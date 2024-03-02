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
  pair<int, int> first;
  pair<int, int> second;
  S() {}
  S(pair<int, int> first, pair<int, int> second)
      : first(first), second(second) {}
};

S op(S l, S r) {
  if (l.first.first == 0) return r;
  if (r.first.first == 0) return l;
  vector<pair<int, int>> v(4);
  v.at(0) = l.first;
  v.at(1) = l.second;
  v.at(2) = r.first;
  v.at(3) = r.second;
  sort(ALL(v));
  S res({0, 0}, {0, 0});
  rrep(i, 4) {
    if (res.first.first == 0) {
      res.first = v.at(i);
      continue;
    }
    if (res.first.first == v.at(i).first) {
      res.first.second += v.at(i).second;
      continue;
    }
    if (res.second.first == v.at(i).first || res.second.first == 0) {
      res.second.first = v.at(i).first;
      res.second.second += v.at(i).second;
      continue;
    }
    break;
  }
  return res;
}

S e() { return S(); }

int main() {
  int n, q;
  cin >> n >> q;
  segtree<S, op, e> seg(n);
  rep(i, n) {
    int in;
    cin >> in;
    seg.set(i, S({in, 1}, {0, 0}));
  }
  while (q--) {
    int mode, x, y;
    cin >> mode >> x >> y;
    if (mode == 1) {
      x--;
      seg.set(x, S({y, 1}, {0, 0}));
    } else {
      x--;
      auto ans = seg.prod(x, y);
      cout << ans.second.second << endl;
    }
  }
  return 0;
}