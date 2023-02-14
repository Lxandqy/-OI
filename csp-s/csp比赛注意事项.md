## 代码文件要求

1. 代码文件按如下格式组织

   假设考生考号为`BJ-00003`，考生姓名为`王小明`，其文件夹应命名为：`BJ-00003wangxiaoming`。

   该文件夹下有四个子文件夹，分别对应四道题目，假设四道题目英文名分别为`division`，`card`，`travel`，`perfect`

   文件夹组织如下：

   ```none
   BJ-00003wangxiaoming
   |                 |                 |                    |
   division          card              travel               perfect
   |                 |                 |                    |
   division.cpp      card.cpp          travel.cpp           perfect.cpp
   ```

   即，第一层是根目录，根目录下有四个文件夹，名字分别是题目英文名，每个题目文件夹下放对应名字的cpp文件

附：CCF对文件夹规范的描述： 绿色框是选手需要建好的文件夹目录 ![img](https://tva1.sinaimg.cn/large/e6c9d24egy1h49e8fiwkij20u00nbq6h.jpg)

1. 代码是离线测评的，也就是说，考试结束后统一测代码，考场上只能通过自己测样例，造数据，自己在本地debug

2. 提交的代码内需要添加文件读写语句。比如，该题英文名是`card`，则在书写好代码后，在main函数里添加下面两句

   ```cpp
   int main(){
   	freopen("card.in","r",stdin);//需要额外添加的
   	freopen("card.out","w",stdout);//需要额外添加的
   	//以下是其他代码
   }
   ```

   正常测试的时候，可以先注释掉这两句文件读写，在DevC++里自己测试好没问题了，提交时再加上这两句代码