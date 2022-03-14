<div>
<center>c++面向对象程序设计实验报告</center>
<div align="right"">物联网001 朱志鑫</div>
</div>

## 一、实验要求

> 1、定义一个类，其中有静态数据成员、各种类型非静态数据成员（含字符指针），静态和非静态成员函数（含分配空间的构造函数、析构函数）。  
> 2、定义全局对象、main函数中局部对象、另一个被main调用的外部函数func中定义局部对象（可以是形参），main函数中动态创建对象，每种对象至少2个。观察、分析各种对象地址。  
> 3、输出对象中各个静态与非静态数据成员的值、地址、对象的存储空间大小等信息。由此理解对象的本质、静态数据成员是本类对象共享一份拷贝等问题。  
> 4、对于上述各种对象，输出静态非静态成员函数地址，以及main、func的地址，并分析。

## 二、关键代码

   完整代码放在[这里](https://github.com/coder-Zzx/cppOOP/blob/main/chapter3/exercise2.cpp)

1. 类的声明：

```cpp
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
```

2. 外部函数:

```cpp
void func()
{
    exercise2 *s_func_1 = new exercise2();
    exercise2 *s_func_2 = new exercise2();
    delete s_func_1;
    delete s_func_2;
}
```

3. main函数：

```cpp
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
```

## 三、运行结果

1. 程序输入：

```cpp
1 1.0 a 1
2 2.0 b 0
3 3.0 c 1
4 4.0 d 0
5 5.5 e 1
6 6.0 f 0
```

    其中，第一位为整型变量i_number赋值，第二位为浮点型变量f_number赋值，第三位为字符指针型变量name赋值，第四行为布尔型变量flag赋值，同时对静态数据成员赋值

```cpp
int exercise2::static_int = 100;
```

程序输出：

```cpp
==========e==========
static int number=100   adress:0x404010
i_number=5      adress:0x661dc0
f_number=5.5    adress:0x661dc8
name=e  adress:0x661dc4
flag=1  adress:0x661dcc
e`s address:0x661dc0 the size:16
static_func`s address   0x4018b0
GetAddress`s address    0x4018e2
=====================
==========f==========
static int number=100   adress:0x404010
i_number=6      adress:0x661de0
f_number=6      adress:0x661de8
name=f  adress:0x661de4
flag=0  adress:0x661dec
f`s address:0x661de0 the size:16
static_func`s address   0x4018b0
GetAddress`s address    0x4018e2
=====================
0x4019a9 0x4018f0
==========c==========
static int number=100   adress:0x404010
i_number=3      adress:0x661e60
f_number=3      adress:0x661e68
name=c  adress:0x661e64
flag=1  adress:0x661e6c
c`s address:0x661e60 the size:16
static_func`s address   0x4018b0
GetAddress`s address    0x4018e2
=====================
==========d==========
static int number=100   adress:0x404010
i_number=4      adress:0x661e80
f_number=4      adress:0x661e88
name=d  adress:0x661e84
flag=0  adress:0x661e8c
d`s address:0x661e80 the size:16
static_func`s address   0x4018b0
GetAddress`s address    0x4018e2
=====================
==========a==========
i_number=1      adress:0x661770
f_number=1      adress:0x661778
name=a  adress:0x661774
flag=1  adress:0x66177c
a`s address:0x661770 the size:16
static_func`s address   0x4018b0
GetAddress`s address    0x4018e2
=====================
==========b==========
static int number=100   adress:0x404010
i_number=2      adress:0x661790
f_number=2      adress:0x661798
name=b  adress:0x661794
flag=0  adress:0x66179c
b`s address:0x661790 the size:16
static_func`s address   0x4018b0
GetAddress`s address    0x4018e2
=====================
```

## 四、结果分析

        首先，从输出结果的顺序可以看出，在执行构造函数时，遵循“全局对象->main函数中的对象->外部函数中的局部对象”的顺序，在执行析构函数时其顺序恰好相反，这与c++的性质相吻合。

        其次可以发现，每个对象的静态数据成员以及静态成员函数static_int,static_func()的地址相同，甚至在实例化对象之前就可以对类的静态数据成员赋值，同时，每个对象的成员函数也共用一个地址，也就是说，对于同一类的不同对象而言，所有对象共用其静态数据成员，静态成员函数以及其他成员函数，静态数据成员，静态成员函数归一个类的全体对象所有。

        再者，对象的地址，静态数据成员的地址，成员函数的地址是不连续的，考虑到在对象被实例化以前，类的静态数据成员就被赋值了，所以这是合理且自然的，同时，对象的地址实际上就是对象首个数据成员的地址，并且在对象所需地址空间内，对象的所有非静态数据成员是在内存上连续存放的，并且遵循内存对齐原则，向类中字节最长的数据成员对齐（整形，浮点型，字符型，布尔型长度分别为4,4,1,1，于是对齐为4，共占据16个字节），同时可以看到对象的内存大小也为16字节，即对象的成员函数不在对象的成员空间内，而是另有安排（也许是为了兼容c中的struct）。

        最后，可以看出，c++中的类与对象，本质上是内存上的一段连续的空间，这段空间内存储着对象的各个数据成员，从这个角度来看，类与对象像是更高级的struct，或者是Python中的list（当然比作list这个比喻有些不恰当，list本质是一个动态长度的数组，可被随时改变，但是类与对象的地址空间在实例化时就被确定无法改变，但是list与类都可以看做是一群不同或相同的数据类型的集合）。
