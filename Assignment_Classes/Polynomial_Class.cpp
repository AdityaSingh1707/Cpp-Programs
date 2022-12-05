#include<iostream>
using namespace std;

class Term
{
    unsigned int exponent;
    double coefficient;

    public:
        Term();
        Term(unsigned int expo, double coeff);
        Term(const Term &ob);
        Term operator+(const Term &ob);
        Term operator-(const Term &ob);
        Term operator*(const Term &ob);
        bool operator>(const Term &ob);
        bool operator<(const Term &ob);
        bool operator==(const Term &ob);
        bool operator!=(const Term &ob);
        Term& operator=(const Term &ob);
        friend istream& operator>>(istream& in, Term &ob);
        friend ostream& operator<<(ostream& out, const Term &ob);

};

Term::Term()
{
    this->coefficient = 0;
    this->exponent = 0;
}

Term::Term(unsigned int expo, double coeff)
{
    this->coefficient = coeff;
    this->exponent = expo;
}

Term::Term(const Term &ob)
{
    this->coefficient = ob.coefficient;
    this->exponent = ob.exponent;
}

Term Term::operator+(const Term &ob)
{
    if(this->exponent != ob.exponent)
    {
        Term T;
        return T;
    }
    return Term(ob.coefficient + this->coefficient, this->exponent); 
}

Term Term::operator-(const Term &ob)
{
    if(this->exponent != ob.exponent)
    {
        Term T;
        return T;
    }
    return Term(this->coefficient - ob.coefficient, this->exponent); 
}

Term Term::operator*(const Term &ob)
{
    return Term(this->coefficient * ob.coefficient, this->exponent + ob.exponent);
}

bool Term::operator>(const Term &ob)
{
    return (exponent > ob.exponent);
}

bool Term::operator<(const Term &ob)
{
    return (exponent < ob.exponent);
}

bool Term :: operator==(const Term &ob)
{
    return (exponent == ob.exponent && coefficient == ob.coefficient);
}

bool Term :: operator!=(const Term &ob)
{
    return (exponent != ob.exponent || coefficient != ob.coefficient);
}

Term& Term :: operator=(const Term &ob)
{
    exponent = ob.exponent;
    coefficient = ob.coefficient;
    return *(this);
}

istream& operator>>(istream& in, Term &T)
{
    cout << "Enter the coeffecient and exponent: ";
    cin >> T.coefficient >> T.exponent;
    return in;
}

ostream& operator<<(ostream& out, const Term &T)
{
    out << T.coefficient << "x" << T.exponent << endl;
    return out;
}

class Node
{
    Term data;
    Node* next = NULL;
    public:
        Node();
        Node(const Term &T);
        friend class  Term;
        
        friend class Polynomial;
};

Node :: Node()
{
    Term T;
    this->data = T;
}

Node :: Node(const Term& T)
{
    this->data = T;
}

class Polynomial
{
    Node *Head;
    public:
        Polynomial();
        Polynomial(const Polynomial&);
        ~Polynomial();
        void del();
        Polynomial operator+=(Polynomial&);
        Term operator+=(const Term&);
        Polynomial operator+(const Polynomial&);
        Polynomial operator*(const Polynomial&);
        Polynomial operator*(const Term &);
        Polynomial& operator=(const Polynomial&);
        friend ostream& operator<<(ostream &, const Polynomial&);
        friend istream& operator>>(istream &, Polynomial&);
};

Polynomial :: Polynomial()
{
    Head = NULL;
}

Polynomial :: Polynomial(const Polynomial&ob)
{
    if (this->Head != NULL)
    {
        Node *prev = this->Head;
        Node *curr = NULL;
        while (prev != NULL)
        {
            curr = prev->next;
            delete (prev);
            prev = curr;
        }
        this->Head = NULL;
    }
    Node *temp = ob.Head;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        if (this->Head == NULL)
            this->Head = newNode;
        else
        {
            Node *curr2 = this->Head;
            while (curr2->next != NULL)
            {
                curr2 = curr2->next;
            }
            curr2->next = newNode;
        }
        temp = temp->next;
    }

}

