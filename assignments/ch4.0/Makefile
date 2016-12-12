CC = g++
CFLAGS = -std=c++11 -c
LFLAGS = -Wall
OBJS = ch4.0_test.o
TARGET = ch4.0_test

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

ch4.0_BinaryTree.o: ch4.0_BinaryTree.h
	$(CC) $(CFLAGS) ch4.0_BinaryTree.h

ch4.0_postFix2Tree.o: ch4.0_BinaryTree.h ch4.0_postFix2Tree.cpp
	$(CC) $(CFLAGS) ch4.0_postFix2Tree.cpp

ch4.0_test.o: ch4.0_BinaryTree.h ch4.0_test.cpp
	$(CC) $(CFLAGS) ch4.0_test.cpp

clean:
	rm *.o $(TARGET)
