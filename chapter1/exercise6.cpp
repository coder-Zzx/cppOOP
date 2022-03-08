/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<cstring>
#define MIN(x,y) x<y?x:y
using namespace std;

void MyStrCmp(char p[],char q[])
{
    int i=0;
    do
    {
        i++;
    } while (*(p+i)==*(q+i));
    int flag=*(p+i)<*(q+i)?0:1;
    if (flag)
    {
        cout<<p<<endl;
    }
    else
    {
        cout<<q<<endl;
    }
}

int main()
{
    char str_1[100],str_2[100];
    cin>>str_1>>str_2;
    MyStrCmp(str_1,str_2);
    // system("pause");
    return 0;
}
