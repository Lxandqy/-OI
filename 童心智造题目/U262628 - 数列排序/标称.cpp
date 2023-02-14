#include<iostream>
#include<testlib.h>


using namespace std;

int a[1111111];
int sum[1000000];

int main(){


   for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n,k,sum = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(a[i] > a[j]){
                    sum++;
                }
            }
        }
        cout << sum << endl;
   }









    return 0;
}
