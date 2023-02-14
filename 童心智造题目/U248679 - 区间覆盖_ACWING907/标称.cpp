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
    for(int _ = 7; _<= 10;_++){
        endTest(_);
        int s,t;
        cin >> s >> t;
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i].l >> a[i].r;
        }

        sort(a + 1,a + n + 1,cmp);

        while(q.size()) q.pop();
        bool flag = true;
        for(int i = 1; i <= n; i++){
            node h;
            h.l = a[i].l;
            h.r = a[i].r;
            if(q.size() && q.top().r >= t) break;
            if(a[i].r < s) continue;
            /*if(q.size())
            cout << q.top().l << " " << q.top().r << "Asd"<< endl;*/
            if(q.empty()){
                if(a[i].l <= s) q.push({a[i].l,a[i].r});
                else{
                    flag = false;
                    break;
                }
            }else{
                if(a[i].l > q.top().r){
                    flag = false;
                    break;
                }
                if(a[i].r <= q.top().r) continue;
                if(a[i].l <= s){
                    while(q.size()) q.pop();
                    q.push({a[i].l,a[i].r});
                }else{
                    if(q.size() == 1){
                        q.push({a[i].l,a[i].r});
                    }else{
                        node p1 = q.top();q.pop();node p2 = q.top();
                        if(a[i].l <= p2.r){
                            q.push({a[i].l,a[i].r});
                        }else{
                            q.push(p1);
                            q.push({a[i].l,a[i].r});
                        }
                    }
                }
            }
        }

        if(q.size() && q.top().r < t) flag = false;

        if(flag) cout << q.size() << endl;
        else cout << -1 << endl;
    }


    return 0;
}
