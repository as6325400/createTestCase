#include<bits/stdc++.h>
#define int long long

using namespace std;

void dfs(int now, vector<vector<int>> &graph, vector<bool> &visited){
  visited[now] = true;
  for(auto i:graph[now]){
    if(visited[i] == false) dfs(i, graph, visited);
  }
}


void output(string caseName){
  ifstream input(caseName);
  int n, m;
  input >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<bool> visited(n + 1, false);
  for(int i = 0; i < m; i++){
    int a, b, w;
    input >> a >> b >> w;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int flag = 1;
  dfs(1, graph, visited);
  for(int i = 1; i <= n; i++){
    if(visited[i] == false) flag = 0;
  }

  cout << caseName << ' ';
  if(flag) cout << "true\n";
  else cout << "false\n";
  
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  // secret testcase
  int testCaseName = 9;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
