#include<iostream>
#include<testlib.h>
using namespace std;
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

int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        cnt = 0,s = 0;
        int n;
        cin >> n;
        int x,y;
        for(int i = 1; i <= n; i++){
            cin >> ch;
            if(ch == "I"){
                cin >> x;
                insert(x);
            }else if(ch == "PM"){
                output();
            }else if(ch == "DM"){
                swap_h(1,cnt);
                cnt--;
                down(1);
            }else if(ch == "D"){
                cin >> x;
                int u = ps1[x];
                swap_h(u,cnt);
                cnt--;
                up(u);
                down(u);
            }else{
                cin >> x >> y;
                change(x,y);
            }
        }
    }
    return 0;
}
