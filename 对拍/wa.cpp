#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

const int N = 5e5 + 10;

char a[N];
int WZ[N][2][2][2];
int A[N],C[N];
long long sum[N];

int main(){
    freopen("data.in","r",stdin);
    freopen("wa.out","w",stdout);
    scanf("%s",a + 1);
    long long ans = 0;
    int next = 0;
    for(int i = 1; i <= strlen(a + 1); i++){
        sum[i + 1] = sum[i];
        if(a[i] == 'a'){
            A[i + 1] = A[i] + 1;
        }else A[i + 1] = A[i];
        if(a[i] == 'c'){
            C[i + 1] = C[i] + 1;
            sum[i + 1] += A[i + 1];
        }else C[i + 1] = C[i];
        for(int l = 0; l < 2; l++)
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                WZ[i][l][j][k] = WZ[i - 1][l][j][k];
            }
        }
        WZ[i][sum[i] % 2][A[i] % 2][C[i] % 2]++;
    }
    WZ[strlen(a + 1) + 1][sum[strlen(a + 1) + 1] % 2][A[strlen(a + 1) + 1] % 2][C[strlen(a + 1) + 1] % 2]++;
    int newa = 0,newc = -1;
    int G = 0;
    for(int i = 1; i <= strlen(a + 1); i++){
        if(a[i] == 'a') newa = i,G = 0;
        if(a[i] == 'c') newc = i,G++;
        if(newa < newc){
        	next = newa;
        	if(G % 2 == 0){
        		ans++;
        	}
        }
        for(int l = 0; l < 2; l++)
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                int cnt = 0;
                if(l != sum[i + 1] % 2) cnt++;
                if(abs(C[i + 1] - k) == 1 && j == 1) cnt++;
                if(cnt % 2 == 0) ans += WZ[next][l][j][k];
            }
        }
    }


    cout << ans << endl;


    return 0;
}
