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
  int h, w, n;
  cin >> h >> w >> n;
  string t;
  cin >> t;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  auto fc = [&](int si, int sj) {
    int i = si, j = sj;
    if (s.at(i).at(j) == '#') return false;
    for (auto c : t) {
      if (c == 'L') j--;
      if (c == 'R') j++;
      if (c == 'U') i--;
      if (c == 'D') i++;
      if (s.at(i).at(j) == '#') return false;
    }
    return true;
  };
  int ans = 0;
  rep(i, h) rep(j, w) {
    if (fc(i, j)) ans++;
  }
  cout << ans << endl;
  return 0;
}