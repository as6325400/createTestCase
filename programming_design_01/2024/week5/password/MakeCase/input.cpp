#include<bits/stdc++.h>
#define int long long

using namespace std;

std::random_device rd;  
std::mt19937 gen(rd()); 
std::uniform_int_distribution<int> dis(1, 1000000000);

std::string generateRandomString(int length) {
  const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string randomString;
  randomString.reserve(length);
  for (int i = 0; i < length; ++i) {
      randomString += charset[dis(gen) % charset.length()];
  }
  return randomString;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));

  vector<int> vec = {0, 0, 0, 5, 10, 20, 50, 100, 200, 500, 100000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = vec[i];
    int m = dis(gen) % n + 1;
    inputFile << generateRandomString(n) << endl;
    inputFile << generateRandomString(m) << endl;
    inputFile.close();
  }
  return 0;
}
