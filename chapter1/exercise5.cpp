/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

void BubbleSort(int array[])
{
    for (int i=9;i>=0;i--)
    {
        int flag=0;
        for (int j=0;j<i;j++)
        {
            if (*(array+j)>*(array+j+1))
            {
                int temp=*(array+j);
                *(array+j)=*(array+j+1);
                *(array+j+1)=temp;
                flag=1;
            }
        }
        if (flag==0)
        {
            break;
        }
    }
}

int main()
{
    int int_array[10];
    int input=0,
        length=0;
    while (cin>>input)
    {
        *(int_array+length)=input;
        length++;
    }
    BubbleSort(int_array);
    for (int i=0;i<10;i++)
    {
        cout<<int_array[i]<<" ";
    }
    // system("pause");
    return 0;
}
