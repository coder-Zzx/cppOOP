/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/
#include <iostream>
using namespace std;

class exercise2
{
private:
    static int static_int;
    int i_number;
    char name;
    float f_number;
    bool flag;
    /* data */
public:
    exercise2(/* args */);     //构造函数，对类的各个数据成员赋值
    ~exercise2();              //析构函数，对类的各个成员输出其值、地址
    static void static_func(); //输出类的静态数据成员的值
    exercise2 *GetAddress();   //获取对象的地址
};

exercise2::exercise2()
{
    cin >> this->i_number >> f_number >> this->name >> this->flag;
}

exercise2::~exercise2()
{
    char *p = &this->name;
    cout << "==========" << this->name << "==========" << endl;
    cout << "static int number=" << this->static_int << "\tadress:" << &this->static_int << endl;
    cout << "i_number=" << this->i_number << "\tadress:" << &this->i_number << endl;
    cout << "f_number=" << this->f_number << "\tadress:" << &this->f_number << endl;
    cout << "name=" << this->name << "\tadress:" << (void *)p << endl;
    cout << "flag=" << this->flag << "\tadress:" << &this->flag << endl;
    cout << this->name << "`s address:" << this << " "
         << "the size:" << sizeof(*this) << endl;
    cout << "static_func`s address\t" << (void *)this->static_func << endl;
    cout << "GetAddress`s address\t" << (void *)&this->GetAddress << endl;
    cout << "=====================" << endl;
}

void exercise2::static_func()
{
    cout << "this is a static func" << endl;
}

exercise2 *exercise2::GetAddress()
{
    return this;
}

int exercise2::static_int = 100;

exercise2 *s_global_1 = new exercise2();
exercise2 *s_global_2 = new exercise2();

void func()
{
    exercise2 *s_func_1 = new exercise2();
    exercise2 *s_func_2 = new exercise2();
    delete s_func_1;
    delete s_func_2;
    cout<<"func done!"<<endl;
}

int main()
{
    exercise2 *s_main_1 = new exercise2();
    exercise2 *s_main_2 = new exercise2();
    func();
    cout << (void *)main << " " << (void *)func << endl;
    delete s_main_1;
    delete s_main_2;
    delete s_global_1;
    delete s_global_2;
    // system("pause");
    return 0;
}