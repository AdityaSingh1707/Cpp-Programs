#include<iostream>
#include<string>
using namespace std;
class String
{
    char * str;
    int length;
    public:
        String();
        String(int size);
        String(char * s);
        ~String();
        String(const String &ob);
        char& operator[](int i);
        String operator+(const String& ob) const;
        String operator+=(const String& s) const;
        friend bool operator==(String &s1,String &s2);
        friend bool operator>(String &s1,String &s2);
        friend bool operator<(String &s1,String &s2);
        string convert() const;
        char* convert_arr();
        friend bool compare(String &s1,string &s2);
};
