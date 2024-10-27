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
  int n = 8;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector table(n, vector<bool>(n, false));
  rep(i, n) {
    rep(j, n) {
      if (s.at(i).at(j) == '.') continue;
      rep(k, n) table.at(i).at(k) = true;
      rep(k, n) table.at(k).at(j) = true;
    }
  }
  int ans = 0;
  rep(i, n) rep(j, n) if (!table.at(i).at(j)) ans++;
  cout << ans << endl;
  return 0;
}