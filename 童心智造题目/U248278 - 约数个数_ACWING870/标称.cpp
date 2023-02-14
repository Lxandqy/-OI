#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){

    for(int i = 1; i <= 10; i++){
        endTest(i);
        int t;
        cin >> t;
        unordered_map <int,int> prime;
        long long h;
        while(t--){
            cin >> h;
            for(int i = 2; i <= h / i; i++){
                while(h % i == 0){
                    h /= i;
                    prime[i]++;
                }
            }
            if(h > 1) prime[h]++;
        }
        long long sum = 1;
        for(auto i : prime){
            sum = (sum * (i.second + 1)) % mod ;
        }
        cout <<1ll *  sum << endl;
    }






    return 0;
}
