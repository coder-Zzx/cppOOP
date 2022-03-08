/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

int main()
{
    int length=0,
        sum=0;
    cin>>length;
    int** int_array=new int*[length]();
    for (int i=0;i<length;i++)
    {
        int *p=new int;
        cin>>*p;
        int_array[i]=p;
    }
    for (int i=0;i<length;i++)
    {
        sum+=*int_array[i];
    }
    cout<<sum<<endl;
    delete int_array;
    // system("pause");
    return 0;
}
