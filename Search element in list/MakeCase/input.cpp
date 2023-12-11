#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  vector<int> num = {0, 0, 0, 5, 10, 15, 20, 50, 100, 1000, 100000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    int count = 0;
    for(int j = 0; j < num[i] - 1; j++){
      int mode = rand() % 51 + 1;
      if(mode >= 1 and mode <= 25){
        inputFile << 1 << ' ' << rand() % num[i] + 1 << '\n';
      }
      else if(mode >= 26 and mode <= 50){
        inputFile << 2 << ' ' << rand() % num[i] + 1 << '\n';
      }
      else{
        int number = rand() % num[i] + 1;
        inputFile << 3 << ' ' << number << '\n';
        count += number;
      }
    }
    int number = rand() % num[i] + 1;
    inputFile << 3 << ' ' << number << '\n';
    count += number;
    cout << count << '\n';
    inputFile.close();
  }
  return 0;
}
