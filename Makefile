CC = gcc
CFLAGS = -static -Wall -Wextra
TARGET = temperament_test
SRC = temperament_test.c

# Windows cross-compile
CC_WIN = x86_64-w64-mingw32-gcc
TARGET_WIN = temperament_test.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

windows: $(TARGET_WIN)

$(TARGET_WIN): $(SRC)
	$(CC_WIN) $(CFLAGS) -o $(TARGET_WIN) $(SRC)

clean:
	rm -f $(TARGET) $(TARGET_WIN)
