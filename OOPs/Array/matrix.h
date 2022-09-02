#include<iostream>
using namespace std;

class Matrix
{
    int **array;
    int row_size;
    int column_size;

    public :
        Matrix();
        Matrix(int row_size, int column_size);
        void get_input();
        void display();
        Matrix add_two_matrices(Matrix temp);
};
