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
  int a;
  cin >> a;
  ll n;
  cin >> n;

  ll ans = 0;
  string ns = to_string(n);
  auto rc = [&](const auto &self, string s) -> void {
    if (s.size() > ns.size()) return;
    if (s != "") {
      ll now = stoll(s);
      if (now > n) return;
      string p;
      ll t = now;
      while (t != 0) {
        p.push_back('0' + t % a);
        t /= a;
      }
      auto r = p;
      reverse(ALL(r));
      if (s.back() != '0' && p.front() != '0' && r == p) {
        ans += now;
      }
    }
    // cerr << s << endl;

    rep(i, 10) {
      string nx = to_string(i);
      nx += s;
      nx += to_string(i);
      self(self, nx);
    }
  };
  rc(rc, "");
  rep(i, 10) { rc(rc, to_string(i)); }
  cout << ans << endl;
  return 0;
}