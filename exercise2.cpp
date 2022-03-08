/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

class Rectangle
{
private:
    int coordinate[2][2];
public:
    Rectangle()
    {
        for (int i=0;i<2;i++)
        {
            for (int j=0;j<2;j++)
            {
                cin>>this->coordinate[i][j];
            }
        }
        cout<<((this->coordinate[1][0]-this->coordinate[0][0])+(this->coordinate[1][1]-this->coordinate[0][1]))*2<<endl;
        cout<<(this->coordinate[1][0]-this->coordinate[0][0])*(this->coordinate[1][1]-this->coordinate[0][1])<<endl;
    }
};

int main()
{
    Rectangle *rec=new Rectangle();
    delete res;
    rec=NULL;
    // system("pause");
    return 0;
}