#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 13;
  srand(time(nullptr));
  vector<int> save = {0, 0, 5, 5, 10, 10, 20, 50, 100, 1000, 10000, 20000, 200000, 200000};
  for(int i = 2; i <= teseCaseNum; i++){
    double min_value = -save[i] * 500; // 最小值
    double max_value = save[i] * 500; // 最大值
    if(i == 13){
      min_value = -1e50;
      max_value = 1e50;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min_value, max_value);
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << save[i] << '\n';
    for(int j = 0; j < save[i]; j++){
      double random_number = dist(gen);
      if(random_number == 0){
        j--;
        continue;
      }
      if(j % 3 == 0){
        if(j % 5 == 0) inputFile << "inf\n";
        else inputFile << "NaN\n";
      }
      inputFile << random_number << '\n';
    }
    inputFile.close();
  }
  return 0;
}
