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
  string t = "BCDEFGHIJKLMNOPQRSTUVWXYZ";
  string s;
  cin >> s;
  auto fc = [&](char x) {
    rep(i, s.size()) {
      if (s.at(i) == x) return i;
    }
    return (int)s.size();
  };
  int now = fc('A');
  int ans = 0;
  rep(i, t.size()) {
    int nx = fc(t.at(i));
    ans += abs(now - nx);
    now = nx;
  }
  cout << ans << endl;
  return 0;
}