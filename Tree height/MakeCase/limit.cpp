#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 15;
  srand(time(nullptr));
  vector<int> num = {0, 0, 0, 5, 10, 15, 20, 50, 100, 1000, 1000, 10000, 50000, 100000, 1, 1000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    vector<int> save;
    for(int j = 1; j <= num[i]; j++){
      save.push_back(j);
    }
    std::random_device rd;
    std::mt19937 rng(rd());

    // 使用 std::shuffle 随机打乱数组
    if(i != 15) std::shuffle(save.begin(), save.end(), rng);
    for(auto j: save){
      inputFile << j << ' ';
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
