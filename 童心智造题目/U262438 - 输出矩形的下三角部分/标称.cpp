#include<iostream>
#include<testlib.h>

using namespace std;

int a[300][300];

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                if(i >= j) cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }





    return 0;
}
