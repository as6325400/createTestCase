#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(0, 255);
  vector<vector<int>> vec = {
    {},
    {},
    {5, 8},
    {15, 20},
    {40, 40},
    {100, 100},
    {200, 400},
    {300, 300},
    {270, 200},
    {512, 512},
    {512, 512},
  };
  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << vec[i][0] << ' ' << vec[i][1] << "\n";
    for(int j = 0; j < 3; j++)
    {
      for(int k = 0; k < vec[i][0]; k++)
      {
        for(int q = 0; q < vec[i][1]; q++)
        {
          inputFile << gen() % 256 << ' ';
        }
        inputFile << '\n';
      }
    }
    inputFile.close();
  }
  return 0;
}
