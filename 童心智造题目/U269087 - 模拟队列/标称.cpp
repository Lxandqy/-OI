#include<iostream>
#include<testlib.h>
using namespace std;
const int maxn = 100010;
int a[maxn];
int cnt = 0,head = 1;
int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
         int n,m;
        cnt = 0,head = 1;
        cin >> n;
        string s;
        int b;
        for(int i = 1; i <= n; i++){
            cin >> s;
            if(s[0] == 'p' && s[1] == 'u'){
                cin >> b;
                a[++cnt] = b;
            }else if(s[0] == 'p' && s[1] == 'o'){
                ++head;
            }else if(s[0] == 'q'){
                cout << a[head] << endl;
            }else{
                if(head > cnt) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }



    return 0;
}
