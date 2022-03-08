/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<iomanip>
using namespace std;

class Student
{
private:
    string name;
    int number;
    int grades;
public:
    Student()
    {
        return;
    }
    void create(string s,int n,int g)
    {
        this->name=s;
        this->number=n;
        this->grades=g;
    }
    float GetAvarage(Student* students,int n)
    {
        float sum=0;
        int nums=0;
        while (nums<n)
        {
            sum+=students[nums].grades;
            cout<<students[nums].name<<" "<<students[nums].number<<" "<<students[nums].grades<<endl;
            nums++;
        }
        return sum/nums;
    }
};

int main()
{
    int N=0;
    cin>>N;
    string name=" ";
    int number=0,grades=0;
    Student *stu=new Student[N];
    for (int i=0;i<N;i++)
    {
        cin>>name>>number>>grades;
        stu[i].create(name,number,grades);
    }
    cout<<fixed<<setprecision(2)<<stu[1].GetAvarage(stu,N);
    // delete stu;
    // stu=NULL;
    // system("pause");
    return 0;
}
