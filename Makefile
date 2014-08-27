CC = gcc
CFLAGS = -g -Wall

TARGET = topcoder

all : $(TARGET)

$(TARGET) :
	$(CC) $(CFLAGS) -o kiwi-juice ./kiwijuice/src/main.c
	$(CC) $(CFLAGS) -o interesting-party ./interestingparty/src/main.c
	$(CC) $(CFLAGS) -o encrypt ./cryptography/src/main.c

clean :
	rm -f kiwi-juice
	rm -f interesting-party
	rm -f encrypt

install : $(TARGET)
	mkdir -p $(prefix)
	mv kiwi-juice $(prefix)
	mv interesting-party $(prefix)
	mv encrypt $(prefix)
