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
const F ID = 8e18;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<tuple<int, int, int, int>> rcli(n);
  rep(i, n) {
    int r, c, l;
    cin >> r >> c >> l;
    c--;
    rcli.at(i) = {r, c, l, i};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(w);
  sort(ALL(rcli), greater<tuple<int, int, int, int>>());
  vector<int> ans(n);
  for (auto [r, c, l, i] : rcli) {
    auto res = lsg.prod(c, c + l);
    if (res == INF) res = h + 1;
    // cerr << i + 1 << " " << res - 1 << endl;
    ans.at(i) = res - 1;
    lsg.apply(c, c + l, res - 1);
  }
  for (auto now : ans) cout << now << endl;
  return 0;
}