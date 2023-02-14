# 线性dp

## P1216 [USACO1.5][IOI1994]数字三角形 Number Triangles

![image-20221021130315391](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20221021130315391.png)

对于第一行我们已经知道了他的最大值，所以对于第二行通过第一行枚举就好了，第三行通过第二行枚举就好了。
每一行都要等上一行枚举完成才能进行新一轮的枚举。并且当前行只会影响下一行，不会影响上一行，我们称为无后效性，只对未来有影响。

## U255571 最长上升子序列（基础版）

![image-20221021133659630](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20221021133659630.png)

## U255583 最长上升子序列（加强版）

通过上一题，我们发现，我们只需要找到前面最长的且最后一位比我们当前i小的即可。

![image-20221021142510253](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20221021142510253.png)

记录完后我们发现有一个性质，那就是长度越长的结尾的数一定会越大
以 $i$ 为结尾的 长度为 $j$ 的上升子序列，一定是在前 $i - 1$存在一个以点$k$结尾长度为 $j - 1$的上升子序列。只有满足 $a_i > a_k$才能成立
所以长度为$j - 1$结尾的最大也可以取到$a_k$ 所以长度越长，结尾的数一定会越大
所以我们最后只需要二分就能完美解决了。

## U255600 最长公共子序列

![image-20221021152618679](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20221021152618679.png)

## P2758 编辑距离

![image-20221021155632483](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20221021155632483.png)

![image-20221021160027095](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20221021160027095.png)

可以由这两种状态转移

