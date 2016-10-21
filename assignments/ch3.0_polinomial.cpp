#include "ch3.0_polynomial.h"
#include <iostream>

Term::Term(const double &c, const int &e,
        Term *n /*= nullptr*/, Term *p /*= nullptr*/) :
    exp{e}, coef{c}, next{n}, prev{p}
{}

Polynomial::Polynomial() :
    length{0}
{
    head = new Term(0, 0);
    tail = new Term(0, 0);
    head->next = tail;
    tail->prev = head;
}

bool Polynomial::empty() const {
    return (length == 0);
}

Term *Polynomial::begin() const {
    return head->next;
}

Term *Polynomial::end() const {
    return tail;
}

void Polynomial::push_front(const double &c, const int &e) {
    if (this->empty()) {
        Term *term = new Term(c, e);
        this->head = term;
        this->tail = term;
    }
    else {
        Term *term = new Term(c, e);
        term->next = this->head->next;
        this->head = term;
    }
}
void Polynomial::insert(const double &c, const int &e) {
    for (Term *t = begin(); t != end(); t = t->next) {
        if (e > t->exp) {
            this->push_front(c, e);
        }
        else if (e == p->exp) {
            if (abs(c - p->coef) < 1E-8)
        }
    }
}

void Polynomial::zero() {
    ;
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

Polynomial *Polynomial::operator*(const Polynomial &rhs) {
    ;
}

void Polynomial::print() const {
    for (Term *p = head; p; p = p->next) {
        std::cout << p->coef << "x^" << p->exp << " + ";
    }
    std::cout << std::endl;
}
