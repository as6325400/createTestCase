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

  for(int i = 4; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int arr[4];
    for(int j = 0; j < 4; j++){
      arr[j] = dis(gen) % 2000001 - 1000000;
    }
    inputFile << arr[0] << " " << arr[1] << " " << dis(gen) % 1000000 + 1 << '\n';
    inputFile << arr[2] << " " << arr[3] << "\n";
    inputFile.close();
  }
  return 0;
}
