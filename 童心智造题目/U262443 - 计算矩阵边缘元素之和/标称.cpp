#include<iostream>
#include<testlib.h>

using namespace std;

int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,m;
        cin >> n >> m;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int x;
                cin >> x;
                if(i == 1 ||  j == 1 || i == n || j == m) sum += x;
            }
        }
        cout << sum << endl;
    }





    return 0;
}
