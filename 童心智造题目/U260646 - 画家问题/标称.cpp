#include <cmath>
#include <cstring>
#include <iostream>
#include <testlib.h>
using namespace std;
char all[16][16];
int anss = 500, n, nn;//分别为答案，n，和2的n次方
void find(int i) { //枚举模块
    for (int j = 0; j < n; j++) {
        all[0][j] = (i % 2 == 1) ? 'y' : 'w';
        i /= 2;
    }
}
void change(int i, int j) {//改变
    if (i >= 0 && i <= n && j >= 0 && j < n) {
        all[i][j] = (all[i][j] == 'w') ? 'y' : 'w';
    }
}
void forChange(int i, int j) {//改变的
    change(i, j);
    change(i - 1, j);
    change(i + 1, j);
    change(i, j - 1);
    change(i, j + 1);
}
bool check() {//判断
    for (int i = 0; i < n; i++) {
        if (all[n][i] != 'y')
            return false;
    }
    return true;
}
int main() {
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        cin >> n;
        nn = pow(2, n);
        char aa[16][16];
        for (int i = 1; i <= n; i++) {//输入
            for (int j = 0; j < n; j++) {
                cin >> aa[i][j];
            }
        }
        anss = 500;
        for (int k = 0; k < nn; k++) {
            find(k);//枚举
            int temp = 0;
            for (int i = 1; i <= n; i++) { //复制到all
                for (int j = 0; j < n; j++) {
                    all[i][j] = aa[i][j];
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < n; j++) {
                    if (all[i - 1][j] == 'w') {
                        forChange(i, j);
                        temp++;
                    }
                }
            }
            if (check()) {
                anss = (anss > temp) ? temp : anss;
            }
        }
        if (anss < 500) {
            cout << anss;
        } else {
            cout << "inf";
        }
    }

}
