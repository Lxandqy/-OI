#include<iostream>
#include<testlib.h>


using namespace std;

long long f[1111111];
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


    for(int _= 1; _ <= 10; _++){
        endTest(_);
         f[1] = 1;
            f[2] = 3;
    for(int i = 3; i <= 60; i++){
           f[i] = f[i - 1] + f[i - 2] * 2;
    }
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
                cout << f[n] << endl;

        }
    }













    return 0;
}
