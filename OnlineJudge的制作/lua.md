# Lua介绍

特点：最快的脚本语言，嵌入式语言

输出： print(123) 

声明变量： 直接赋值即可   a = 1，b = "123123" 等，但是默认为全局变量即可以在其他文件中使用，若想局部变量 local a = 1 即可。

nil：相当于c语言中的none

赋值： a,b = 1,2  相当于 a = 1，b = 2，没有赋值的默认为nil

number：支持科学计数法2e9，16进制 0x...

^ : 相当于次幂

<< ，>>: 左移右移

字符串 : "  "    ' ' 双引号，单引号都是字符串

[[ ]]：多行文本，里面字符不会被转义字符转换

.. :   a..b  字符串a和字符串b连接起来

tostring(x) ： 变成字符串

tonumber("") : 将字符串变成数字，若转换失败返回nil

#： 字符串前面加# 例如 #a 则会输出a的长度

**函数**

```lua
function f(a,b)
	print(a,b)
    return a,b
end

//函数可以传入任意的值，若没有传到的默认为nil
```

**table**

```lua
a = {1,"ac",{},function() end}  //类似数组，lua的表可以存任何东西，但是下标从1开始
a[5] = 123  //表可以直接赋值
print(a[1])  //输出1
table.insert(a,"d") //在表末尾插入
table.insert(a,2,"d") //在第二个元素前面插入
table.remove(a,2) //删除第2个元素 并且返回该元素
printf(#a) //输出表的长度
```

```lua
a = {
	a = 1,
	b = "1234",
	c = function()
	end,
	d = 123123，
    [",;"] = 123
}
a["abc"] = "asdasd" //可以这样用
print(a["a"]) //这种写法例如map
print(a.a) //这样子也可以输出 
print(a[,;])
```

全局表，在lua中有个全局表 _G，所有全局变量都在 _G中可以找到

```lua
a = 1
print(_G["a"])
```

布尔：

1 > 2，1~=2 //不等于

支持 a and b，a or b，not a //与或非 但是返回的不一定是true，false，返回的是 a 或者 b，只有not返回true，false

在lua中，nil 和 false是假，

分支：

```lua
if 1>10 then
	print("!23")
elseif 1 < 10 then
    print("123")
else 
	print("no")
end
```

循环:

```lua
for i=1,10,1 do   //分别是初始值，结束值，步长 并且i在循环过程中不能修改
	if i == 5 then break end   //结束
end

local n = 10
while n > 1 do
   n = n - 1 // n-- ,n -= 1 是不被允许的 
end
```

强制转换

```lua
s = string.char(0x30,0x31) //可以把ascii 变成字符返回字符串
n = string.byte(s,2)  //将字符串某个拿出来变成ascii
```

lua文件引用另一个lua文件需要使用require函数

1. 运行指定文件
2. 末尾不带.lua扩展名
3. 目录层级用 . 分隔(类似于python)
4. 只会运行一次

例如 require(path/hello)

当我们使用 package.path = patckage.path.. ";/path/?.lua"

我们就无需再写路径，直接require(hello)即可



XXX.YYYY，如何实现此类型的函数

```lua
local hello = {}
fuction hello.say()

end
```



对于table的遍历

```lua
t = {"a","b","c","d"}

for i = 1,#t,1 do
	print(i,t[i])
end

for i,j in ipairs(t) do  //ipairs只能对于下标为数字类型的,并且得按顺序
   	print(i,j)   
end

t = {
    apple = "a",
    banana = "b",
    eraser = "c",
    water = "d"
}

for i,j in pairs(t) do
    print(i,j)
end

//pairs内部机制就是next函数  next(t,"b") 可以得到答案  eraser c
//倘若后边没有，输出nil
```

正则表达式具体看官方手册。



**原表-> 相当于可以重写加减乘除。**

例如:

```
t = {a = 1}
mt = {
	__add = function(a,b)
		return a.a + b
	end,
}
setmetable(t,mt);
```



lua上的协程

创建协程返回thread类型  coroutin.create()；



lua添加新库

1. 内嵌库
   直接在Lua内部添加C库
2. 共享库
   使用require调用C库

内嵌库：

```
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include <stdio.h>

static int Test_hello(lua_State *L){
	printf("hello lua!!\n");
	return 0;
}

static const struct luaL_Reg testlib[] = {
	{"hello",Test_hello}//注册在lua中使用的时候的函数名字
	{NULL,NULL}
};

int luaopen_test(lua_State *L){
	LuaL_newlib(L,testlib); //在lua表中添加注册的函数
	return 1;
}
```



lua栈

lua使用虚拟栈和C互传值，这个栈不同于lua栈也不是C里面的栈。

<img src="C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\image-20230216213342156.png" alt="image-20230216213342156" style="zoom:80%;" />栈顶先取出，随后再栈慢慢取出。
<img src="C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\image-20230216230125737.png" alt="image-20230216230125737" style="zoom:80%;" />

上图中 L代表的就是栈，里面包含传入的参数。