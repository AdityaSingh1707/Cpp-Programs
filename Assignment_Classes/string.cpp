#include "string.h"

String::String()
{
    this->str=NULL;
    this->length=0;
}
String::String(int size)
{
    this->str=new char[size];
    this->length=size;
}
String::~String()
{
    delete str;

}
String::String(char * s)
{
    this->str=s;
    int count=0;
    for(int i=0;s[i]!='\0';++i)
        count++;
    this->length=count;

}
char& String::operator[](int i)
{
    return str[i];
    
}
String::String(const String &ob)
{
    str=new char[ob.length];
    for(int i=0;str[i]!='\0';++i)
        str[i]=ob.str[i];
    

}
String String::operator+(const String& ob) const
{
    String concate;
    int size=this->length+ob.length;
    for(int i=0;i<this->length;++i)
        concate.str[i]=this->str[i];
    for(int j=0;j<ob.length;++j)
        concate.str[j]=ob.str[j];
    return concate;
}
String String::operator+=(const String& s) const
{
    int size=this->length+s.length;
    for(int i=0;i<this->length;++i)
        this->str[i]=this->str[i];
    for(int j=0;j<s.length;++j)
        this->str[j]=s.str[j];
    return *this;
}
bool operator==(String &s1,String &s2)
{
    int flag=0;
    if(s1.length!=s2.length)
        return false;
    else
    {
        for(int i=0;s1.str[i]!='\0';++i)
        {
            if(s1.str[i]==s2.str[i+1])
                flag=1;
            else{
                flag=0;
                break;
            }

        }
    }
    if(flag==0)
        return false;
    else
        return true;
}
string String::convert() const
{
    string new_str(this->str);
    return new_str;
}
bool compare(String &s1,string &s2)
{
    int flag=0;
    string s=s1.convert();
    if(s.length()!=s2.length())
        return false;
    else
    {
        for(int i=0;s1.str[i]!='\0';++i)
        {
            if(s[i]==s2[i+1])
                flag=1;
            else{
                flag=0;
                break;
            }

        }
    }
    if(flag==0)
        return false;
    else
        return true;
    
}
char * String::convert_arr()
{
    string new_str(this->str);
    char * ret=new_str.c_str();
    return ret;
}



