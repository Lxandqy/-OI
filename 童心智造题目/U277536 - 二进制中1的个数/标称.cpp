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

//����ȷ���ݹ��Ǹ���ģ�ȷ����������ɶ��
//һ������д�ľ���ȷ����ǰ�����Ķ��ӽڵ���˭
//��Ҫ���ز�����
//��Ҫ���ݲ�����  x ��ǰ���ǰ��������ĸ�����  x + 1~x + 3��x+4~x+5
//ʲôʱ������ݹ飬��ǰ�����û�ж����˾ͽ�����
int flag[N];

	int n;
void dg(int cnt){//��¼ǰ�����������������
	flag[a[cnt]] = 1;
	int id;
	for(int i = 1; i <= n; i++){
		if(b[i] == a[cnt]) id = i;
	}

	//        a id1 a a id a  a a a
	int id1 = 0,id2 = n + 1;
	//ȥ����ҵ���һ������������
	for(int i = id - 1; i >= 1; i--){
		if(flag[b[i]] == 1){
			id1 = i;
			break;
		}
	}
	//˵�� id1 + 1 ~ id - 1�ĵ㶼��������
	if(id - 1 - (id1 + 1) + 1 != 0){
		c[a[cnt]].l = a[cnt + 1];
		dg(cnt + 1);
	}
	//�ұ��ҵ���һ������������
	for(int i = id + 1; i <= n; i++){
		if(flag[b[i]] == 1){
			id2 = i;
			break;
		}
	}
	//cnt+ id - 1 - (id1 + 1) + 1 + 1
	//��ʱ˵��  id + 1 ~ id2 - 1�����������ĵ�
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
