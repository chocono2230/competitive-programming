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

int op(int l, int r) { return max(l, r); }
int e() { return 0; }

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int sz = 500005;
  segtree<int, op, e> seg(sz);
  int ans = 0;
  rep(i, n) {
    int now = a.at(i);
    int l = max(0, now - d);
    int r = min(sz - 1, now + d) + 1;
    int add = seg.prod(l, r) + 1;
    ans = max(ans, add);
    seg.set(now, op(seg.get(now), add));
  }
  cout << ans << endl;
  return 0;
}