#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 31;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);

  for(int i = 31; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + id + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << 1 << ' ' << 5 << ' ' << 10 << endl;
    inputFile << 1 << ' ' << 3 << ' ' << 5 << endl;
    inputFile << 4 << ' ' << 5 << ' ' << 6 << endl;
    inputFile.close();
  }
  return 0;
}
