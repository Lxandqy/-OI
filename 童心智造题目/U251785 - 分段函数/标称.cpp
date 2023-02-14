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

int main(){double x;
    for(int _ = 1; _<= 10;_++){
        endTest(_);

        scanf("%lf",&x);
        if(x >= 0 && x < 5){
            printf("%.3lf",-x + 2.5);
        }else if(x >= 5 && x < 10){
            printf("%.3lf",2 - 1.5 * (x - 3) * (x - 3));
        }else{
            printf("%.3lf",x / 2 - 1.5);
        }

    }


    return 0;
}
