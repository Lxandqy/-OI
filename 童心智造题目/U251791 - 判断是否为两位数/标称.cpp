#include<iostream>
#include<algorithm>
#include<testlib.h>
#include<queue>

using namespace std;

const int N = 100010;
struct node{
    int l,r;
    friend bool operator <(const node a,const node b){
        return a.r < b.r;
    }
}a[N];
bool cmp(node a,node b){
    return a.l < b.l;
}
priority_queue<node>q;

int main(){
    for(int _ = 1; _<= 10;_++){
        endTest(_);

        int x;
	scanf("%d",&x);
	if(x >= 10 && x < 99){
		cout << 1 << endl;
	}else cout << 0 << endl;

    }


    return 0;
}
