#include<iostream>
#include<testlib.h>

using namespace std;

int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int a;
        cin >> a;

        int minn = 0x3f3f3f3f;
        int maxn = 0;
        for(int i = 0; i <= 10000; i++){
            if(a >= i * 4 && (a - i * 4) % 2 == 0){
                minn = min(minn, i + (a - i * 4) / 2);
                maxn = max(maxn, i + (a - i * 4) / 2);
            }
        }

        if(minn == 0x3f3f3f3f) cout << 0 << " " << 0 << endl;
        else cout << minn << " " << maxn << endl;
    }



    return 0;
}
