#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  stack<char> ss;
  for(int i = 0; i < n; i++){
    if(s[i] == '*' and !ss.empty()){
      ss.pop();
    }
    else if(s[i] != '*') ss.push(s[i]);
  }
  cout << ss.size() << '\n';
}