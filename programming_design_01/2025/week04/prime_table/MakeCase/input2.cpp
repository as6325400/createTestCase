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

  for(int i = 6; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + id + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int t = dis(gen) % 10 + 1;
    inputFile << t << '\n';
    for(int j = 0; j < t; j++){
      int left = dis(gen) % (1000000 - 1) + 1;
      int right = left + dis(gen) % (1000000 - left) + 1;
      inputFile << left << ' ' << right << '\n';
    }
    inputFile.close();
  }
  return 0;
}
