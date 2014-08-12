CC = gcc
CFLAGS = -g -Wall

OBJS = interestingparty
SRCS = ./src/main.c
TARGET = interestingparty

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(OBJS) $(SRCS)

clean :
	rm $(OBJS)
