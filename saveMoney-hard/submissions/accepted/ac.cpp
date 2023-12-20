#include <bits/stdc++.h>
#define int long long

using namespace std;

#define ll long long
ll mod = 1e9 + 7;

int totalMoney(int n) {
  ll w = n / 7;
  ll firstday = ((1 + w) * w / 2);
  ll money = (2 * firstday + w * 6) * 7 / 2;
  
  if(n % 7 != 0){
    ll temp = n % 7;
    money += ((w + 1 + w + temp) * temp / 2);
  }
  
  return (int)money % mod;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << totalMoney(n) << '\n';
}