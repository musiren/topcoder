CC = gcc
CFLAGS = -g

OBJS = soldierandcards
TARGET = soldierandcards

all :$(TARGET)

clean :
	rm -f soldierandcards

$(TARGET) : $(OBJS)
	rm -f  soldierandcards
	$(CC) $(CFLAGS) -o $(OBJS) ./src/main.c
