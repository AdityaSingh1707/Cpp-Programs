#include<iostream>
using namespace std;

class Array
{
    int *arr;
    int size;

    public :
        Array();
        Array(int size);
        Array operator+(Array temp);
        Array operator-(Array temp);
        friend istream& operator>>(istream &in, const Array &ob);
        friend ostream& operator<<(ostream &out, const Array &ob);
};
