#include "ch3.0_polynomial.h"
#include <iostream>
#include <cmath>

Polynomial::Term::Term(const double c, const int e,
        Term *n /*= nullptr*/, Term *p /*= nullptr*/) :
    exp{e}, coef{c}, next{n}, prev{p}
{}

Polynomial::Polynomial() : length{0}
{
    head = new Term(0, 0);
    tail = new Term(0, 0);
    head->next = tail;
    tail->prev = head;
}

void Polynomial::zero() {
    ;
}

void Polynomial::insert(const double &c, const int &e) {
    if (empty()) {
        Term *pos = end();
        pos->prev = pos->prev->next = new Term(c, e, pos, pos->prev);
        ++length;
    }
    else {
        for (Term *t = begin(); t != end(); t = t->next) {
            if (e > t->exp) {
                t->prev = t->prev->next = new Term(c, e, t, t->prev);
                ++length;
                break;
            }
            else if (e == t->exp) {
                if (fabs(c + t->coef) < COEF_PRECISION) {
                    EraseAt(t);
                }
                else {
                    t->coef += c;
                }
                break;
            }
        }
    }
}

//Polynomial::Term *Polynomial::InsertAt(Term *pos, Term &x) {
//    x.next = pos;
//    x.prev = pos->prev;
//    pos->prev = pos->prev->next = &x;
//    ++length;
//    std::cout << pos << ", " << pos->prev << ", " << pos->next << ", "
//        << &x << ", " << x.next << std::endl; //TODO
//    return &x;
//}

Polynomial::Term *Polynomial::EraseAt(Term *pos) {
    Term* t = pos->next;
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    --length;
    return t;
}
Polynomial *Polynomial::operator+(Polynomial &rhs) {
    for (Term *pl = this->head; pl; pl = pl->next) {
        for (Term *pr = rhs.head; pr; pr = pr->next) {
            if (pr->exp < pl->exp) {
                break;
            }
            else if (pr->exp == pl->exp) {

            }
            rhs.head = pr;
        }
        rhs.head = nullptr;
        rhs.tail = nullptr;
        rhs.length = 0;
    }
}

Polynomial &Polynomial::operator*(Polynomial &rhs) {
    ;
}

void Polynomial::print() const {
    std::cout << "[Printing the polynomial:]" << std::endl;
//    check whether the address is correct:
//    std::cout << "===" << head << ", " << head->next << ", "
//        << begin() << ", " << head->next->next << ", " << end() << std::endl;
    if (empty()) std::cout << "It is empty now." << std::endl;
    else {
        Term *t = begin();
        while (t->next != end()) {
            std::cout << t->coef << "x^" << t->exp << " + ";
            t = t->next;
        }
        std::cout << t->coef << "x^" << t->exp << std::endl;
    }
}
