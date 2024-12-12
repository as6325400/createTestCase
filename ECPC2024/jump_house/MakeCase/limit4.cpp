#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 36;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);


  for(int i = 35; i <= teseCaseNum; i++){
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
      if(i < n / 2){
        inputFile << gen() % 2 << " ";
        continue;
      }
      if(i % 2 == 0) inputFile << 1 << " ";
      else inputFile << 0 << " ";
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
      
      inputFile << n / 2 << " " << n << endl;
    }
    inputFile.close();
  }
  return 0;
}
