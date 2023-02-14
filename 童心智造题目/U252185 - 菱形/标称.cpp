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
        int n;
        cin >> n;
        int x = n * 2 - 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= (x - (i * 2 - 1)) / 2; j++) printf(" ");
            for(int j = 1; j <= (i * 2 - 1); j++) printf("%d",j);
            printf("\n");
        }

        for(int i = n - 1; i >= 1; i--){
            for(int j = 1; j <= (x - (i * 2 - 1)) / 2; j++) printf(" ");
            for(int j = 1; j <= (i * 2 - 1); j++) printf("%d",j);
            printf("\n");
        }

    }




    return 0;
}
