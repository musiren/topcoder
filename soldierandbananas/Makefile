CC = gcc
CFLAGS = -g

OBJS = soldierandbananas
TARGET = soldierandbananas

all :$(TARGET)

clean :
	rm -f soldierandbananas

$(TARGET) : $(OBJS)
	rm -f  soldierandbananas
	$(CC) $(CFLAGS) -o $(OBJS) ./src/main.c
