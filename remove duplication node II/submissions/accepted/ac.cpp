#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  map<int, int> mp;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    mp[num]++;
  }
  vector<int> ans;
  for(auto i:mp){
    if(i.second == 1) ans.push_back(i.first);
  }
  cout << ans.size() << '\n';
  for(auto &i:ans){
    cout << i << ' ';
  }
  cout << '\n';
}
