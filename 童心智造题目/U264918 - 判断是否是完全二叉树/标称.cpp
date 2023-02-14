#include<iostream>
#include<cstring>
#include<testlib.h>

using namespace std;

const int N = 2e6 + 10;
int n;


struct node{
    int l,r;
}a[N];

int has[N],id[N];
void dfs(int x){
    if(a[x].l != -1 && id[x] * 2 < 2000001){
        id[a[x].l] = id[x] * 2;
        has[id[x] * 2] = 1;
        dfs(a[x].l);
    }
    if(a[x].r != -1 && id[x] * 2 < 2000001){
        id[a[x].r] = id[x] * 2 + 1;
        has[id[x] * 2 + 1] = 1;
        dfs(a[x].r);
    }
}


int main(){
    for(int _= 1; _ <= 10;_++){
        endTest(_);
        int m;
        cin >> n >> m;
        memset(a,0,sizeof a);
        memset(has,0,sizeof has);
        for(int i = 1; i <= n; i++){
            int x,y;
            cin >>x >> y;
            a[i].l = x;
            a[i].r = y;
        }
        id[m] = 1;
        has[1] = 1;
        dfs(m);

        bool flag = true;
        for(int i = 1; i <= n; i++){
            if(!has[i]){
                flag = false;
            }
        }

        if(flag) cout << "YES";
        else cout << "NO";

    }




    return 0;
}
