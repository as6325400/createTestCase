#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  set<int> s;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    s.insert(num);
  }
  for(auto &i:s){
    cout << i << ' ';
  }
  cout << '\n';
}
