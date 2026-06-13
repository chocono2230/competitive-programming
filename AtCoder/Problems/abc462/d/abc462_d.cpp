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

struct S {
  long long value;
  int size;
};
using F = long long;

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  int n, d;
  cin >> n >> d;
  vector<S> in(1000005, {0, 1});
  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(in);
  ll ans = 0;
  rep(i, n) {
    int s, t;
    cin >> s >> t;
    int p = t - s - d + 1;
    if (p <= 0) continue;
    ans += lsg.prod(s, s + p).value;
    lsg.apply(s, s + p, 1);
  }
  cout << ans << endl;

  return 0;
}