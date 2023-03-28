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

struct UnionFind {
  vector<int> d;
  vector<int> mnn;
  vector<int> edge;
  UnionFind(int n) : d(n, -1), mnn(n), edge(n, 0) {
    mnn.resize(n);
    rep(i, n) { mnn.at(i) = i; }
  }
  int find(int x) {
    if (d.at(x) < 0) return x;
    return d.at(x) = find(d.at(x));
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d.at(x) > d.at(y)) swap(x, y);
    mnn.at(x) = min(mnn.at(x), mnn.at(y));
    d.at(x) += d.at(y);
    d.at(y) = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d.at(find(x)); }

  void adEdge(int u, int v) { edge.at(u) = v; }
  int ans(int x) {
    int ld = find(x);
    return mnn.at(ld);
  }

  void qe(int u, int v) {
    if (same(u, v)) return;
    int now = u;
    vector<int> z;
    while (1) {
      z.push_back(now);
      if (same(now, v)) break;
      now = mnn.at(find(now));
      now = edge.at(now);
    }
    rep(i, z.size() - 1) { unite(z.back(), z.at(i)); }
  }
};

int main() {
  int n;
  cin >> n;
  UnionFind uf(n);
  rep(i, n - 1) {
    int in;
    cin >> in;
    in--;
    uf.adEdge(i + 1, in);
  }
  int q;
  cin >> q;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      uf.qe(u, v);
    } else {
      int x;
      cin >> x;
      x--;
      cout << uf.ans(x) + 1 << endl;
    }
  }
  return 0;
}