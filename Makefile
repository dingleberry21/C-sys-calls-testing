CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99

SOURCES = main.c
TARGET = test

OBJECTS = $(SOURCES:.c=.o)

INCLUDE_DIRS = 
INCLUDES = $(addprefix -I,$(INCLUDE_DIRS))

LIBS = 
LDFLAGS = $(addprefix -l,$(LIBS))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild