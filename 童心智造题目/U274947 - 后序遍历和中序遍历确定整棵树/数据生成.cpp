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

void dg1(int x){  //Кѓ
    if(a[x].l) dg1(a[x].l);
    if(a[x].r) dg1(a[x].r);
    printf("%d ",x);
}

void dg2(int x){ //жа
    if(a[x].l) dg2(a[x].l);
    printf("%d ",x);
    if(a[x].r) dg2(a[x].r);
}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 1; _ <= 11; _++){
        startTest(_);
        int n;
        n = rnd.next(1,1000);
        memset(head,-1,sizeof head);
        memset(a,0,sizeof a);
        anss = 0;
        cout << n <<endl;
        for(int i = 1; i <= n; i++) fa[i] = i,mp[i] = 0;
        for(int i = 1; i <= n - 1; i++){
            int x = rnd.next(1,n);
            int y = rnd.next(1,n);
            while(find(x) == find(y) ||(x == 1 && mp[x] >= 2) || (y == 1 &&mp[y] >= 2) || mp[x] >= 3 || mp[y] >= 3){
                x = rnd.next(1,n);
                y = rnd.next(1,n);
            }
            mp[x]++,mp[y]++;
            fa[find(x)] = find(y);
            add(x,y);
            add(y,x);
        }

        dg(1,0);
        dg1(1);
        cout << endl;
        dg2(1);



    }


    return 0;
}
