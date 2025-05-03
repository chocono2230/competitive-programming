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

struct UnionFind_hv {
  vector<int> d;
  vector<ll> weight;
  UnionFind_hv(int n) : d(n, -1), weight(n, 0) {}
  int find(int x) {
    if (d.at(x) < 0) return x;
    int ret = find(d.at(x));
    weight.at(x) += weight.at(d.at(x));
    return d.at(x) = ret;
  }
  ll get_weight(int x) {
    find(x);
    return weight.at(x);
  }
  ll diff(int x, int y) { return weight.at(y) - weight.at(x); }
  bool unite(int x, int y, ll w) {
    w += weight.at(x);
    w -= weight.at(y);
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d.at(x) > d.at(y)) swap(x, y), w = -w;
    d.at(x) += d.at(y);
    d.at(y) = x;
    weight.at(y) = w;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d.at(find(x)); }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind_hv uf(n + 1);
  rep(i, m) {
    int l, r, s;
    cin >> l >> r >> s;
    l--;
    if (uf.same(l, r)) {
      if (uf.diff(l, r) != s) {
        cout << -1 << endl;
        return 0;
      }
    }
    uf.unite(l, r, s);
  }

  rep(i, n) {
    int j = i + 1;
    if (!uf.same(i, j)) {
      uf.unite(i, j, 1);
    } else {
        }
  }
  ll ans = uf.diff(0, n);
  cout << ans << endl;
  return 0;
}