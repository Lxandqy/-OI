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
    for(int _ = 1; _<= 12;_++){
        endTest(_);
    int n;
    scanf("%d",&n);
    if(n%3==0&&n%5==0&&n%7==0)
    {
        cout<<"3 5 7";
    }
    else if(n%3==0&&n%5==0)
    {
        cout<<"3 5";
    }
    else if(n%5==0&&n%7==0)
    {
        cout<<"5 7";
    }
    else if(n%3==0&&n%7==0)
    {
        cout<<"3 7";
    }
    else if(n%3==0)
    {
        cout<<"3";
    }
      else if(n%5==0)
    {
        cout<<"5";
    }
      else if(n%7==0)
    {
        cout<<"7";
    }
    else
        cout<<"n";
    }


    return 0;
}
