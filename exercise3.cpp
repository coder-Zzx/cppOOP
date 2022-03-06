/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

int main()
{
    char* const name=new char[4]{'a','b','c'};
    *name='z';
    cout<<name<<endl;
    delete name;
    // system("pause");
    return 0;
}