#include<bits/stdc++.h>
#define int long long

using namespace std;

string random_string(int len, set<char> n){
  string str = "";
  for(int i = 0; i < len; i++){
    char c = 'a' + rand() % 26;
    while(n.count(c)){
      c = 'a' + rand() % 26;
    }
    str += (char)c;
  }
  return str;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 20;
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

    int mode = dis(gen) % 2;
    int len1 = dis(gen) % 10 + 1;
    int len2 = dis(gen) % 10 + 1;

    if(len1 > len2){
      swap(len1, len2);
    }

    // 答案為 yes
    if(mode == 0){
      string pattern = random_string(len1, set<char>());

      // 扣掉 pattern 的長度  
      int dis = len2 - len1;
      int front = rand() % (dis + 1);
      int back = dis - front;
      set<char> ss;
      map<char, int> mp;
      for(int i = 0; i < len1; i++){
        mp[pattern[i]]++;
        ss.insert(pattern[i]);
      }

      string str = pattern;
      shuffle(str.begin(), str.end(), gen);

      string word = "";
      word += random_string(front, ss);
      word += str;
      word += random_string(back, ss);

      inputFile << pattern << endl;
      inputFile << word << endl;

    }

    else{
      string pattern = random_string(len1, set<char>());
      set<char> ss;
      for(int i = 0; i < len1; i++){
        ss.insert(pattern[i]);
      }
      string word = random_string(len2, ss);
      inputFile << pattern << endl;
      inputFile << word << endl;
    }
    inputFile.close();
  }
  return 0;
}
