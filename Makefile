CC = gcc
CFLAGS = -Wall -Wextra -Isrc
TARGET = bin/student_app
SRCS = src/main.c src/student.c
OBJS = obj/main.o obj/student.o

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj bin

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
