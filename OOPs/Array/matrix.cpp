#include"matrix.h"

Matrix::Matrix() // Default Constructor will always construct a matrix of order 3x3 
{
    this->column_size = this->row_size = 3;
    this->array = new int*[row_size];
    for(int i = 0; i < row_size; i++)
    {
        this->array[i] = new int[column_size];
    }
    this->column_size = column_size;
    this->row_size = row_size;
}

Matrix::Matrix(int row_size, int column_size)
{
    array = new int*[row_size];
    for(int i = 0; i < row_size; i++)
    {
        array[i] = new int[column_size];
    }
    this->column_size = column_size;
    this->row_size = row_size;
}

void Matrix:: get_input()
{
    for(int i = 0; i < row_size; i++)
    {
        for(int j = 0; j < column_size; j++)
        {
            cout<<"Enter the value of element at "<<i<<","<<j<<" position :  ";
            cin>>array[i][j]; 
        }
    }
}

void Matrix::display()
{
    for(int i = 0; i < row_size; i++)
    {
        for(int j = 0; j < column_size; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

Matrix Matrix::add_two_matrices(Matrix temp)
{
    Matrix res(row_size, column_size);
    for(int i = 0; i < row_size; i++)
    {
        for(int j = 0; j < column_size; j++)
        {
            res.array[i][j] = this->array[i][j] + temp.array[i][j];
        }
    }
    return res;
}
