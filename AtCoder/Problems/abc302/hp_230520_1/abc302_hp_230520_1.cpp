#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int n;
vector<int> a, b;
vector gr(0, vector<int>());
vector<int> ans;

struct UnionFind {
  map<int, vector<int>> memo;
  vector<int> d;
  vector<int> edge;
  int qe = 0;
  UnionFind(int n) : d(n, -1), edge(n, 0) {}
  int find(int x) {
    if (d.at(x) < 0) return x;
    return find(d.at(x));
  }
  int unite(int x, int y) {
    static int query_count = 0;
    x = find(x);
    y = find(y);
    if (x == y) {
      vector<int> mv = {0, x, 0};
      int bq = min(edge.at(x), size(x));
      edge.at(x)++;
      int aq = min(edge.at(x), size(x));
      mv.back() = aq - bq;
      qe += mv.back();
      memo[query_count] = mv;
      return query_count++;
    }
    if (d.at(x) > d.at(y)) swap(x, y);
    int bq = min(edge.at(x), size(x)) + min(edge.at(y), size(y));
    vector<int> mv = {1, x, y, d.at(y), 0};
    d.at(x) += d.at(y);
    edge.at(x) += edge.at(y) + 1;
    d.at(y) = x;
    int aq = min(edge.at(x), size(x));
    mv.back() = aq - bq;
    qe += mv.back();
    memo[query_count] = mv;
    return query_count++;
  }
  void remove(int qc) {
    auto v = memo[qc];
    assert(!v.empty());
    if (v.front() == 0) {
      assert(v.size() == 3);
      qe -= v.back();
      edge.at(v.at(1))--;
      return;
    }
    assert(v.size() == 5);
    int x = v.at(1), y = v.at(2), dd = v.at(3), qd = v.at(4);
    qe -= qd;
    d.at(y) = dd;
    edge.at(x) -= edge.at(y) + 1;
    d.at(x) -= d.at(y);
  }
  int get_qe() { return qe; }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d.at(find(x)); }
};
UnionFind uf(0);

void dfs(int now, int bf) {
  int aa = a.at(now), bb = b.at(now);
  int r = uf.unite(aa, bb);
  ans.at(now) = uf.get_qe();
  for (auto nx : gr.at(now)) {
    if (nx == bf) continue;
    dfs(nx, now);
  }
  uf.remove(r);
}

int main() {
  cin >> n;
  gr.resize(n);
  a.resize(n);
  b.resize(n);
  uf = UnionFind(n);
  ans.resize(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a.at(i) = x;
    b.at(i) = y;
  }
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gr.at(u).push_back(v);
    gr.at(v).push_back(u);
  }
  dfs(0, -1);
  rep2(i, 1, n) {
    if (i != 1) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}