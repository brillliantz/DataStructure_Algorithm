CC = g++
CFLAGS = -std=c++11 -c
LFLAGS = -Wall
OBJS = adt_linkedlist_test.o
TARGET = adt_linkedlist_test.out

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

adt_linkedlist_test.o: adt_linkedlist.cpp adt_linkedlist.h adt_linkedlist_test.cpp
	$(CC) $(CFLAGS) adt_linkedlist_test.cpp

clean:
	rm *.o $(TARGET)
