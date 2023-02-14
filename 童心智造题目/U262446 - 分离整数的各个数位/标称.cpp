#include<iostream>
#include<testlib.h>

using namespace std;

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        for(;n > 0;){
            if(n == 0) break;
            cout << n % 10 << endl;
            n /= 10;
        }
    }






    return 0;
}
