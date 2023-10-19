#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 50;
  srand(time(nullptr));

  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int num = rand() % 20 + 1;
    int win = rand() % num + 1;
    int loss = num - win;
    int player = rand() % 3 + 1;
    inputFile << num << ' ' << player << ' ' << win << ' ' << loss << '\n';
    inputFile.close();
  }
  return 0;
}
