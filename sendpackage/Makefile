CC = gcc
CFLAGS = -g

OBJS = sendpackage
TARGET = sendpackage

all :$(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJS) ./src/main.c ../log/log.h ../log/log.c
