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

using S = pair<ll, int>;
S op(S l, S r) { return max(l, r); }
S e() { return {0, -1}; }

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  segtree<S, op, e> seg(w);
  vector<pair<int, int>> rc(n);
  vector<int> memo(n, -1);
  vector<tuple<int, int, int>> qe(n);
  rep(i, n) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    rc.at(i) = {r, c};
    qe.at(i) = {r, c, i};
  }
  sort(ALL(qe));
  for (auto [r, c, idx] : qe) {
    auto mx = seg.prod(0, c + 1);
    auto now = seg.get(c);
    if (now.first >= mx.first + 1) continue;
    memo.at(idx) = mx.second;
    seg.set(c, {mx.first + 1, idx});
  }
  auto [mx, end] = seg.all_prod();
  cout << mx << endl;
  vector<int> mv;
  int i = h - 1, j = w - 1;
  int pos = end;
  auto fc = [&](int ni, int nj) {
    rep2(p, ni, i) mv.push_back(0);
    rep2(p, nj, j) mv.push_back(1);
    i = ni;
    j = nj;
  };
  while (pos != -1) {
    auto [ni, nj] = rc.at(pos);
    fc(ni, nj);
    pos = memo.at(pos);
  }
  fc(0, 0);
  reverse(ALL(mv));
  rep(i, mv.size()) {
    if (mv.at(i) == 0)
      cout << 'D';
    else
      cout << 'R';
  }
  cout << endl;
  return 0;
}