#include <iostream>
using namespace std;


class Array
{
    int* arr;
    int size;

    public:
        Array(); // Default Constructor.
        Array(int size); // Parameterized Constructor.
        void take_input();
        void display();
        Array add(Array temp);
};
