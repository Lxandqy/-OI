#include<bits/stdc++.h>
#define cin myfile
#define cout outfile

using namespace std;

ifstream myfile("./data/game6.in");
ofstream outfile("./data/game6.out", ios::trunc);

int main(){

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if(a >= 700){
                cout << "我考上了杭二中!!\n";
        }else if(a >= 698){
                cout << "我考上了学军中学!!\n";
        }else if(a >= 695){
                cout << "我考上了萧山中学!!\n";
        }else{
                cout << "我好菜!我高中要继续加油!\n";
        }
    }





    return 0;
}
