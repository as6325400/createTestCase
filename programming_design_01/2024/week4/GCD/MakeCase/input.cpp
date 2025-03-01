#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000000000;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);
  vector <int> num = {0, 0, 0, 5, 10, 20, 50, 100, 200, 500, 1000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    int start = rand() % (MAX / 200);
    int rate = MAX / start;
    for(int j = 0; j < num[i]; j++){
      inputFile <<  start * (gen() % rate + 1) << ' ';
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
