CC = g++
CFLAGS = -std=c++11 -c
LFLAGS = -Wall
OBJS = ch3.0_polynomial.o ch3.0_polynomial_test.o
TARGET = test_poly.out

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

ch3.0_polynomial.o: ch3.0_polynomial.h ch3.0_polynomial.cpp
	$(CC) $(CFLAGS) ch3.0_polynomial.cpp

ch3.0_polynomial_test.o: ch3.0_polynomial.h ch3.0_polynomial_test.cpp
	$(CC) $(CFLAGS) ch3.0_polynomial_test.cpp

clean:
	rm *.o $(TARGET)
