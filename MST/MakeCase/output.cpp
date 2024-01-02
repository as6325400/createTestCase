#include<bits/stdc++.h>
#define int long long

using namespace std;

struct disjoint_set
{
	vector<int> parent;
	vector<int> siz;
	void Init(int n)
	{
		parent.resize(n+1);
		siz.resize(n+1,1);
		for(int i=1;i<=n;i++) parent[i]=i;
	}
	int find(int x)
	{
		if(x==parent[x]) return x;
		return parent[x]=find(parent[x]);
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
	void unite(int a,int b)
	{
		int pa=find(a),pb=find(b);
		if(siz[pa]>siz[pb]) swap(pa,pb);
		parent[pa]=pb;
		siz[pb]+=siz[pa];
	}
} dsu;

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, m;
  input >> n >> m;
  vector<tuple<int, int, int>> graph(m);
  for(int i = 0; i < m; i++){
    int a, b, w;
    input >> a >> b >> w;
    graph[i] = {w, a, b};
  }
  disjoint_set ddd;
  ddd.Init(n + 1);
  sort(graph.begin(), graph.end());
  int count = 0, mm;
  vector<pair<int, int>> ans;
  for(auto [w,v,u]:graph)
  {
      if(!ddd.same(u,v))
      {   
          mm = w;
          count += w;
          ddd.unite(v,u);
          ans.push_back({v, u});
      }
  }
  output << count << '\n';
  for(int i = 0; i < ans.size(); i++){
    output << ans[i].first << ' ' << ans[i].second << '\n';
  }
  output << mm << '\n';
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
 