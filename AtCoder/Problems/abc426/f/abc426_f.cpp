#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using S = pair<ll, int>;
using F = long long;

const S INF = S(8e18, 0);

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return S(f + x.first, x.second); }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  int n;
  cin >> n;
  vector<S> a(n);
  rep(i, n) cin >> a.at(i).first;
  rep(i, n) a.at(i).second = i;
  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(a);
  fenwick_tree<int> fw(n);
  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    ll ans = (ll)(r - l) * k;
    ans -= (ll)fw.sum(l, r) * k;
    while (1) {
      auto p = lsg.prod(l, r);
      if (p.first > k) break;
      ans -= k - p.first;
      fw.add(p.second, 1);
      lsg.set(p.second, S(8e18, p.second));
    }
    lsg.apply(l, r, -k);
    // rep(i, n) cerr << (lsg.get(i).first > 1e8 ? 0 : lsg.get(i).first) << " ";
    // cerr << endl;
    cout << ans << endl;
  }
  return 0;
}