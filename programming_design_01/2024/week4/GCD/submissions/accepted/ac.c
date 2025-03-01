#include<stdio.h>
#include<stdlib.h>
#define int long long

int arr[200005];

signed main(){
  int n;
  scanf("%lld", &n);
  int min = 1e9;
  for(int i = 0; i < n; i++){
    scanf("%lld", &arr[i]);
    if(arr[i] < min) min = arr[i];
  }
  int start = min;
  int ans = 1;
  while (start >= 0)
  { 
    int flag = 0;
    for(int i = 0; i < n; i++){
      if(arr[i] % start != 0){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      ans = start;
      break;
    }
    start--;
  }
  printf("%lld\n", ans);
  
  
  return 0;
}