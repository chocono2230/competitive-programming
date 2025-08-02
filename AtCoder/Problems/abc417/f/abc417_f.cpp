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
using mint = modint998244353;

struct S {
  mint value;
  int size;
};

struct F {
  mint value;
  bool flg;
};

const F ID(0, true);

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
  if (f.flg != ID.flg) x.value = f.value * x.size;
  return x;
}
F composition(F f, F g) { return (f.flg == ID.flg ? g : f); }
F id() { return ID; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<S> v(n, {0, 1});
  rep(i, n) { v.at(i) = S(a.at(i), 1); }
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    l--;
    mint sum = seg.prod(l, r).value;
    mint nx = sum / (r - l);
    F f(nx, false);
    seg.apply(l, r, f);
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << seg.get(i).value.val();
  }
  cout << endl;
  return 0;
}