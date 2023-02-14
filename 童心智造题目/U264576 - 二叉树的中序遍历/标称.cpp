#include<iostream>
#include<cstring>
#include<testlib.h>

using namespace std;

const int N = 1e5 + 10;
int n;


struct node{
    int l,r;
}a[N];

int dist[N],Du[N];
void dfs(int x,int pre){
    if(a[x].l != -1) dfs(a[x].l,x);
    printf("%d",x);
    if(a[x].r != -1) dfs(a[x].r,x);
}


int main(){
    for(int _= 1; _ <= 10;_++){
        endTest(_);
        cin >> n;
        memset(Du,0,sizeof Du);
        memset(a,0,sizeof a);
        for(int i = 1; i <= n; i++){
            int x,y;
            cin >>x >> y;
            a[i].l = x;
            a[i].r = y;
            if(x != -1)
                Du[x]++;
            if(y != -1)
                Du[y]++;
        }

        int Root = 0;

        for(int i = 1; i <= n; i++){
            if(Du[i] == 0) Root = i;
        }

        dist[0] = 0;
        dfs(Root,0);


    }




    return 0;
}
