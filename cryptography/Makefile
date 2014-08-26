CC = gcc
CFLAGS = -g -Wall

OBJS = cryptography
SRCS = ./src/main.c
TARGET = cryptography

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
