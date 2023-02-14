#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#include<queue>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 101000;
const int maxn = 1e5 + 5;
string ch;int cnt = 0,h[maxn],ps1[maxn],ps2[maxn],s = 0;//ps1记录 第i个插入的数的位置，ps2记录 这个位置的数是第几个插入的;
void swap_h(int x,int y){
    swap(h[x],h[y]);
    swap(ps2[x],ps2[y]);
    swap(ps1[ps2[x]],ps1[ps2[y]]);
}
void down(int x){
    int t = x;
    if(x * 2 <= cnt && h[t] > h[x * 2]) t = x * 2;
    if(x * 2 + 1 <= cnt && h[t] > h[x * 2 + 1]) t = x * 2 + 1;
    if(t != x){
        swap_h(x,t);
        down(t);
    }
}
void up(int x){
    if(x / 2 > 0 && h[x / 2] > h[x]){
        swap_h(x,x / 2);
        up(x >> 1);
    }
}
void insert(int x){
    s++;
    h[++cnt] = x;
    ps1[s] = cnt;
    ps2[cnt] = s;
    up(cnt);
}
void output(){
    cout << h[1] << endl;
}
void change(int x,int y){
    h[ps1[x]] = y;
    up(ps1[x]);
    down(ps1[x]);
}

int a[N];
int flag[N];

map<int,int>mp;
int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 1; _ <= 11; _++){
        startTest(_);
        memset(flag,0,sizeof flag);
        int n;
        cout << (n = rnd.next(1,100000)) << endl;
        for(int i = 1; i <= n; i++){
            printf("%d ",rnd.next(0,2000000000));
        }




    }


    return 0;
}
