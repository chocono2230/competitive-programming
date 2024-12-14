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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> memo(n);
  ll ans = 0;
  rep(i, n) {
    int p = a.at(i) * 2;
    while (p % 2 == 0) p /= 2;
    ans += p;
  }

  auto rc = [&](const auto &self, int l, int r, bool flg) -> void {
    if (r - l <= 1) return;
    int ev = l, od = r;
    ll esum = 0, osum = 0;
    rep2(i, l, r) {
      if (flg ^ (a.at(i) % 2 == 0)) {
        memo.at(ev++) = a.at(i);
        esum += a.at(i);
      } else {
        od--;
        memo.at(od) = a.at(i);
        osum += a.at(i);
      }
    }
    if (esum == 0 && osum == 0) return;
    cerr << l << " " << r << " " << flg << " " << ev << " " << od << endl;
    rep2(i, l, r) { cerr << memo.at(i) << " "; }
    cerr << endl;
    if (!flg) {
      rep2(i, od, r) {
        ans += esum;
        ans += memo.at(i) * (ev - l);
      }
    } else {
      ll t = 0;
      rep2(i, l, ev) {
        ans += t;
        ans += (memo.at(i) + 1) * (i - l);
        t += memo.at(i);
      }
      t = 0;
      rep2(i, od, r) {
        ans += t;
        ans += (memo.at(i) + 1) * (i - od);
        t += memo.at(i);
      }
      rep2(i, od, r) memo.at(i)++;
    }
    cerr << ans << endl;
    rep2(i, l, r) {
      a.at(i) = memo.at(i);
      a.at(i) /= 2;
    }
    if (!flg) {
      self(self, l, od, false);
      self(self, od, r, true);
    } else {
      self(self, l, r, false);
    }
  };
  rc(rc, 0, n, false);
  cout << ans << endl;
  return 0;
}