#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> odd;
  vector<int> even;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    if(num % 2 == 1) odd.push_back(num);
    else even.push_back(num); 
  }
  sort(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  for(auto i:odd){
    cout << i << ' ';
  }
  cout << '\n';
  for(auto i:even){
    cout << i << ' ';
  }
  cout << '\n';
}