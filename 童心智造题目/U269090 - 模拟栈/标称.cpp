#include<iostream>
#include<testlib.h>
using namespace std;
const int maxn = 100010;
int a[maxn];
int cnt = 0;
int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int n,m;
        cin >> n;
        string s;
        int b;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> s;
            if(s[0] == 'p' && s[1] == 'u'){
                cin >> b;
                a[++cnt] = b;
            }else if(s[0] == 'p' && s[1] == 'o'){
                --cnt;
            }else if(s[0] == 'q'){
                cout << a[cnt] << endl;
            }else{
                if(cnt == 0) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }


    return 0;
}
