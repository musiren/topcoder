CC = gcc
CFLAGS = -g

OBJS = kiwijuice
TARGET = kiwijuice

all :$(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJS) ./src/main.c ../log/log.h ../log/log.c
