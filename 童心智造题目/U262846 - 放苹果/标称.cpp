#include<iostream>
#include<testlib.h>


using namespace std;

int a[1111111];
int sum[1000000];

int n,m;
int dfs(int x,int y,int pre){
    if(x == 0) return 1;
    else if(y == m +1) return 0;
    int sum = 0;
    for(int i = pre; i <= x; i++){
        sum += dfs(x - i,y + 1,i);
    }
    return sum;
}

int main(){

    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int t;
        cin >> t;
        while(t--){
            cin >>n >>m;
            cout << dfs(n,1,1) <<endl;


        }
    }










    return 0;
}
