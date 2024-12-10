#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 32;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);


  for(int i = 32; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + id + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    
    int n = 200000, q = 200000;
    inputFile << n << " " << q << endl;
    for(int i = 0; i < n; i++){
      inputFile << 1 << " ";
    }
    inputFile << endl;
    for(int j = 0; j < q / 2; j++){
      int l, r;
      l = dis(gen) % n + 1;
      r = dis(gen) % n + 1;
      if(l > r) swap(l, r);
      inputFile << l << " " << r << endl;
    }
    for(int j = q / 2; j < q; j++){
      int l, r;
      inputFile << 1 << " " << n << endl;
    }
    inputFile.close();
  }
  return 0;
}
