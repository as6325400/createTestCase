#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  stack<char> s;
  cin >> n;
  for(int i = 0; i < n; i++){
    int mode;
    cin >> mode;
    if(mode == 1){
      char c;
      cin >> c;
      s.push(c);
    }
    else if(mode == 2){
      if(!s.empty()){
        cout << s.top() << '\n';
        s.pop();
      }
      else{
        cout << "no character\n";
      }
    }
    else{
      if(!s.empty()) cout << s.top() << '\n';
      else cout << "no character\n";
    }
  }
}