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
int op(int x, int y) { return min(x, y); }
int e() { return INF; }

int main() {
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> v(n);
  map<ll, int> mp;
  rep(i, n) {
    ll a, b, c;
    cin >> a >> b >> c;
    mp[a] = -1;
    mp[b] = -1;
    mp[c] = -1;
    ll mn = min({a, b, c});
    ll mx = max({a, b, c});
    ll mid = -mn - mx + a + b + c;
    v.at(i) = {mn, mid, mx};
  }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  sort(ALL(v));
  segtree<int, op, e> seg(sz);
  int bfa = -1;
  vector<pair<int, int>> bc;
  v.push_back({INF, 0, 0});
  for (auto [aa, bb, cc] : v) {
    if (aa != bfa) {
      for (auto [bbb, ccc] : bc) {
        int b = mp[bbb], c = mp[ccc];
        int r = seg.prod(0, b);
        if (r < c) {
          cout << "Yes" << endl;
          return 0;
        }
      }
      for (auto [bbb, ccc] : bc) {
        int b = mp[bbb], c = mp[ccc];
        seg.set(b, op(seg.get(b), c));
      }
      bc.clear();
    }
    bfa = aa;
    bc.push_back({bb, cc});
  }
  cout << "No" << endl;

  return 0;
}