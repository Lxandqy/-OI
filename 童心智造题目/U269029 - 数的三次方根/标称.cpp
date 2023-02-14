#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;
double n;
int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        cin >> n;
        double l = -100.0,r = 100.0;
        while(r - l > 1e-7){
            double m = (l + r) / 2;
            if(m * m * m > n) r = m;
            else l = m;
        }
        printf("%.6lf",l);

    }

    return 0;
}
