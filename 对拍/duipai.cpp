///�����ļ�����Ҫ�����������ļ������ſ�����
///windows������.EXE��ִ���ļ����ļ�������ͬһ�ļ����������и������·������
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
        system("rand");     ///windows����"./"��linux����Ҫ�ڿ�ִ���ļ����ļ���ǰ��"./"
        system("ac");      ///system("./***");  ���г�������***�����ִ���ļ���
        system("wa");
        if (system("fc ac.out wa.out")){       ///windows ����  system("fc *** ***");
            printf("Wrong Answer\n");          ///linux ������  system("diff *** ***");
            return 0;                  ///�Ƚ������ļ��������ڶ���ʱ�Ƚ�������ͬ���������ļ�
        }
        else printf("Accepted\n");
    }
    return 0;
}
