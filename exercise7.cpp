/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

int main()
{
    int matrix[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin>>matrix[i][j];
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=i;j<3;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    // system("pause");
    return 0;
}