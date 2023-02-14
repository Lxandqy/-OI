///对拍文件，需要在另外三个文件编译后才可运行
///windows下生成.EXE可执行文件，文件都放在同一文件夹下用文中给的相对路径即可
#include<bits/stdc++.h>
using namespace std;

//freopen("data.in","r",stdin);
//    freopen("ac.out","w",stdout);
//   freopen("data.in","r",stdin);
 //   freopen("wa.out","w",stdout);
//
int main(){
    int Case=1;
    while(1){
        printf("The result of No. %d Case is:  ",Case=1);
        system("rand");     ///windows不加"./"，linux下需要在可执行文件的文件名前加"./"
        system("ac");      ///system("./***");  运行程序，其中***代表可执行文件名
        system("wa");
        if (system("fc ac.out wa.out")){       ///windows 下用  system("fc *** ***");
            printf("Wrong Answer\n");          ///linux 环境用  system("diff *** ***");
            return 0;                  ///比较两个文件，我们在对拍时比较两个不同程序的输出文件
        }
        else printf("Accepted\n");
    }
    return 0;
}
