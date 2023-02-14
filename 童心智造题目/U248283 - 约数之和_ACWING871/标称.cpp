#include<iostream>
#include<testlib.h>
#include<unordered_map>
const int mod = 1e9 + 7;
using namespace std;
int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int t;
        cin >> t;
        unordered_map<int,int>m;
        while(t--){
            int n;
            cin >> n;
            for(int i = 2; i * i <= n; i++){
                while(n % i == 0){
                    m[i]++;
                    n /= i;
                }
            }
            if(n > 1) m[n]++;
        }
        long long sum = 1;
        for(auto i : m){
            int a = i.first,b = i.second;
            long long s = 1;
            while(b--){
                s = (s * a + 1) % mod;
            }
            sum = (sum * s) % mod;
        }
        cout << sum << endl;
    }







    return 0;
}
