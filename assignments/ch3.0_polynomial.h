class Term
{
  public:
    int exp;
    double coef;
    Term *next;
    Term *prev;
    Term(const double &c, const int &e, Term *n = nullptr, Term* p = nullptr);
};

class Polynomial {
    private:
        Term *head;
        Term *tail;
        int length;

    private:
        void push_front(const double &c, const int &e);
        bool empty() const;
    public:
        Polynomial();
        void insert(const double &c, const int &e);
        void zero();
        Term *begin() const;
        Term *end() const;
        Polynomial *operator+(Polynomial &rhs);
        Polynomial *operator*(Polynomial &rhs);
        void print() const;
};
