#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 12;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);
  vector<int> vec = {0, 0, 5, 5, 10, 10, 10, 20, 40, 100, 1000, 10000, 200000};
  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + id + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = vec[i];
    inputFile << n << '\n';
    for(int i = 0; i < n; i++){
      int a = dis(gen) % (int)(1e6 - 1) + 1;
      int b = dis(gen) % (int)(1e6 - a) + 1 + a;
      inputFile << a << ' ' << b << '\n';
    }
    inputFile.close();
  }
  return 0;
}