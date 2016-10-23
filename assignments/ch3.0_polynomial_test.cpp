#include "ch3.0_polynomial.h"
#include <iostream>

int main() {
    Polynomial poly1 = Polynomial{};

    std::cout << "\nis it empty? "<< poly1.empty() << std::endl;
    poly1.print();
    std::cout << "\nNow insert one term x into the polynomial" << std::endl;
    poly1.insert(1, 1);
    std::cout << "\nis it empty? "<< poly1.empty() << std::endl;
    poly1.print();

    std::cout << "\nNow insert some terms into the polynomial." << std::endl;
    for (int i = 2; i < 10; ++i) {
        poly1.insert(2*i+1.3, i);
    }
    poly1.print();

    std::cout << "\nNow insert 1.35*x^5 - 3*x^4 - 15.3*x^7" << std::endl;
    poly1.insert(1.35, 5);
    poly1.insert(-3, 4);
    poly1.insert(-15.3, 7);
    poly1.print();

    Polynomial poly2 = Polynomial{};
    for (int i = 2; i < 10; ++i) {
        poly2.insert(2*i+1.1, 2*i);
    }
    poly2.insert(-19.3, 9);
    poly2.print();

    std::cout << "\nNow test function add" << std::endl;
    Polynomial *sum = poly1.add(&poly2);
    sum->print();
}
