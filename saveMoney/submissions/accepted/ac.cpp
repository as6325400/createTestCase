#include <bits/stdc++.h>
#define int long long

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int mon = 1; 
        while(n > 0)
        {
            int res = mon;
            for(int i = 1 ;i <= min(n, (int)7); i++ )
            {
                sum += res++;
                sum %= (int)(1e9 + 7);
            }
            mon++;
            n = n-7;
        }
        return sum % (int)(1e9 + 7);
    }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  Solution sol;
  cout << sol.totalMoney(n) << '\n';
}