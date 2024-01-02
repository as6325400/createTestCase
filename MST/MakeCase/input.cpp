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

// 生成稠密圖
vector<tuple<int, int, int>> generate_dense_graph(int n, set<pair<int, int>> edges) {
    vector<tuple<int, int, int>> graph;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if(edges.count(make_pair(i, j)) == 0 && edges.count(make_pair(j, i)) == 0){
                edges.insert(make_pair(i, j));
                tuple<int, int, int> temp;
                int a = rand() % 20 + 1;
                temp = make_tuple(a, i, j);
                graph.push_back(temp);
                temp = make_tuple(a, j, i);
                graph.push_back(temp);
            }
        }
    }
    return graph;
}

// 生成一般圖
void generate_general_graph(int n, int m, set<pair<int, int>>& edges) {
    while (edges.size() < m) {
        int a = rand() % n;
        int b = rand() % n;
        if (a != b && edges.count(make_pair(a, b)) == 0 && edges.count(make_pair(b, a)) == 0) {
            edges.insert(make_pair(a, b));
        }
    }
}

// 生成聯通圖
void generate_connected_graph(int n, int m, set<pair<int, int>>& edges) {
    // 先建立一張完全圖
    auto graph = generate_dense_graph(n, edges);
    // 找出最小生成樹，以保證圖是聯通的
    disjoint_set ddd;
    ddd.Init(n);
    sort(graph.begin(), graph.end());
    for(auto [w,v,u]:graph)
    {
        if(!ddd.same(u,v))
        {
            ddd.unite(v,u);
            edges.insert(make_pair(v, u));
        }
    }
    // 產生其餘的邊
    generate_general_graph(n, m, edges);
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 9;
  srand(time(nullptr));
  vector<int> n = {0, 0, 8, 8, 20, 20, 20, 50, 300, 300};
  vector<int> e = {0, 0, 12, 20, 25, 40, 80, 125, 300, 150 * 299};
  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    set<pair<int, int>> edges;
    inputFile << n[i] << ' ' << e[i] << '\n';

    generate_connected_graph(n[i], e[i], edges);
    for(auto j:edges){
      inputFile << j.first + 1 << ' ' << j.second + 1 << ' ' << rand() % (1000000) + 1 << '\n';
    }
    inputFile.close();
  }
  return 0;
}
