#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = unsigned long long;
using namespace std;

int main() {
  ll il, ir;
  cin >> il >> ir;
  vector<pair<ll, ll>> ans;
  auto rc = [&](const auto &self, ll l, ll r, ll tl, ll tr, int w) -> void {
    if (l == tl && r == tr) {
      ans.push_back({l, r});
      return;
    }
    ll mid = l + (1ULL << w);
    if (tl < mid) {
      self(self, l, mid, tl, min(tr, mid), w - 1);
    }
    if (mid < tr) {
      self(self, mid, r, max(tl, mid), tr, w - 1);
    }
  };
  rc(rc, 0, (1ULL << 60), il, ir, 59);
  cout << ans.size() << endl;
  for (auto p : ans) cout << p.first << " " << p.second << endl;

  return 0;
}