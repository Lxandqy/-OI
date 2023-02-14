#include<iostream>
#include<testlib.h>
using namespace std;
int n,m,x;
const int maxn = 100010;
int b[maxn],a[maxn];
int main(){
    for(int _ = 7; _ <= 11; _++){
        endTest(_);
        int n,m,x;
        scanf("%d%d%d",&n,&m,&x);
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d",&b[i]);
        }
        for(int i = 0,j = m - 1; i < n; i++){
            while(j >= 0 && a[i] + b[j] > x){
                j--;
            }
            if(a[i] + b[j] == x){
                cout << i << " " << j << endl;
                break;
            }
        }
    }




    return 0;
}
