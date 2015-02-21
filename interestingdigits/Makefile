CC = gcc
CFLAGS = -g -Wall

OBJS = interestingdigits
SRCS = ./src/main.c
TARGET = interestingdigits

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
