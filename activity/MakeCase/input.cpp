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
  std::uniform_int_distribution<int> dis(1, 1000000000);
  vector<int> v = {0, 0, 0, 10, 20, 100, 200, 1000, 10000, 100000, 200000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << v[i] << endl;
    for(int j = 0; j < v[i]; j++){
      int s = dis(gen), e = dis(gen);
      if(s > e) swap(s, e);
      inputFile << s << " " << e << endl;
    }
    inputFile.close();
  }
  return 0;
}
