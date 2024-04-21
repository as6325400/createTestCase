#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[200005];

int main()
{
  int n, q;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int num;
    scanf("%d", &arr[i]);
  }
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    int l, r, ans;
    scanf("%d%d", &l, &r);
    ans = arr[l];
    for(int j = l + 1; j <= r; j++){
      ans &= arr[j];
    }
    printf("%d\n", ans);
  }
}
