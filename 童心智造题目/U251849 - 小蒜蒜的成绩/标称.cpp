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
    for(int _ = 1; _<= 13;_++){
        endTest(_);

        int a,b,sum = 0;
        scanf("%d %d",&a,&b);
        if(a < 60) sum++;
        if(b < 60) sum++;
        if(sum != 1){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }



    }


    return 0;
}
