#include<iostream>
#include<testlib.h>


using namespace std;

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,m,sum = 0;
        cin >> n >> m;
        for(int i = n; i <= m; i++){
            int x = i;
            for(;x > 0;){
                sum += x % 10;
                x /= 10;
            }
        }
        cout << sum << endl;
    }







    return 0;
}
