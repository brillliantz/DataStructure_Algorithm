CC = g++
CFLAGS = -std=c++11
# LFLAGS = -Wall
# OBJS = 
# TARGET =

all: ch3.0_josephus.out ch3.0_josephus_STL.out ch3.0_1-4_noSTL_test.out ch3.0_2-3_test.out

ch3.0_josephus.out: ch3.0_josephus.cpp
	$(CC) $(CFLAGS) ch3.0_josephus.cpp -o ch3.0_josephus.out

ch3.0_josephus_STL.out: ch3.0_josephus_STL.cpp
	$(CC) $(CFLAGS) ch3.0_josephus_STL.cpp -o ch3.0_josephus_STL.out

ch3.0_1-4_noSTL_test.out: ch3.0_1-4_noSTL_test.cpp ./utils/adt_linkedlist.h ./utils/adt_linkedlist.cpp ch3.0_1_singly.cpp ch3.0_1_doubly.cpp ch3.0_4.cpp ch3.0_2_noSTL.cpp ch3.0_3_noSTL.cpp
	$(CC) $(CFLAGS) ch3.0_1-4_noSTL_test.cpp ./utils/adt_linkedlist.cpp -o ch3.0_1-4_noSTL_test.out

ch3.0_2-3_test.out: ch3.0_2.cpp ch3.0_3.cpp ch3.0_2-3_test.cpp
	$(CC) $(CFLAGS) ch3.0_2-3_test.cpp -o ch3.0_2-3_test.out

clean:
	rm *.out
