#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 12;
  srand(time(nullptr));
  vector<int> num = {0, 0, 0, 0, 5, 10, 10, 10, 10, 1000, 1000000, 1000000, 1000000};
  for(int i = 12; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    for(int j = 0; j < num[i]; j++){
      inputFile << 2 * (rand() % (int)(2e8 - 1)) + 1  << ' ';
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
