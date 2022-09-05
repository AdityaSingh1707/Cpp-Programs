#include"Array.h"

int main()
{
    int size;

    cout<<"Enter the size of the array :\n";
    cin>>size;

    Array a1(size), a2(size), res1(size), res2(size);

    cout<<"Enter the elements of the array a1 : "<<endl;
    cin >> a1;

    cout<<"Enter the elements of the array a2 : "<<endl;
    cin >> a2;

    cout<<a1<<a2;

    res1 = a1 + a2;

    cout<<res1;

    res2 = a1 - a2;

    cout<<res2;

    return 0;
}
