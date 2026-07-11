# Dont make this file in linux after download because its just a test someone copy this file without read this makefile 


CC = gcc
CFLAGS = -Wall
TARGET = -r-

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

# 
clean:
	@echo "Cleaning up build artifacts..."
	rm -rf *.o $(TARGET)

  # its not working if you see plaes do this working
