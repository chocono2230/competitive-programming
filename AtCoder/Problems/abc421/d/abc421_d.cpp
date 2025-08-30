#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  ll sr, sc, tr, tc;
  cin >> sr >> sc >> tr >> tc;
  ll n, m, l;
  cin >> n >> m >> l;
  vector<pair<char, int>> s(m), t(l);
  rep(i, m) {
    char s1;
    int a1;
    cin >> s1 >> a1;
    s.at(i) = {s1, a1};
  }
  rep(i, l) {
    char s1;
    int a1;
    cin >> s1 >> a1;
    t.at(i) = {s1, a1};
  }
  reverse(ALL(s));
  reverse(ALL(t));
  auto cp = [](ll &sr, ll &sc, char x, int y) {
    if (x == 'U') sr -= y;
    if (x == 'D') sr += y;
    if (x == 'L') sc -= y;
    if (x == 'R') sc += y;
  };
  ll ans = 0;
  while (!s.empty()) {
    auto [ss, a] = s.back();
    auto [tt, b] = t.back();
    // cerr << sr << " " << sc << " " << tr << " " << tc << endl;
    auto upd = [&]() {
      int mn = min(a, b);
      cp(sr, sc, ss, mn);
      cp(tr, tc, tt, mn);
      s.back().second -= mn;
      if (s.back().second == 0) s.pop_back();
      t.back().second -= mn;
      if (t.back().second == 0) t.pop_back();
    };
    if (sr == tr) {
      if (sc == tc) {
        if (ss == tt) {
          int mn = min(a, b);
          ans += mn;
        }
        upd();
        continue;
      }
      ll d = sc - tc;
      upd();
      if (ss == 'U' || ss == 'D') continue;
      if (tt == 'U' || tt == 'D') continue;
      ll nxd = sc - tc;
      if ((d < 0 && nxd >= 0) || (d > 0 && nxd <= 0)) {
        if (abs(d) % 2 == 0) ans++;
      }
    } else if (sc == tc) {
      ll d = sr - tr;
      upd();
      if (ss == 'L' || ss == 'R') continue;
      if (tt == 'L' || tt == 'R') continue;
      ll nxd = sr - tr;
      if ((d < 0 && nxd >= 0) || (d > 0 && nxd <= 0)) {
        if (abs(d) % 2 == 0) ans++;
      }
    } else {
      ll sr1 = sr, sc1 = sc, tr1 = tr, tc1 = tc;
      ll d = sc - tc;
      ll d2 = sr - tr;
      upd();
      ll nxd = sc - tc;
      ll nxd2 = sr - tr;
      if ((d < 0 && nxd >= 0) || (d > 0 && nxd <= 0)) {
        if ((d2 < 0 && nxd2 >= 0) || (d2 > 0 && nxd2 <= 0)) {
          if (abs(nxd) == abs(nxd2)) ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}