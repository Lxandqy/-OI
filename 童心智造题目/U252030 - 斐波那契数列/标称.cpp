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
        a[1] = 1;
        a[2] = 1;
        for(int i = 3; i <= 46; i++){
            a[i] =  a[i - 1] + a[i - 2];
        }
        int n;
        cin >> n;
        cout << a[n] << endl;

    }




    return 0;
}
