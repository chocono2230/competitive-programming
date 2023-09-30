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

struct S {
  int m1;
  int m0;
  int l1;
  int l0;
  int r1;
  int r0;
  int sz;
};

using F = int;

S op(S l, S r) {
  S res;
  res.m1 = max({l.m1, r.m1, l.r1 + r.l1});
  res.m0 = max({l.m0, r.m0, l.r0 + r.l0});
  res.l1 = l.l1;
  if (l.l1 == l.sz) {
    res.l1 += r.l1;
  }
  res.l0 = l.l0;
  if (l.l0 == l.sz) {
    res.l0 += r.l0;
  }
  res.r1 = r.r1;
  if (r.r1 == r.sz) {
    res.r1 += l.r1;
  }
  res.r0 = r.r0;
  if (r.r0 == r.sz) {
    res.r0 += l.r0;
  }
  res.sz = l.sz + r.sz;
  return res;
}

S mapping(F f, S s) {
  if (f == 0) return s;
  auto res = s;
  swap(res.m0, res.m1);
  swap(res.l0, res.l1);
  swap(res.r0, res.r1);
  return res;
}

F composition(F f, F g) { return f ^ g; }

S e() { return S{0, 0, 0, 0, 0, 0, 0}; }

F id() { return 0; }

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<S> v(n, S{0, 0, 0, 0, 0, 0, 0});
  rep(i, n) {
    if (s.at(i) == '1') {
      v.at(i).m1++;
      v.at(i).l1++;
      v.at(i).r1++;
    } else {
      v.at(i).m0++;
      v.at(i).l0++;
      v.at(i).r0++;
    }
    v.at(i).sz++;
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> lst(v);
  rep(i, q) {
    int c, l, r;
    cin >> c >> l >> r;
    l--;
    if (c == 1) {
      lst.apply(l, r, 1);
    } else {
      auto z = lst.prod(l, r);
      cout << z.m1 << endl;
    }
  }
  return 0;
}