CC = gcc
CFLAGS = -g -Wall

TARGET = topcoder

all : $(TARGET)

$(TARGET) :
	$(CC) $(CFLAGS) -o0 kiwi-juice ./kiwijuice/src/main.c
	$(CC) $(CFLAGS) -o0 interesting-party ./interestingparty/src/main.c

clean :
	rm -f kiwi-juice
	rm -f interesting-party

install : $(TARGET)
	mkdir -p $(prefix)
	mv kiwi-juice $(prefix)
	mv interesting-party $(prefix)
