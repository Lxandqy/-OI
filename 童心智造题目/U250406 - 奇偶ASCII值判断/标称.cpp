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
        char x;
        cin >>x;
        if((int)x % 2 == 0){
            cout <<"NO" << endl;
        }else cout << "YES" <<endl;

    }


    return 0;
}
