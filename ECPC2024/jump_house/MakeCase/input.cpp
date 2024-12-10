#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 30;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);


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
    
    int n = 10, q = 5;
    inputFile << n << " " << q << endl;
    for(int i = 0; i < n; i++){
      inputFile << dis(gen) % 2 << " ";
    }
    inputFile << endl;
    for(int j = 0; j < q; j++){
      int l, r;
      l = dis(gen) % n + 1;
      r = dis(gen) % n + 1;
      if(l > r) swap(l, r);
      inputFile << l << " " << r << endl;
    }
    inputFile.close();
  }
  return 0;
}
