/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<cstring>
using namespace std;

char null='a';

class String
{
private:
    char* array;
public:
    friend ostream &operator<<(ostream&,String&);
    String(const char* p)
    {
        this->array=new char[strlen(p)+1];
        strcpy(this->array,p);
    }
    ~String()
    {
        delete this->array;
    }
    char& operator[](int n)
    {
        if (n>=strlen(this->array))
        {
            cout<<"Index out of range."<<endl;
            return null;
        }
        else
        {
            return *(this->array+n);
        }
    }
    String& operator+(const String &a)
    {
        char* new_array=new char[strlen(this->array)+1];
        strcpy(new_array,this->array);
        this->array=new char[strlen(new_array)+strlen(a.array)+1];
        strcpy(this->array,new_array);
        strcat(this->array,a.array);
        return *this;
    }
    string operator+(const char a[])
    {
        char* new_str=new char[this->getLength()+strlen(a)+1];
        strcpy(new_str,this->getArray());
        strcat(new_str,a);
        string str(new_str);
        return str;
    }
    operator int()
    {
        return this->getLength();
    }
    char* getArray()
    {
        return this->array;
    }
    int getLength()
    {
        return strlen(this->array);
    }
};

ostream& operator<<(ostream& co,String &s)
{

    for (int i=0;i<strlen(s.getArray());i++)
    {
        co<<*(s.getArray()+i);
    }
    return co;
}

int main()
{
    String string1("mystring"),string2("yourstring"),string3("herstring");
    cout<<string1<<endl;
    string1[7]='n';
    cout<<string1<<endl;
    string1[8]='n';
    cout<<string1+string2+string3<<endl;
    cout<<string1<<endl;
    cout<<string2+"ab"<<endl;
    cout<<string2<<endl;
    cout<<string3+3<<endl;
    cout<<string3<<endl;
    return 0;
}
