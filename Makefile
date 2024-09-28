CC = gcc
CFLAGS = -static -Wall -Wextra
TARGET = temperament_test
SRC = temperament_test.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
