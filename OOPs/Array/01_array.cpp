#include "array.h"

// Array:: is used as the class name under which following functions are defined. 

Array::Array(int size) // Parameterized Constructor
{
    arr = new int[size];
    this->size = size; //this pointer is used to point to the variable that is defined under the class
                        // (to access a variable from class.)
}

Array::Array()  // Default Constructor 
{
    size = 5;
    arr = new int[size];
}

void Array::take_input()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << "Enter the value at " << i << "th Position: ";
        cin >> arr[i];
    }
}

void Array::display()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << arr[i] << " ";
    }
}


Array Array::add(Array temp)
{
    Array res(this->size);

    for (int i = 0; i < temp.size; i++)
    {
        res.arr[i] = this->arr[i] + temp.arr[i];
    }

    return res;
}

void access_class_member(Array ob)
{
    cout<<"Size of array :  "<<ob.size<<endl;
}
