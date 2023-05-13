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
  string s;
  cin >> s;
  ll n;
  cin >> n;
  string t;
  while (n != 0) {
    if (n % 2 == 1) {
      t.push_back('1');
      n--;
    } else
      t.push_back('0');
    n /= 2;
  }
  reverse(ALL(t));
  if (t.size() != s.size()) {
    if (t.size() < s.size())
      t = string(s.size() - t.size(), '0') + t;
    else
      s = string(t.size() - s.size(), '0') + s;
  }
  const ll INF = 1e18;
  vector dp(t.size() + 1, vector<ll>(2, -INF));
  dp.front() = {0, -INF};
  rep(i, t.size()) {
    int ni = i + 1;
    char sc = s.at(i), tc = t.at(i);
    int z = t.size() - i - 1;
    ll add = 1LL << z;
    if (sc == '1' || sc == '?') {
      if (tc == '1') {
        dp.at(ni).at(0) = dp.at(i).at(0) + add;
        dp.at(ni).at(1) = dp.at(i).at(1) + add;
      } else {
        if (sc == '1') dp.at(ni).at(0) = -INF;
        dp.at(ni).at(1) = dp.at(i).at(1) + add;
      }
    }
    if (sc == '0' || sc == '?') {
      if (tc == '1') {
        dp.at(ni).at(1) = max(dp.at(ni).at(1), dp.at(i).at(0));
        dp.at(ni).at(1) = max(dp.at(ni).at(1), dp.at(i).at(1));
      } else {
        dp.at(ni).at(0) = max(dp.at(ni).at(0), dp.at(i).at(0));
        dp.at(ni).at(1) = max(dp.at(ni).at(1), dp.at(i).at(1));
      }
    }
  }
  ll ans = max(dp.back().front(), dp.back().back());
  if (ans < 0) ans = -1;
  cout << ans << endl;
  return 0;
}