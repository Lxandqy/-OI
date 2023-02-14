#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std ;
const int N=1010 ;
int m,n ;
int h[N],e[N*2],ne[N*2],w[N*2],idx ;
int dis[N] ;
int stop[N] ;
int add_cnt ;
void add(int a,int b,int c)
{
    e[idx]=b ;
    w[idx]=c ;
    ne[idx]=h[a] ;
    h[a]=idx++ ;
}
void Add(int stop[],int start,int end)
{
    add_cnt++ ;
    if(start>=end) return ;
    for(int i=start;i<=(start+end>>1);i++) add(stop[i],add_cnt,0) ;
    for(int i=(start+end>>1)+1;i<=end;i++) add(add_cnt,stop[i],1) ;
    Add(stop,start,start+end>>1) ;
    Add(stop,(start+end>>1)+1,end) ;
}
void bfs()  //和SPFA一个样子
{
    queue<int> q ;
    q.push(1) ;
    memset(dis,0x3f,sizeof dis) ;
    dis[1]=0 ;
    while(q.size())
    {
        int t=q.front() ;
        q.pop() ;
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i] ;
            if(dis[j]>dis[t]+w[i])
            {
                dis[j]=dis[t]+w[i] ;
                q.push(j) ;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&m,&n) ;
    add_cnt=n ;
    string str ;
    getline(cin,str) ;
    memset(h,-1,sizeof h) ;
    while(m--)
    {
        int cnt=0 ;
        string str ;
        getline(cin,str) ;
        memset(stop,0,sizeof stop) ;
        for(auto ch:str)
        {
            if(ch==' ') cnt++ ;
            else stop[cnt]=stop[cnt]*10+ch-'0' ;
        }
        Add(stop,0,cnt) ;
    }
    bfs() ;
    if(dis[n]>1e9) puts("NO") ;
    else printf("%d",dis[n]-1) ;
    return 0 ;
}
