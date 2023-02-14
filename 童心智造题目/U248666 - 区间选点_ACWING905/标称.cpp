#include<bits/stdc++.h>
#include<testlib.h>
using namespace std;
template <typename T>
T find_kth_element(T arr[], int rk, const int len) {
  if (len <= 1) return arr[0];
  // 随机选择基准（pivot）
  const T pivot = arr[(int)rnd.next() % len];
  // i：当前操作的元素
  // j：第一个等于 pivot 的元素
  // k：第一个大于 pivot 的元素
  int i = 0, j = 0, k = len;
  // 完成一趟三路快排，将序列分为：
  // 小于 pivot 的元素 ｜ 等于 pivot 的元素 ｜ 大于 pivot 的元素
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
