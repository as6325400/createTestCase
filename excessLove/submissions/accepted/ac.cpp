#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, ans = 1;
  cin >> t;
  vector<int> save(t);
  for(int i = 0; i < t; i++){
    cin >> save[i];
    ans *= save[i];
  }
  int temp = *min_element(save.begin(), save.end());
  ans /= temp;
  ans *= (temp - 1);
  cout << ans << '\n';
}
