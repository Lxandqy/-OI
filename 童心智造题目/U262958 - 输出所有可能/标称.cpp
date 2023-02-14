#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<testlib.h>
#include<cstring>
#include<iostream>
using namespace std;
void move(int x,char pos1,char pos2)
{
	printf("%c->%d->%c\n",pos1,x,pos2);
}
/*
N:代表盘子的个数
pos1:起始位置
pos2：中转位置
pos3:目的位置
*/

int n;
void dfs(int y,string a){
    if(y == n){
        cout << a << endl;
        return ;
    }
    for(int i = 1; i <= n; i++){
        dfs(y + 1,a + char(i + '0'));
    }

}



int main()
{
    for(int _ = 1; _ <= 7; _++){
        endTest(_);
        cin >> n;
        dfs(0,"");
    }

	return 0;
}
