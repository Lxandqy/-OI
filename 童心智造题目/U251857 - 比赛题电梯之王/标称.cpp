#include<iostream>
#include<algorithm>
#include<testlib.h>
#include<queue>
#define first x
#define second y

using namespace std;

const int N = 10000010;

typedef pair<int,int> PII;

int b[N];

int main(){
    for(int _ = 11; _ <= 12; _++){
            endTest(_);
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            scanf("%d",&b[i]);
        }

        cout << 0 << endl;
        int ed = 1 + b[1],now = 1,pre = 1 + b[1];
        for(int i = 2; i <= n; i++){
            if(i <= pre){
                ed = max(ed,i + b[i]);
            }else{
                now++;
                pre = ed;
            }
            if(i <= pre) printf("%d\n",now);
            else printf("%d\n",-1);
        }
    }



    return 0;
}
