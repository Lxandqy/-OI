#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<testlib.h>
void move(int x,char pos1,char pos2)
{
	printf("%c->%d->%c\n",pos1,x,pos2);
}
/*
N:�������ӵĸ���
pos1:��ʼλ��
pos2����תλ��
pos3:Ŀ��λ��
*/
void Hanoi(int n,char pos1,char pos2,char pos3)
{
	if (n == 1)
	{
		move(n,pos1,pos3);
	}
	else
	{
		Hanoi(n-1,pos1,pos3,pos2);
		move(n,pos1, pos3);
		Hanoi(n-1,pos2,pos1,pos3);
	}
}
int main()
{
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int m;char a,b,c;
        scanf("%d %c %c %c", &m,&a,&c,&b);
        Hanoi(m, a, b, c);
    }

	return 0;
}
