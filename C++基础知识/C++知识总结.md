1.[数组](#1)
2.[指针](#2)
3.[存储](#3)
4.[结构体](#4)
5.[const修饰符](#5)
6.[引用](#6)
7.[作用域](#7)
8.[重载](#8)
9.[封装](#9)
10.[初始化列表](#10)
11.[static关键词](#11)
12.[友元](#12)
13.[继承](#13)
14.[多态](#14)
15.[封装](#15)
<span id = "1"></span>
**1.数组**
关于数组首先对于一个一维数组来说 type a[N]  type表示他的类型，N表示数组的大小 a就是该数组的首地址 所以数组也可以用 *a来表示 每往右移一个位置地址就(如果是小端法地址增加 type类型的字节数)
![在这里插入图片描述](https://img-blog.csdnimg.cn/db11c1087bcf4ffcab310dcaa2f3a7c4.png)


教大家如何去判断小端法大端法:

```cpp
int a[2];
a[1] = 1;
cout << *(int *)((char *)&a[0]) << " " << *(int *)((char *)&a[0] + 1) << " " << *(int *)((char *)&a[0] + 2) << " " << *(int *)((char *)&a[0] + 3) << endl;
	cout << a << " " << &a[0] << " " << &a[1] << " " << (a + 2) << endl;
如果输出0001即是大端法 反之亦然
```
对于char数组比较特殊 因为他输出地址的时候 会把值输出出来直到遇到 '\0'才会停止 但是他每次往右只增加一个字节 所以我们通常可以转化成(Char*)就可以变成一次一次加了

**多维数组**
对于多维数组来说 例如一个 二维数组 int a[5][3];
因为我们知道C的特性是组合就近原则有数组和数组组合 再和指针结合 所以我们可以把它看出 a是一个数组数组大小为5 数组中每个成员是一个大小为3的数组 并且地址是从左到右从上到下增加的
![在这里插入图片描述](https://img-blog.csdnimg.cn/5684be92139d4664ab50785a8784f856.png)
并且如果是 使用的是 (a + 1)这种的话 因为我们现在是代表 a[]数组所以每次跳的地址数 就是3 * 4 跳的是一整个 但是如果现在是 (a[0] + i) 每次就是跳4个字节 (不过都要符合内存对齐条件 有些计算机pack是8 如果你 #program pack 改为1就变成我上述所说的了)

<span id = "2"></span>
**2.指针**

 1. type *a 是一级指针 表示 a是一个指针 指向type类型的地址想要获取a的值就需要解引用 *a即可 那么对于 type **a 是二级指针 表示 a是一个指针 指向 指向type类型的指针地址的地址 简化以下就是 a是一个指针 指向 一个type类型指针的地址![在这里插入图片描述](https://img-blog.csdnimg.cn/b1ada976249041629bee20657fb82c83.png)

 2. 对于有数组的指针来说 一般是会先和数组结合 例如 int *a[5] a就会和[5]先结合 表示 a是一个有5个元素的数组 每个元素存的是 int类型的指针![在这里插入图片描述](https://img-blog.csdnimg.cn/485cc90bc208440f9165125c3d47f3c0.png)
    那么如果是 int ( * a)[5] 表示 a是一个指针 指向 int类型数组的首地址 ![在这里插入图片描述](https://img-blog.csdnimg.cn/8dc4f551cb6d465c8f0a44e501f2b388.png) 
 函数指针 type (*) () 这样形式的就是一个函数指针 最右边的表示所拥有的变量 例如 int (*a)(int x,int y)  表示a是一个指针指向函数地址![在这里插入图片描述](https://img-blog.csdnimg.cn/ccf1f1eb432b43eab8f1794b4353f44f.png)
    对于上述图片来说 指向了 sb函数的地址 函数的名字代表函数的地址 在下边运用的时候 你可以解引用也可以不解引用 那么对于 int(**a)(int x,int y) 去掉了 *a来说剩下的就是 int(*)(int x,int y) 代表的就是 a是指针 指向了一个函数指针 ![在这里插入图片描述](https://img-blog.csdnimg.cn/1e0bbea07d4148ee8c9dccd3582ae562.png)
    对于b来说必须解引用 因为解引用了之后才能表示他是一个函数指针 
    3.char * 指针 对于char * = "adas"这种形式来说 后面的 adas是常量 属于在常量区里面是不能改变的
<span id = "3"></span>
**3.存储**
局部变量存在栈区 static和全局变量是放在静态区的 无论是全局static还是局部都是在静态区 常量存在常量区 堆区需要我们自己分配 例如 malloc 和 free 不过记得释放
<span id = "4"></span>
**4.结构体**
1.第一个成员在结构体变量偏移量为0的地址处。

2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。

对齐数 = 编译器默认的对齐数与该成员大小的较小值。

3.结构体总大小为最大对齐数的整数倍（每个成员变量都有一个对齐数）。

4.如果嵌套了结构体，嵌套的结构体对齐到自己最大对齐数的整数倍处，结构体的整体大小就是所有所有最大的对齐数的整数倍（包含嵌套结构体的对齐数）。
<span id = "5"></span>
**5.const修饰符解析**
const 会对于 就近的数修饰为常量
例如 const int a 修饰了a为常量
const int *a 修饰了 *a为常量但是 a不是常量 所以a地址可修改
const int * const a 表示 *a和 a都是常量
![在这里插入图片描述](https://img-blog.csdnimg.cn/abe430d7eacb4e8aa074a027c77e5718.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/459c2420a80f4271bb721567e701afcc.png)
<span id = "6"></span>
**6.引用**
引用为 int &a = b;
表示a代表b 相当于a用的就是b的地址 但是 a引用完后不能更改引用对象因为引用的本质就是一个指针常量 int &a相当于 int * const a 引用做函数参数的时候 可以改变实参 
<span id = "7"></span>
**7.作用域**
1、首先对于创建的变量来说，有两个属性特别重要：
（1）作用域 （2）以及生命周期
2、一般，作用域一般分为全局作用域、局部作用域、类作用域、语句作用域、文件作用域以及命名作用域；
**全局变量**：
作用域：整个程序还有其他的源文件 （使用extern）
生命周期：整个程序
存放：静态全局区，每次对其进行的更改会保留
**静态全局变量**：
作用域：对应的程序内
生命周期：整个程序
存放：静态全局区，每次对其进行的更改会保留
注：相比于全局变量，静态全局变量只是更改了其作用域
**局部变量**：
作用域：该函数内部，在函数的外部不能执行
生命周期：该函数调用期间，调用完毕进行回收；
存放：存放在栈上
**静态局部变量**：
作用域：该函数内部，在函数的外部不能执行
生命周期：整个程序执行期间
存放：存放在静态全局区
注：对于静态局部变量的更改会保留下来，如果重读调用的话，会改变他的值；
**类作用域**：
对于类作用域：肯定是作用域：为类；
调用其中的函数：必须显示的实例化对象，进行调用；
可以使用类名直接进行初始化，还可以使用指针进行初始化；
3、
内存的分配方式为静态分配以及动态的分配：
对于静态的分配：直接在程序中，或者是函数中进行创建；那么这个过程在编译的阶段就进行确定，
效率高，但是灵活性不高；
还可以使用动态分配的方式，在堆区使用new 的方式来创建对象，使用指针的方式进行接收；
注意这里需要使用delete来释放掉相对应的内存空间；

<span id = "8"></span>
**8.重载**  

 1. **函数重载**
 函数重载对于同一个作用域下相同变量名的函数只需要满足以下一点即可 1.变量个数不同2.变量顺序不同3.函数参数类型不同 就可以进行重载了 
 2.**运算符重载** 要使用 operator 我分别举几个例子吧
 加法运算符重载: 
```cpp
struct node{
	int x,y;
	node operator+(node &a){
		node d = {this->x + a.x,this->y + a.y};
		return d;
	}
}; 
```
左移运算符重载: 

```cpp
//写在结构体外
ostream & operator<<(ostream &cout,node &a){
	printf("%d %d\n",a.x,a.y);
	return cout;	
}
//写在结构体内
firend ostream & operator<<(ostream &cout,node &a){
	printf("%d %d\n",a.x,a.y);
	return cout;	
}
//为什么我要写返回的类型为 ostream & 因为为了保证程序的健壮性 cout << a << endl; 前面 cout << a如果返回的不是 &cout类型那么后续就会报错
```
前置++运算符重载

```cpp
node & operator++(){
		this->x++;
		return *this;
	}
```
后置++运算符重载

```cpp
node & operator++(int ){
		int x = this->x;
		this->x += 1;
		node s = {x,this->y};
		return s;
	}
//后面的int表示占位 可以区分前置++
```

<span id = "9"></span>
**9.封装**
   * **class代表封装** 和结构体有点相似但是结构体默认全是public 
      **注意1.:成员函数和成员变量是分开存的所以class里面的内存大小只有成员变量(非静态) 如果没有变量的话 默认占一个内存空间**
      **注意2.成员函数如果是个虚函数的话 内部会存在一个4个字节的vfptr(virtual function pointer)指针指向vftable虚函数表 表内部记录虚函数的地址**
      ![在这里插入图片描述](https://img-blog.csdnimg.cn/7cc266aef1b44fefa855eedd4ed5d911.png)

class可以更改权限: 

```cpp
class{
public: int a;
private: int b;
};
//这样外部访问不到b这个值 只能内部访问
```
注意:public表示全部都能访问 protected表示子类可以访问父亲类 但是其他外部不能访问 private 表示只有内部可以访问
  * **构造函数与拷贝构造函数与析构函数**
 构造函数的调用规则 : 
 默认构造函数 (无参，函数体为空)
 默认拷贝构造函数(对属性值进行拷贝)
 如果构造了有参构造函数 默认无参构造函数消失 但是会提供默认拷贝函数
 如果构造了默认拷贝函数 系统不会提供其他构造函数


```cpp
//构造函数和拷贝构造都是无返回值
class ss{
	public:
		int a,b;
	
	ss(){ //无参构造
		
	}
	ss(int a){ //有参构造
		this->a = a;
	}
	ss(const ss &p){ //拷贝构造
		this->a = p.a;
		this->b = p.b;
	}
	//注意拷贝对象不要初始化匿名对象
	//ss s3;
	// ss(s3) == ss s3; 所以会报错
	
	//隐式转换法 ss s3 = 10 与 ss s3 = ss(10)
};
```
**拷贝构造运用时机:**
1.使用已经初始化过的对象来创建另一个对象
2.值传递的方式给函数传参
3.以值方式返回给局部变量
**析构函数**
表示形式就是 ~(封装名) 系统自动销毁并释放内存
**浅拷贝与深拷贝**
浅拷贝 : 对于值简单的拷贝
深拷贝 : 在堆区重新申请内存进行拷贝
首先我用malloc指向了一块地址 对于系统拷贝调用来说我的对象指向的是和我拷贝对象的地址是一块地方 那么我释放内存的时候就会重复释放产生错误
所以我们会使用深拷贝重新定义拷贝每次拷贝都要申请自己的独立的地址这样释放就不会产生错误
**成员函数 对象**
**如果成员函数加了const** 那么就是常函数常含数不能修改成员变量 但是如果成员属性增加 mutable 那么该成员可以在成员函数中修改
**如果对象增加了const** 那么就是常对象 常对象只能访问常函数
<span id = "10"></span>
**10.初始化列表**

```cpp
class node{
	public:
		int a,b;
		int *c;
	
	node():a(10),b(20){
	}
	node(int a,int b):a(a),b(b){
		
	}
};
```
<span id = "11"></span>
**11.static**
放在静态区 作用域为当前文件 这句话意思是 如果 1.cpp 和 2.cpp是一起编译使用的 2.cpp不能使用1.cpp里面static的变量; 类里面的static函数只能访问static变量 并且 static变量只有一个 创建几个对象使用的都是一个static变量 创建完staic变量后 需要在类外部声明初始值
<span id = "12"></span>
**12友元**
  * 全局函数做友元 函数可以访问class里面的私密成员 
  * 类做友元 另一个类产生的对象可以访问当前类的私密成员
  * 成员函数做友元 该函数可以访问当前类的私密成员

  <span id = "13"></span>
  **13.继承**
  **1.继承的第一大特点就是提高代码复用性** 
  **2.继承的权限:**
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/813337282efb42c790207456908f8e45.png)
**3.继承后子类有哪些成员**
子类继承父类会拥有父类全部非静态成员 但是private被系统隐藏了访问不到但是是真是存在的
**4.继承中构造与析构的关系**
先构造父类再构造子类 先析构子类再析构父类
**5.继承中同名的访问方式**
直接访问是访问子类的 如果想访问父类的话需要加作用域
**6.菱形继承的处理方式 (继承多个爹 但是爹的爹是一样的产生了重复的属性)**
数据会有两份所以会产生资源浪费
我们只需要给父类加上virtual 变成虚继承父亲的父亲叫虚基类
继承后重复的属性访问一块地址
因为产生了一个 vbprt(virtual base pointer) 指向 vbtable vbtable会记录重复数据的偏移量 对于每个 vbptr在类中的地址 偏移会指向一块地址 所以不会产生资源浪费
<span id = "14"></span>
**14.多态**
**1.静态多态与动态多态**
运算符重载和函数重载属于**静态多态**
派生类和虚函数属于**动态多态**
**静态多态**属于早绑定在编译期间就绑定了
**动态多态**在运行的时候才绑定
**虚函数**:在函数名面前加virtual就是虚函数让计算机不知道什么时候运行
如果子类重写父类的虚函数则会动态绑定
**纯虚函数**(抽象类子类必须重写 无法实例化对象):用大于号替换 = 0;
![在这里插入图片描述](https://img-blog.csdnimg.cn/27be94c723c944938bd96207e5553bbd.png)
析构有个问题就是我们 Animal animal = new cat的时候 如果我们cat里面有堆指针的话 我们需要释放这个堆指针 但是默认调用的是父亲的析构函数 所以我们要用**虚析构**来释放
对于**纯虚析构**来说 我们必须要给父类外部重写析构 因为我们在给子类析构的时候父类也要析构

<span id = "15"></span>
**15.模板**

  * **函数模板:**
```cpp
template<typename T,typename TT> typename可以换成class
void 函数名（T a,TT b)
//使用事项 1.系统自动推导出T等typename才能使用
//2.函数名<type,type>()自己写出T等typename代表的类型
```
**普通函数与函数模板的区别：**
普通函数会产生隐式转换
函数模板只有自己写出类型才会隐式转换 
隐式转换的意思 >> 就是将传进去的参数自动转换成对应的参数
**函数模板调用规则：**
如果普通函数和函数模板都可以调用优先调用普通函数
函数模板也可以重载
**模板的局限性**
```cpp
#define Template template
#define Typename typename
Template <Typename T>
bool myswap(T& a, T& b) {
	if (a == b) return true;
	else return false;
}
//如果T传的是一个结构体他就不知道如何去比较
//那么我们必须重载模板
Template <>
bool myswap(node& a, node& b) {
	if (a.x == b.x && a.y == b.y) return true;
	else return false;
}
```
  * **类模板**


```cpp
Template <Typename T>
class 类名<Typename a,Typename b{
	void sb(T &a);
}

Template<Typename T>
void 类名<T>::sb(T &a){
} //类外实现
```
**类模板使用注意事项:**
类模板没有自动推导功能
类模板可以有默认参数

```cpp
Template <Typename T = int>
class 类名<Typename a,Typename b{

}
```
**类模板中成员创用时机** : 调用时才会创建
**类模板对象做函数参数传递方式:**
**1.指定传入类型**

```cpp
Template <Typename T>
class node{
public:
	T x, y;
};

void show(node<int> &a) {
	cout << a.x << " " << a.y;
}

int main() {
	node<int> a = { 1,2 };
	show(a);

```

**2.参数模板化**

```cpp
Template <Typename T>
class node{
public:
	T x, y;
};

Template <Typename T>
void show2(node<T>& a) {
	cout << a.x << " " << a.y;
}
node<int> a = { 1,2 };
show2(a);
```

**3.整个类模板化**
```cpp
Template <Typename T>
class node{
public:
	T x, y;
};

Template <Typename T>
void show2(T& a) {
	cout << a.x << " " << a.y;
}
node<int> a = { 1,2 };
show2(a);
```

**类模板与继承**
**注意事项:**
1.儿子继承父类要把父模板的类型指定出来

```cpp
class node{
public:
	T x, y;
};

class node2 :public node<int> {

};
```
2.想灵活指定父亲模板的类型 需要把儿子也变成模板

```cpp
Template <Typename T>
class node{
public:
	T x, y;
};

Template <Typename T,Typename T2>
class node3 : public node <T> {

};
```
**类模板分文件写注意事项**
**解决方法:**
1.首先类模板里面的实现函数如果包含Typename的话他是不会直接创建出来的所以我们如果分.h 和 .cpp去写的类模板 我们需要直接包含.cpp 因为.h不创建出来所以没有函数声明
2.将.h和.cpp写在一起 .hpp文件表面这是一个类模板文件

**类模板全局函数实现:**
1.全局函数内部实现

```cpp
Template <class T>
class node{
	friend void awr(node &a) {
		cout << a.x  << endl;
	}
public:
	node(int x, int y) {
		this->x = x, this->y = y;
	}
private:
	T x, y;
};
```
2.全局函数外部实现

```cpp
//首先声明这个类
Template<class T>
class node;
//声明这个模板的实现形式
Template<class T>
void awr(node<T> a) {
	cout << a.x <<  " " << a.y << endl;
}

Template <class T>
class node{
//友元awr是个模板
	friend void awr<T>(node<T> a);
public:
	node(int x, int y) {
		this->x = x, this->y = y;
	}
private:
	T x, y;
};
```
**模板特化：**
模板谈特化就是对于特殊类型的我们进行特殊化处理
模板为什么要特化，因为编译器认为，对于特定的类型，如果你对某一功能有更好地实现，那么就该听你的。

模板分为类模板与函数模板，特化分为全特化与偏特化。全特化就是限定死模板实现的具体类型，偏特化就是模板如果有多个类型，那么就只限定为其中的

一部分，其实特化细分为范围上的偏特化与个数上的偏特化。

模板的泛化：是指用的时候指定类型。
全特化如下：

```cpp
template<typename T,typename T2>
	struct Node{
	};
template<> //我们对于所有泛型进行特定处理
	struct Node<char,int>{
	};
```
偏特化如下：

```cpp
template<typename T,typename T2>
	struct Node{
	};
template<typename T>  //我们只对一部分进行特化，就是对于T2进行特化
	struct Node<T,int>{
	};
```
笔者在面试的时候遇到了面试官问unordered_map的源码，现场支支吾吾答不出来，面试官问以下代码是否正确？

```cpp
struct node{
	int x;
	string a;
};
unordered_map<node,int> m;
```
事实上一定是错误的，但是笔者只对string，int做过哈希，没对结构体做过哈希所以导致答不上来。
第二天去阅读unordered_map的源码如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/8126a644943b48b48c3684d8b23ba773.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/7a2a4eb2d2594ee28832b49694f68ff5.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/ceea875a94624b538076f67a46418f07.png)
发现对于普通类型都是全特化，对于结构体应该是偏特化，那么string也是结构体为什么string不用呢？
那么发现在另一个头文件里写了对于string的全特化
![在这里插入图片描述](https://img-blog.csdnimg.cn/dafe1ba01fb041cfa8e1f4c883a0cb61.png)
所以对于结构体来说应该是偏特化，使用的是结构体指针！