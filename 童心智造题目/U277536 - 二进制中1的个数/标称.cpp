#include<stdio.h>
#include<vector>
#include<algorithm>
#include<testlib.h>
#include<bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;

struct node{
	int l,r;
}c[N];

int a[N],b[N];

//首先确定递归是干嘛的，确定整棵树长啥样
//一个函数写的就是确定当前这个点的儿子节点是谁
//需要返回参数吗？
//需要传递参数吗？  x 当前这个前序遍历到哪个点了  x + 1~x + 3，x+4~x+5
//什么时候结束递归，当前这个点没有儿子了就结束了
int flag[N];

	int n;
void dg(int cnt){//记录前序遍历，遍历到哪了
	flag[a[cnt]] = 1;
	int id;
	for(int i = 1; i <= n; i++){
		if(b[i] == a[cnt]) id = i;
	}

	//        a id1 a a id a  a a a
	int id1 = 0,id2 = n + 1;
	//去左边找到第一个被遍历过的
	for(int i = id - 1; i >= 1; i--){
		if(flag[b[i]] == 1){
			id1 = i;
			break;
		}
	}
	//说明 id1 + 1 ~ id - 1的点都是左子树
	if(id - 1 - (id1 + 1) + 1 != 0){
		c[a[cnt]].l = a[cnt + 1];
		dg(cnt + 1);
	}
	//右边找到第一个被遍历过的
	for(int i = id + 1; i <= n; i++){
		if(flag[b[i]] == 1){
			id2 = i;
			break;
		}
	}
	//cnt+ id - 1 - (id1 + 1) + 1 + 1
	//此时说明  id + 1 ~ id2 - 1都是右子树的点
	if(id2 - 1 - (id + 1) + 1 != 0){
		c[a[cnt]].r = a[cnt	+ id - 1 - (id1 + 1) + 1 + 1];
		dg(cnt	+ id - 1 - (id1 + 1) + 1 + 1);
	}
}


int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int x;
        cin >> x;
        int sum = 0;
        while(x){
            if(x & 1) sum++;
            x >>= 1;
        }
        printf("%d\n",sum);
    }


}
