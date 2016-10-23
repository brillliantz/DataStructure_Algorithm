const double COEF_PRECISION = 1E-8;


class Polynomial {
    private:
        struct Term
        {
            int exp;
            double coef;
            Term *next;
            Term *prev;
            Term(const double c, const int e, Term *n = nullptr, Term* p = nullptr);
        };

    private:
        Term *head;
        Term *tail;
        int length;

    public:
        Polynomial();
        void zero();

        bool empty() const {return (length == 0);}

        Term *begin() const {return head->next;}
        Term *end() const {return tail;}

        void insert(const double &c, const int &e);

        Polynomial *add(Polynomial *rhs);
        //Polynomial &operator+(Polynomial &rhs);
        //Polynomial &operator+(Polynomial &&rhs);
        //Polynomial &operator*(Polynomial &rhs);
        //Polynomial &operator*(Polynomial &&rhs);

        void print() const;

    private:
        //Term *InsertAt(Term *pos, Term &x);
        Term *EraseAt(Term *pos);
};

//Polynomial *add(Polynomial *lhs, Polynomial *rhs);
