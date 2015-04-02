CC = gcc
CFLAGS = -g -Wall -o
LOG_DIR = ./log
LOG_HEADER = ./log/log.h
LOG_SOURCE = ./log/log.c

TARGET = topcoder

all : $(TARGET)

$(TARGET) :
	$(CC) $(CFLAGS) kiwi-juice ./kiwijuice/src/main.c -I$(LOG_DIR) $(LOG_HEADER) $(LOG_SOURCE)
	$(CC) $(CFLAGS) interesting-party ./interestingparty/src/main.c -I$(LOG_DIR) $(LOG_HEADER) $(LOG_SOURCE)
	$(CC) $(CFLAGS) encrypt ./cryptography/src/main.c -I$(LOG_DIR) $(LOG_HEADER) $(LOG_SOURCE)
	$(CC) $(CFLAGS) interesting-digits ./interestingdigits/src/main.c -I$(LOG_DIR) $(LOG_HEADER) $(LOG_SOURCE)
	$(CC) $(CFLAGS) send-package ./sendpackage/src/main.c -I$(LOG_DIR) $(LOG_HEADER) $(LOG_SOURCE)

clean :
	rm -f kiwi-juice
	rm -f interesting-party
	rm -f encrypt
	rm -f interesting-digits
	rm -f send-package

install : $(TARGET)
	mkdir -p $(prefix)
	mv kiwi-juice $(prefix)
	mv interesting-party $(prefix)
	mv encrypt $(prefix)
	mv interesting-digits $(prefix)
	mv send-package $(prefix)
