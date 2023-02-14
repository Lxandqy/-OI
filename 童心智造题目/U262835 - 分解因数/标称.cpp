#include<iostream>
#include<testlib.h>


using namespace std;

int a[1111111];
int sum[1000000];

int dfs(int x,int pre){
    if(x == 1) return 1;
    int sum = 0;
    for(int i = pre; i <= x; i++){
        if(x % i == 0) sum += dfs(x / i,i);
    }
    return sum;
}

int main(){


   for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int t;
        cin >>t;
        for(;t--;){

            int x;
            cin >> x;
            cout << dfs(x,2) << endl;

        }
   }









    return 0;
}
