#include<bits/stdc++.h>
#define int long long

using namespace std;

char rv(char a){
    if(a == '}') return '{';
    if(a == ']') return '[';
    // if(a == ')') return '(';
    return '#';
}

bool isValid(string s) {
    stack<char> save;
    // save.push(s[0]);
    for(int i = 0; i < s.size(); i++){
        if(!save.empty() and rv(s[i]) == save.top()) save.pop();
        else save.push(s[i]);
    }
    return save.empty();
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  if(isValid(s)) cout << "Yes\n";
  else cout << "No\n";
}
