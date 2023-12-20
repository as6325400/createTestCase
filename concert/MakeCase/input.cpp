#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 20;
  srand(time(nullptr));

  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int sum = rand() % 2147483648 + 1;
    int parking = rand() % sum + 1;
    string ah, am, lh, lm;
    ah = to_string(rand() % 24 + 1);
    lh = to_string(rand() % 24 + 1);
    am = to_string(rand() % 60 + 1);
    lm = to_string(rand() % 60 + 1);
    if(ah.size() < 2) ah = '0' + ah;
    if(lh.size() < 2) lh = '0' + lh;
    if(am.size() < 2) am = '0' + am;
    if(lm.size() < 2) lm = '0' + lm;
    inputFile << parking << ' ' << sum - parking << ' ' << ah << ' ' << am << ' ' << lh << ' ' << lm << '\n';
    inputFile.close();
  }
  return 0;
}
