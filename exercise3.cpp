/*������Ҫ�������������!!!
 *������Ҫ�������������!!!
 *������Ҫ�������������!!!*/
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