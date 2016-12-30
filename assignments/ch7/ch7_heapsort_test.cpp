#include <iostream>
#include <vector>
#include "ch7_heapsort.hpp"

template <typename T>
void print_vector(std::vector<T> v) {
    for (auto &i : v) {
        std::cout << i << ',';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v1{ 142, 543, 123, 65, 453, 808, 572, 434, 111, 242, 811, 102};
    std::vector<int> v2 = v1;
    std::vector<int> v3 = v1;
    std::vector<int> v4 = v1;
    std::cout << "\nUnsorted list: " << std::endl;
    print_vector(v1);

    heap_sort( v1, 0, v1.size() - 1 );
    heap_sort( v2, 4, 9 );
    heap_sort( v3, 11, 11 );
    heap_sort( v3, 0, 1 );

    std::cout << "\nVarious sorted lists: " << std::endl;
    print_vector(v1);
    print_vector(v2);
    print_vector(v3);
    print_vector(v4);

    return 0;
}

