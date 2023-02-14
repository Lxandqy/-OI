#include<iostream>
#include<queue>
#include<cstring>
#include<testlib.h>

using namespace std;

const int N = 2e6 + 10;
int n;

int has[N],id[N];
long long sum;
struct node{
    int id,w;
    bool operator < (const node &p)const{
        return w < p.w;
    }
}a[N];

struct node2{
    int w,l,r;
}b[N];

void dfs(int x,int pre){
    if(!b[x].l && !b[x].r) sum += b[x].w * pre;
    if(b[x].l) dfs(b[x].l,pre + 1);
    if(b[x].r && b[x].l) dfs(b[x].r,pre + 1);
    else if(b[x].r) dfs(b[x].r,pre);
}





int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        cin >> n;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        sum = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            b[i].w = x;
            a[i].id = i;
            a[i].w = x;
        }

        int cnt = n;
        for(int i = 1 ; i <= n - 1; i++){
            sort(a + (i - 1) *  2 + 1, a + n + i);
            b[++cnt].w = a[(i - 1) *  2 + 1].w + a[(i - 1) *  2 + 2].w;
            b[cnt].l = a[(i - 1) *  2 + 1].id;
            b[cnt].r = a[(i - 1) *  2 + 2].id;
            a[cnt].id = cnt;
            a[cnt].w = b[cnt].w;
        }

        dfs(a[cnt].id,0);

        cout << sum << endl;
    }





    return 0;
}
