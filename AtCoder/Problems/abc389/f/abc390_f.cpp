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

S imxr = 0;
bool mxr(S x) { return x <= imxr; }
S imxl = 0;
bool mxl(S x) { return x < imxl; }

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> lr(n);
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    lr.at(i) = {l, r};
  }
  int q;
  cin >> q;
  vector<pair<int, int>> qi(q);
  rep(i, q) {
    int in;
    cin >> in;
    qi.at(i) = {in, i};
  }
  sort(ALL(qi));

  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(q + 2);
  rep(i, q) { lsg.set(i + 1, qi.at(i).first); }
  lsg.set(0, -INF);
  lsg.set(q + 1, INF);
  for (auto [l, r] : lr) {
    // rep2(i, 1, q + 1) cerr << lsg.get(i) << " ";
    // cerr << endl;
    imxl = l;
    imxr = r;
    int nl = lsg.max_right<mxl>(0);
    int nr = lsg.max_right<mxr>(0);
    // cerr << nl << " " << nr << endl;
    lsg.apply(nl, nr, 1);
  }
  // rep2(i, 1, q + 1) cerr << lsg.get(i) << " ";
  // cerr << endl;
  vector<int> ans(q);
  rep(i, q) { ans.at(qi.at(i).second) = lsg.get(i + 1); }
  for (auto now : ans) cout << now << endl;
  return 0;
}