#include<bits/stdc++.h>
#define int long long

using namespace std;


// #include<stdio.h>
// #include<string.h>
// #define int long long

// char s1[100005];
// char s2[100005];


// signed main(){
//   scanf("%s %s", s1, s2);
//   int len1 = strlen(s1), len2 = strlen(s2);
//   createTable();
//   for(int i = 0; i < len1; i++){
//     printf("%c", transform(s1[i], s2[i % len2]));
//   }
//   printf("\n");
// }

char table[26][26];

void createTable(){
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 26; j++){
      table[i][j] = (char)((i + j) % 26) + 'a';
    }
  }
}

char transform(char a, char b){
  if(b < 'a') b += 32;
  if(a >= 'a') return table[a - 'a'][b - 'a'];
  return table[a + 32 - 'a'][b - 'a'] - 32;
}

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  string s1, s2;
  input >> s1 >> s2;
  int len1 = s1.length(), len2 = s2.length();
  createTable();
  for(int i = 0; i < len1; i++){
    s1[i] = transform(s1[i], s2[i % len2]);
  }
  output << s1;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 