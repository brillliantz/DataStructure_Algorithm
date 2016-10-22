#include "ch3.0_polynomial.h"
#include <iostream>

int main() {
    Polynomial poly1 = Polynomial{};

    std::cout << "is empty: "<< poly1.empty() << std::endl;
    poly1.print();
    poly1.insert(1, 1);
    std::cout << "is empty: "<< poly1.empty() << std::endl;
    poly1.print();

    for (int i = 2; i < 10; ++i) {
        poly1.insert(2*i+1.3, i);
    }
    poly1.print();
}
