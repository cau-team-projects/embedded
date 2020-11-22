CC = aarch64-linux-gnu-gcc

CFLAGS =
LDFLAGS = -static

default: buzzertest

lcdtest: buzzertest.o
	$(CC) $(LDFLAGS) -o buzzertest buzzertest.o

lcdtest.o: buzzertest.c
	$(CC) $(CFLAGS) -o buzzertest.o -c buzzertest.c

clean:
	rm buzzertest.o buzzertest
