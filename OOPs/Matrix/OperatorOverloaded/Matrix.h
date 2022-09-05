#include<iostream>
using namespace std;

class Matrix
{
    int **arr;
    int row_size;
    int column_size;

    public :
        Matrix();
        Matrix(int row_size, int column_size);
        Matrix operator+(Matrix temp);
        Matrix operator-(Matrix temp);
        friend istream& operator>>(istream &in, const Matrix &ob);
        friend ostream& operator<<(ostream &out, const Matrix &ob);
};
