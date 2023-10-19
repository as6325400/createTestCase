#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    if(s == "inf") cout << 0 << '\n';
    else if(s == "NaN") cout << "inf" << '\n';
    else{
        stringstream ss(s);
        double num;
        ss >> num;
        cout << 1 / num << '\n';
    }
  }
}
