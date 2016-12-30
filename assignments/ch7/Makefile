CC = g++
CFLAGS = -std=c++11 -c
LFLAGS = -Wall
OBJS = ch7_heapsort_test.o
TARGET = ch7_heapsort_test.out

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

ch7.0_heapsort_test.o: ch7_heapsort.hpp ch7_heapsort_test.cpp
	$(CC) $(CFLAGS) ch7_heapsort_test.cpp

clean:
	rm *.o $(TARGET)
