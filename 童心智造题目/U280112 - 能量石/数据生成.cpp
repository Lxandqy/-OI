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


int fa[N],mp[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int anss;
int head[N],to[N],last[N];
void add(int a,int b){
    to[++anss] = b;
    last[anss] = head[a];
    head[a] = anss;
}

struct node{
    int l,r;
}a[N];

void dg(int x,int pre){
    for(int i = head[x]; i != -1; i = last[i]){
        int j = to[i];
        if(j == pre) continue;
        if(!a[x].l) a[x].l = j;
        else a[x].r = j;
        dg(j,x);
    }

}

void dg1(int x){
    printf("%d ",x);
    if(a[x].l) dg1(a[x].l);
    if(a[x].r) dg1(a[x].r);
}

void dg2(int x){
    if(a[x].l) dg2(a[x].l);
    printf("%d ",x);
    if(a[x].r) dg2(a[x].r);
}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 6; _ <= 11; _++){
            startTest(_);
            int t;
            cout << (t = rnd.next(1,10)) << endl;
            while(t--){
                int n;
                cout << (n = rnd.next(1,100)) << endl;
                for(int i = 1; i <= n; i++){
                    cout << rnd.next(1,100) << " " << rnd.next(1,100000) << " " << rnd.next(1,100000) << endl;
                }
            }
    }


    return 0;
}
