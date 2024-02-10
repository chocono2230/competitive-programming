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
#include <atcoder/all>
using namespace atcoder;

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(m);
  rep(i, m) cin >> b.at(i);
  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(n);
  rep(i, n) { lsg.set(i, a.at(i)); }
  rep(i, m) {
    int pos = b.at(i);
    ll co = lsg.get(pos);
    lsg.set(pos, 0);
    lsg.apply(0, n, co / n);
    co %= n;
    if (co == 0) continue;
    int l = pos + 1;
    int r = pos + 1 + co;
    if (r <= n) {
      lsg.apply(l, r, 1);
    } else {
      lsg.apply(l, n, 1);
      int d = r - n;
      lsg.apply(0, d, 1);
    }
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << lsg.get(i);
  }
  cout << endl;
  return 0;
}