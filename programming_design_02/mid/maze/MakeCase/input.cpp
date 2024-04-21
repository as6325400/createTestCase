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

  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    vector<int> vec(4);
    while(1){
      for(int j = 0; j < 4; j++){
        if(j < 2) vec[j] = dis(gen) % 10;
        else vec[j] = dis(gen) % 21;
      }
      sort(vec.begin(), vec.end());
      if(vec[0] == vec[1] || vec[1] == vec[2] || vec[2] == vec[3]) continue;
      if(vec[2] + vec[3] <= 20) break;
    }
    int mode = rand() % 2;
    if(mode == 0){
      inputFile << vec[0] << " " << vec[1] << ' ' << mode << '\n';
    }
    else{
      inputFile << vec[2] << " " << vec[3] << " " << mode << " " << vec[0] << " " << vec[1] << '\n';
    }
    inputFile.close();
  }
  return 0;
}
