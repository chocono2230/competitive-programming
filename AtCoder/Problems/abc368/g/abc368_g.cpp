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

using S = pair<ll, ll>;
S op(S l, S r) {
  S res(0, 0);
  res.first = l.first + r.first;
  res.second = max(l.second, r.second);
  return res;
}
S e() { return {0, 0}; }

bool f(S x) { return x.first <= x.second; }

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> b(n);
  rep(i, n) cin >> b.at(i);
  segtree<S, op, e> as(n);
  auto ss = [&](int i) {
    S p(0, 0);
    p.first = a.at(i);
    if (b.at(i) == 1) {
      p.second = 0;
      as.set(i, p);
      return;
    }
    p.second = a.at(i) / (b.at(i) - 1);
    as.set(i, p);
  };
  rep(i, n) { ss(i); }

  int q;
  cin >> q;
  while (q--) {
    int mode, p, q;
    cin >> mode >> p >> q;
    if (mode == 1) {
      p--;
      a.at(p) = q;
      ss(p);
    }
    if (mode == 2) {
      p--;
      b.at(p) = q;
      ss(p);
    }
    if (mode == 3) {
      p--;
      ll now = 0;
      int pos = p;
      int end = q;
      while (pos != end) {
        if (now + a.at(pos) < now * b.at(pos)) {
          now *= b.at(pos);
          pos++;
          continue;
        }
        int nx = as.max_right<f>(pos);
        now += as.prod(pos, nx + 1).first;
        pos = nx + 1;
      }
      cout << now << endl;
    }
  }
  return 0;
}