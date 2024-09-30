CC = gcc
CFLAGS = -static -Wall -Wextra
TARGET = temperament_test
SRC = temperament_test.c

# Windows
CC_WIN = x86_64-mingw-w64-mingw32-gcc
TARGET_WIN = temperament_test.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

windows: $(TARGET_WIN)
	$(CC_WIN) $(CFLAGS) -o $(TARGET_WIN) %(SRC)

clean:
	rm -f $(TARGET)
