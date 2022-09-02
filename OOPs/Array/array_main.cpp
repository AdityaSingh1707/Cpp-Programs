#include "array.h"

int main()
{
    int size_array;

    cout << "Give the size of Array: ";
    cin >> size_array;

    Array a1(size_array); // a1 , a2, res are called objects.
    Array a2(size_array);
    Array res(size_array);

    a1.take_input();
    cout << "A1 INPUT OVER" << endl;
    a2.take_input();
    cout << "A2 INTPUT OVER" << endl;

    res = a1.add(a2);

    res.display();

    return 0;
}
