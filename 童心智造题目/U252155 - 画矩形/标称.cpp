#include<iostream>
#include<algorithm>
#include<testlib.h>
#include<queue>
#define first x
#define second y

using namespace std;

const int N = 10000;

typedef pair<int,int> PII;

int b[N];

int main(){

    long long a[N];
    for(int _ = 1; _<= 10; _++){
        endTest(_);
        int n,m;
        char c;
        int x;
        scanf("%d %d %c %d",&n,&m,&c,&x);
        for(int i = 1; i <= n; i++){
            if(i == 1 || i == n)
            for(int j = 1; j <= m; j++){
                cout << c;
            }
            else{
                cout << c;
                for(int j = 2; j <= m - 1; j++)
                    if(x == 0) cout << " ";
                    else cout << c;
                cout << c;
            }
            cout << endl;
        }

    }




    return 0;
}
