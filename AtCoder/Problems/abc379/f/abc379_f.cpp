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

const int INF = 1001001001;
using S = int;
S op(int l, int r) { return min(l, r); }
S e() { return INF; }

using T = int;
T opt(T l, T r) { return max(l, r); }
T et() { return 0; }

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> h(n);
  rep(i, n) {
    cin >> h.at(i);
    h.at(i)--;
  }
  vector qs(n, vector<pair<int, int>>());
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    qs.at(r).push_back({l, i});
  }

  vector<int> edge(n, -1);
  segtree<S, op, e> segs(n);
  rrep(i, n) {
    int now = h.at(i);
    S r = segs.prod(now, n);
    if (r != INF) {
      edge.at(now) = r;
    }
    segs.set(now, i);
  }

  vector<int> dp(n, 0);
  rrep(i, n) {
    int nx = edge.at(h.at(i));
    if (nx != -1) {
      dp.at(h.at(i)) = dp.at(h.at(nx)) + 1;
    }
  }

  segtree<T, opt, et> segt(h);
  vector<int> ans(q, 0);
  rrep(r, n) {
    for (auto [l, idx] : qs.at(r)) {
      T mx = segt.prod(l + 1, r + 1);
      ans.at(idx) = dp.at(mx);
    }
  }
  rep(i, q) cout << ans.at(i) << endl;
  return 0;
}