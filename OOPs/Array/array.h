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

// public is used to keep the functions/variables that declared under it are public 
// (so that they can be used everywhere).
// Variables and Functions those are not under public are private and limited to the class.. 
