/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
    friend class Time;
public:
    Date()
    {
        cin>>this->year>>this->month>>this->day;
    }
};

class Time
{
private:
    int hour;
    int min;
    int sec;
public:
    Date *MyDate=new Date();
    Time()
    {
        cin>>this->hour>>this->min>>this->sec;
    }
    ~Time()
    {
        this->display();
        delete MyDate;
        MyDate=NULL;
    }
    void display()
    {
        cout<<MyDate->year<<"/"<<MyDate->month<<"/"<<MyDate->day<<endl;
        cout<<this->hour<<":"<<this->min<<":"<<this->sec<<endl;
    }
};




int main()
{
    Time *time=new Time();
    delete time;
    // system("pause");
    return 0;
}
