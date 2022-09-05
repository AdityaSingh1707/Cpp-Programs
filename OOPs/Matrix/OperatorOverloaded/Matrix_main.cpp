#include"Matrix.h"

int main()
{
    int row, column;

    cout<<"Enter the number of rows and columns are :\n";
    cin>>row>>column;

    Matrix m1(row, column), m2(row, column), res1(row, column), res2(row, column);

    cout<<"Enter the elements of the Matrix m1 :\n";
    cin >> m1;
    cout<<"Enter the elements of the Matrix m2 :\n";
    cin >> m2;

    cout<<"Displaying the elements of the Matrix m1 :\n";
    cout << m1;
    cout<<"Displaying the elements of the Matrix m2 :\n";
    cout << m2;

    res1 = m1 + m2;
    cout<<"Displaying the elements of the Matrix res (After Addition : (m1 + m2)) :\n";
    cout << res1;

    res2 = m1 - m2;
    cout<<"Displaying the elements of the Matrix res (After Substraction : (m1 - m2)) :\n";
    cout << res2;
    
    return 0;
}
