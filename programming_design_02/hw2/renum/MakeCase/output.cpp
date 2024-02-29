#include<bits/stdc++.h>
#define int unsigned long long

using namespace std;

int reverse(int num){
  int ans = 0;
  while(num > 0){
    ans *= 10;
    ans += (num % 10);
    num /= 10;
  }
  return ans;
}


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int num, count = 0;
  input >> num;
  while(num != reverse(num)){
    count++;
    num += reverse(num);
    if(num > 9223372036854775807){
      output << "Lycherl" << endl;
      return;
    }
  }
  output << count << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 15;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 