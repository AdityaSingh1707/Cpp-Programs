#include"matrix.h"

int main()
{
    int row_size, column_size;

    cout<<"Enter the number of rows and columns of the Matrix :  ";
    cin>>row_size>>column_size;

    Matrix m1(row_size, column_size);
    cout<<"Please provide input for Matrix m1 : \n"; 
    m1.get_input();
    cout<<"\nInput for matrix m1 taken Succesfully!\n";
    cout<<"\nDisplaying Matrix m1 :\n";
    m1.display();

    Matrix m2(row_size, column_size);
    cout<<"Please provide input for Matrix m2 : \n"; 
    m2.get_input();
    cout<<"\nInput for matrix m2 taken Succesfully!\n";
    cout<<"\nDisplaying Matrix m2 :\n";
    m2.display();

    Matrix res(row_size, column_size);
    res = m1.add_two_matrices(m2);
    cout<<"Resultant Matrix :\n";
    res.display();
    return 0;
}
