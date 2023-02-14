#include<iostream>
#include<testlib.h>


using namespace std;

int a[1111111];
int sum[1000000];

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int x = a[n];
        sort(a + 1,a + n + 1);
        for(int i = 1; i <= n; i++){
            cout << a[i] <<" ";
        }
    }







    return 0;
}
