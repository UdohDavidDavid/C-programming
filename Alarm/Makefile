# Makefile for alarm.c
CC = gcc
CFLAGS = $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_mixer
TARGET = alarm
SRC = alarm.c
PARAM = 00:00:03

all: $(TARGET)

# Build the program
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Run the program
run: $(TARGET)
	./$(TARGET) $(PARAM)
