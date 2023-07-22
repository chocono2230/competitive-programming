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
  int n, d;
  cin >> n >> d;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<bool> chk(d, false);
  rep(j, d) {
    bool f = false;
    rep(i, n) {
      if (s.at(i).at(j) == 'x') f = true;
    }
    if (!f) chk.at(j) = true;
  }
  chk.push_back(false);
  int now = 0, ans = 0;
  for (auto f : chk) {
    if (!f) {
      ans = max(ans, now);
      now = 0;
    } else
      now++;
  }
  cout << ans << endl;
  return 0;
}