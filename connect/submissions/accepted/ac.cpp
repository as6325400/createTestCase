#include <bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
class dsu
{
    private:
        // unordered_map<T,T> parent; 如果可以hash_可以改用umap加速
        vector<T> parent; // 都數字可以再用vector加速，然後建構子要改一下
        // map<T,T> parent;
    public:
        dsu(int number){
            parent.resize(number);
            for(int i = 0; i < number; i++)
                parent[i] = i;
        }
        // dsu(vector<T> save){
        //     for(auto &i:save){
        //         parent[i] = i;
        //     }
        // }
        int parent_number(){
            int count = 0;
            for(auto &i:parent){
                if(i.first == i.second) count++;
            }
            return count;
        }
        T find_root(T x){
            if(x == parent[x]) return x;
            return parent[x] = find_root(parent[x]);
        }
        bool Same(T a, T b){
            return find_root(a) == find_root(b);
        }
        void Union(T a, T b){
            //將a併進b
            parent[find_root(a)] = find_root(b);
        }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> graph(m);
  dsu<int> dd(n + 1);
  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    graph[i] = {w, a, b};
  }
  sort(graph.begin(), graph.end());
  int ans = 0, mm;
  vector<pair<int, int>> ans_e;
  for(auto [w, a, b]:graph){
    if(!dd.Same(a, b)){
      ans += w;
      mm = w;
      ans_e.push_back({a, b});
      dd.Union(a, b);
    }
  }
  if(ans_e.size() == n - 1) cout << "Yes\n";
  else cout << "No\n";
}