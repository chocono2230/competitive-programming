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
  int n, q;
  cin >> n >> q;
  vector<int> ans;
  UnionFind_hv uf(n);
  rep(i, q) {
    int a, b, d;
    cin >> a >> b >> d;
    a--;
    b--;
    if (uf.same(a, b) && uf.diff(a, b) != d) continue;
    ans.push_back(i + 1);
    uf.unite(a, b, d);
  }
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}