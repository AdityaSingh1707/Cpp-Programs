#include"Matrix.h"

Matrix::Matrix()
{
    this->row_size = this->column_size = 3;
    this->arr = new int*[row_size];
    for(int i = 0; i < row_size; i++)
    {
        this->arr[i] = new int[column_size];
    }
}

Matrix::Matrix(int row_size, int column_size)
{
    this->column_size = column_size;
    this->row_size = row_size;
    this->arr = new int*[this->row_size];
    for(int i = 0; i < this->row_size; i++)
    {
        this->arr[i] = new int[this->column_size];
    }
    
}

Matrix Matrix::operator+(Matrix temp)
{
    Matrix res(this->row_size, this->column_size);
    for(int i = 0; i < this->row_size; i++)
    {
        for(int j = 0; j < this->column_size; j++)
        {
            res.arr[i][j] = this->arr[i][j] + temp.arr[i][j]; 
        }
    }
    return res;
}

Matrix Matrix::operator-(Matrix temp)
{
    Matrix res(this->row_size, this->column_size);
    for(int i = 0; i < this->row_size; i++)
    {
        for(int j = 0; j < this->column_size; j++)
        {
            res.arr[i][j] = this->arr[i][j] - temp.arr[i][j]; 
        }
    }
    return res;
}

istream& operator>>(istream &in, const Matrix &ob)
{
    for(int i = 0; i < ob.row_size; i++)
    {
        for(int j = 0; j < ob.column_size; j++)
        {
            in>>ob.arr[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream &out, const Matrix &ob)
{
    // out<<"Displaying the elements of the Matrix :\n";

    for(int i = 0; i < ob.row_size; i++)
    {
        for(int j = 0; j < ob.column_size; j++)
        {
            out<<ob.arr[i][j]<<" ";
        }
        out<<endl;
    }

    return out;
}
