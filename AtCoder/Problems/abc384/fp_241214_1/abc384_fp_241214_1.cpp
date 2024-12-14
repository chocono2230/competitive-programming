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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> d(26, 0);
  int pw = 1;
  rep(lv, 26) {
    vector<pair<int, ll>> memo(pw, {0, 0});
    rep(i, n) {
      int md = a.at(i) % pw;
      int ta = pw - md;
      if (ta == pw) ta = 0;
      memo.at(md).first++;
      memo.at(md).second += a.at(i);
      auto [mc, ms] = memo.at(ta);
      d.at(lv) += (ll)a.at(i) * mc + ms;
    }
    pw *= 2;
  }
  ll ans = 0;
  pw = 1;
  rep(i, 25) {
    ans += (d.at(i) - d.at(i + 1)) / pw;
    pw *= 2;
  }
  cout << ans << endl;
  return 0;
}