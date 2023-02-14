#include<iostream>
#include<testlib.h>


using namespace std;

int a[1111111];
int sum[1000000];

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1,a + n + 1);
        cout << a[k] << endl;
    }


a




    return 0;
}
