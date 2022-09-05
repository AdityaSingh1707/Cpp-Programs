#include"Array.h"

Array::Array()
{
    this->size = 5;
    this->arr = new int[this->size];
}

Array::Array(int size)
{
    this->size = size;
    this->arr = new int[this->size];
}

Array Array::operator+(Array temp)
{
    Array res(this->size);

    for(int i = 0; i < this->size; i++)
    {
        res.arr[i] = this->arr[i] + temp.arr[i];
    }

    return res;
}

Array Array::operator-(Array temp)
{
    Array res(this->size);

    for(int i = 0; i < this->size; i++)
    {
        res.arr[i] = this->arr[i] - temp.arr[i];
    }

    return res;
}

ostream& operator<<(ostream &out, const Array &ob)
{
    out<<"Displaying the elements of the array : "<<endl;

    for(int i = 0; i < ob.size; i++)
    {
        out<<ob.arr[i]<<" ";
    }
    out<<endl;

    return out;
}

istream& operator>>(istream &in, const Array &ob)
{

    for(int i = 0; i < ob.size; i++)
    {
        in>>ob.arr[i];
    }

    return in;
}
