#include<iostream>
#include<testlib.h>


using namespace std;

int main(){

        for(int _ =1; _ <= 10; _++){
            endTest(_);
            int n,sum = 0;
            cin >> n;
            for(int i = 0; ; i++){
                int x = i;
                sum = 0;
                for(;x > 0;){
                    sum += x % 10;
                    x /= 10;
                }
                if(sum == n) {
                    cout << i << endl;
                    break;
                }
            }

        }






    return 0;
}
