CC = gcc
CFLAGS = -Wl,--rpath=./lib -ltest
TARGET = test_exe
INC = -I./lib
LIB = -L./lib

all = $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(INC) $(LIB) -pg main.c -o $(TARGET) $(CFLAGS) 
	
clean :
	rm -f *.o test_exe
