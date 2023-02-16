一共分为三部分：

1. python部分
2. python调用C++库
3. C++库

# 1. python部分

## 1.1 client

客户端部分采用了任务队列，一个样例一个样例进行判断。

![image-20230215122539350](C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\image-20230215122539350.png)
_run函数
![image-20230215122812332](C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\image-20230215122812332.png)
随后调用了C++模块库

![image-20230215122848561](C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\image-20230215122848561.png)

同样由shell生成库
<img src="C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\image-20230215124342537.png" alt="image-20230215124342537"  />

