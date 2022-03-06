/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

void AscendingOrder(int &a,int &b,int &c)
{
    int temp;
    if (a>b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    if (b>c)
    {
        temp=b;
        b=c;
        c=temp;
    }
    if (a>b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    // cout<<a<<b<<c<<endl;
}

int main()
{
    int first=0,
        second=0,
        third=0;
    cin>>first>>second>>third;
    AscendingOrder(first,second,third);
    cout<<first<<" "<<second<<" "<<third<<endl;
    // system("pause");
    return 0;
}