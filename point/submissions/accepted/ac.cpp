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
  int x = 0, y = 0;
  for(int i = 0; i < n; i++){
    if(s[i] != 'b'){
      ss.push(s[i]);
      if(s[i] == 'w') y++;
      if(s[i] == 'a') x--;
      if(s[i] == 's') y--;
      if(s[i] == 'd') x++;
    }
    else{
      if(ss.empty()) continue;
      char c = ss.top();
      ss.pop();
      if(c == 'w') y--;
      if(c == 'a') x++;
      if(c == 's') y++;
      if(c == 'd') x--;
    }
  }
  cout << x << ' ' << y << '\n';
}