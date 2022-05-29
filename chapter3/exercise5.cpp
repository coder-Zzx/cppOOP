/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

class Sample
{
private:
    char name;
    int A[5];
    friend class Process;

public:
    Sample()
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> this->A[i];
        }
    }
    ~Sample()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << this->A[i] << " ";
        }
        cout << endl;
    }
};

class Process
{
public:
    Sample *s = new Sample();
    void sort()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5 - i; j++)
            {
                if (s->A[j] > s->A[j+1])
                {
                    swap(s->A[j], s->A[j+1]);
                }
            }
        }
    }
    ~Process()
    {
        this->sort();
        delete s;
    }
};

int main()
{
    Process *p = new Process();
    delete p;
    // system("pause");
    return 0;
}
