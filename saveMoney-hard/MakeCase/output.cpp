#include<bits/stdc++.h>
#define int long long

using namespace std;
class Solution {
public:
    int totalMoney(int n) {
      int mod = 1e9 + 7;
        int w = n / 7;
        int money = w * 28;
        money += (7 * w * (w - 1)) / 2;

        if (n % 7) {
            int extra_days = n % 7;
            int money_to_add = w + 1;
            for (int i = 0; i < extra_days; ++i) {
                money += money_to_add;
                money_to_add += 1;
            }
        }
        return money % mod;
    }
};


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n;
  input >> n;
  Solution s;
  output << s.totalMoney(n) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  output(path + "sample/" + "3.in");
  // secret testcase
  int testCaseName = 12;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 