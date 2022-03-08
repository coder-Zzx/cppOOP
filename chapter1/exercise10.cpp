/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

int main()
{
    int int_array[100];
    int a=0,
        length=0,
        index=0;
    while (cin>>a)
    {
        if (a==-1)
        {
            break;
        }
        int_array[length++]=a;
    }
    int result[length];
    for (int k=0;k<length;k++)
    {
        if (int_array[k]!=0)
        {
            result[index++]=int_array[k];
        }
    }
    for (int m=index;m<length;m++)
    {
        result[m]=0;
    }
    for (int m=0;m<length;m++)
    {
        cout<<result[m]<<" ";
    }
    // system("pause");
    return 0;
}