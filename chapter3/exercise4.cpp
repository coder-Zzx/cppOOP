/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Line;

class Point
{
private:
    double x;
    double y;
public:
    Point();
    // ~Point();
    friend double dist(Line &l,Point &p);
};

class Line
{
private:
    double A;
    double B;
    double C;
public:
    Line();
    // ~Line();
    friend double dist(Line &l,Point &p);
};

Point::Point()
{
    cin>>this->x>>this->y;
}

Line::Line()
{
    cin>>this->A>>this->B>>this->C;
}

double dist(Line &l,Point &p)
{
    double d=fabs((l.A*p.x+l.B*p.y+l.C)/sqrt(pow(l.A,2)+pow(l.B,2)));
    return d;
}

int main()
{
    Point P;
    Line L;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<dist(L,P)<<endl;
    // system("pause");
    return 0;
}
