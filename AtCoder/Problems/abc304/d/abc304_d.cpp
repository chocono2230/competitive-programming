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

int main() {
  int w, h;
  cin >> w >> h;
  int n;
  cin >> n;
  vector<pair<int, int>> pq(n);
  rep(i, n) {
    int p, q;
    cin >> p >> q;
    pq.at(i) = {p, q};
  }
  int an;
  cin >> an;
  vector<int> a(an);
  rep(i, an) cin >> a.at(i);
  int bn;
  cin >> bn;
  vector<int> b(bn);
  rep(i, bn) cin >> b.at(i);
  b.push_back(h);
  a.push_back(w);

  vector<int> co(bn + 1, 0);
  vector<tuple<int, int, int>> ev;
  rep(i, n) { ev.push_back({pq.at(i).first, 1, pq.at(i).second}); }
  rep(i, an + 1) ev.push_back({a.at(i), 0, 0});
  sort(ALL(ev));
  int mx = 0, mn = 1001001001;
  set<int> use;
  for (auto [j, mode, i] : ev) {
    if (mode == 0) {
      int z = 0, nmx = 0, nmn = 1001001001;
      for (auto p : use) {
        // cerr << j << " " << p << " " << co.at(p) << endl;
        nmx = max(nmx, co.at(p));
        nmn = min(nmn, co.at(p));
        co.at(p) = 0;
        z++;
      }
      if (z != bn + 1) nmn = 0;
      mx = max(mx, nmx);
      mn = min(mn, nmn);
      use.clear();
      continue;
    }
    int idx = lower_bound(ALL(b), i) - b.begin();
    co.at(idx)++;
    use.insert(idx);
  }
  cout << mn << " " << mx << endl;
  return 0;
}