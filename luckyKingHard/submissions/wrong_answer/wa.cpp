#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, ans = 0;
  cin >> t;
  while(t != 0){
    ans += t /= 2;
  }
  cout << ans << '\n';
}
