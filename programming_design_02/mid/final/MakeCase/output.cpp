#include<bits/stdc++.h>
#define int long long

using namespace std;

int dp[26][10005];

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  string pattern, word;
  input >> pattern;
  input >> word;
  int pattern_num[26] = {0};
  for(int i = 0; i < pattern.size(); i++){
    pattern_num[pattern[i] - 'a']++;
  }
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= word.size(); i++){
    for(int j = 0; j < 26; j++){
      dp[j][i] = dp[j][i - 1];
    }
    dp[word[i - 1] - 'a'][i]++;
  }

  int flag = 0;
  for(int i = 0; i < word.size(); i++){
    flag = 0;
    int end = i + pattern.size();
    for(int j = 0; j < 26; j++){
      if(dp[j][end] - dp[j][i] != pattern_num[j]){
        flag = 1;
        break;
      }
    }

    if(flag == 0){
      for(int j = i; j < i + pattern.size(); j++){
        output << word[j];
      }
      output << endl;
      return;
    }
  }

  output << "Invalid" << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 24;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 