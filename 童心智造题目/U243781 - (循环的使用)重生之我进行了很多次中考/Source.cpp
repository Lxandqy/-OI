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
                cout << "�ҿ����˺�����!!\n";
        }else if(a >= 698){
                cout << "�ҿ�����ѧ����ѧ!!\n";
        }else if(a >= 695){
                cout << "�ҿ�������ɽ��ѧ!!\n";
        }else{
                cout << "�Һò�!�Ҹ���Ҫ��������!\n";
        }
    }





    return 0;
}