void Polynomial::del()
{
    Node *prev = this->Head;
    Node *curr = NULL;
    while (prev != NULL)
    {
        curr = prev->next;
        delete (prev);
        prev = curr;
    }
    this->Head = NULL;
}

Polynomial::~Polynomial()
{
   del();
}

Term Polynomial::operator+=(const Term &ob)
{

    Node *newNode = new Node(ob);
    if (this->Head == NULL)
    {
        this->Head = newNode;
    }
    else
    {
        Node *curr = this->Head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    return ob;
}

Polynomial Polynomial::operator+=(Polynomial &ob)
{
    Polynomial res;
    Node *temp3 = res.Head;
    Node *temp1 = this->Head, *temp2 = ob.Head;
    while(temp1 != 0 && temp2 != 0)
    {
        if(temp1->data > temp2->data)
        {
            res += temp1->data;
            temp1 = temp1->next;
        }
        else if(temp1->data < temp2->data)
        {
            res += temp2->data;
            temp2 = temp2->next;
        }
        else
        {
            Term value = temp1->data + temp2->data;
            res += value;
        }
    }
    while(temp1 != 0)
    {
        res += temp1->data;
        temp1 = temp1->next;
    }
    while(temp2 != 0)
    {
        res += temp2->data;
        temp2 = temp2->next;
    }

    *this = res;
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& ob)
{
    Polynomial res;
    Node *temp3 = res.Head;
    Node *temp1 = this->Head, *temp2 = ob.Head;
    while(temp1 != 0 && temp2 != 0)
    {
        if(temp1->data > temp2->data)
        {
            res += temp1->data;
            temp1 = temp1->next;
        }
        else if(temp1->data < temp2->data)
        {
            res += temp2->data;
            temp2 = temp2->next;
        }
        else
        {
            Term value = temp1->data + temp2->data;
            res += value;
        }
    }
    while(temp1 != 0)
    {
        res += temp1->data;
        temp1 = temp1->next;
    }
    while(temp2 != 0)
    {
        res += temp2->data;
        temp2 = temp2->next;
    }
    return res;
}

Polynomial& Polynomial::operator=(const Polynomial&ob)
{
    if (this->Head != NULL)
    {
        Node *prev = this->Head;
        Node *curr = NULL;
        while (prev != NULL)
        {
            curr = prev->next;
            delete (prev);
            prev = curr;
        }
        this->Head = NULL;
    }
    Node *temp = ob.Head;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        if (this->Head == NULL)
            this->Head = newNode;
        else
        {
            Node *curr2 = this->Head;
            while (curr2->next != NULL)
            {
                curr2 = curr2->next;
            }
            curr2->next = newNode;
        }
        temp = temp->next;
    }
    return *this;
}

Polynomial Polynomial::operator*(const Term &ob)
{
    Polynomial res;
    Node *h1 = this->Head;
    while(h1 != NULL)
    {
        Term pdt = h1->data*ob;
        res += pdt;
        h1 = h1->next;
    }
    return res;
}


Polynomial Polynomial::operator*(const Polynomial &ob)
{
    Polynomial temp, res;
    Node *h1 = this->Head, *h2 = ob.Head, *curr;

    while(h1 != NULL)
    {
        curr = h2;
        while(curr)
        {
            Term pdt = (h1->data*curr->data);
            temp += pdt;
            curr = curr->next;
        }
        res = res + temp;
        temp.del();
        h1 = h1->next;
    }
    return res;
}

istream& operator>>(istream&ob, Polynomial&ob)
{
    int n;
    Term t;
    cout<<"Enter the number of distict terms :";
    in>>n;
    while(n != 0)
    {
        cout<<"Enter the coefficient and exponenet of term :"<<endl;
        in>>t;
        ob += t;
    }
    return in;
}

ostream& operator<<(ostream&ob, const Polynomial&ob)
{
    Node *curr = ob.Head;
    while(curr != NULL)
    {
        out<<curr->t<<" ";
        curr = curr->next;
    }
    return out;
}

int main()
{
    
    return 0;
}
