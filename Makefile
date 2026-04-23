CC := gcc
CFLAGS := -Wall -Wextra -Werror
PREFIX ?= /usr/local
BINDIR := $(PREFIX)/bin
TARGET := ccd

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f ccd

install:
	install -d $(PREFIX)
	install -m 755 $(TARGET) $(BINDIR)/$(TARGET)
	
uninstall:
	rm -f $(PREFIX)/$(TARGET)

.PHONY: clean install uninstall
