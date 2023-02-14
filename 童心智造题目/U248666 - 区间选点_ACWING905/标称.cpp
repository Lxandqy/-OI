#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;
template <typename T>
T find_kth_element(T arr[], int rk, const int len) {
  if (len <= 1) return arr[0];
  // ���ѡ���׼��pivot��
  const T pivot = arr[(int)rnd.next() % len];
  // i����ǰ������Ԫ��
  // j����һ������ pivot ��Ԫ��
  // k����һ������ pivot ��Ԫ��
  int i = 0, j = 0, k = len;
  // ���һ����·���ţ������з�Ϊ��
  // С�� pivot ��Ԫ�� �� ���� pivot ��Ԫ�� �� ���� pivot ��Ԫ��
  while (i < k) {
    if (arr[i] < pivot)
      swap(arr[i++], arr[j++]);
    else if (pivot < arr[i])
      swap(arr[i], arr[--k]);
    else
      i++;
  }
  if (rk < j) return find_kth_element(arr, rk, j);
  else if (rk >= k)
    return find_kth_element(arr + k, rk - k, len - k);
  return pivot;
}

const int N = 5e6 + 10;
int a[N];
int main(){
        endTest(1);
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        int k;
        cin >> k;
        cout << find_kth_element(a,k,n) << endl;





    return 0;
}
