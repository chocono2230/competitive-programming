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
  int n, m;
  cin >> n >> m;
  vector a(m, vector<int>(n));
  rep(i, m) rep(j, n) {
    cin >> a.at(i).at(j);
    a.at(i).at(j)--;
  }

  int ans = 0;
  rep(p, n) rep2(q, p + 1, n) {
    bool f = false;
    rep(i, m) rep(j, n - 1) {
      if (a.at(i).at(j) == p && a.at(i).at(j + 1) == q) f = true;
      if (a.at(i).at(j) == q && a.at(i).at(j + 1) == p) f = true;
      if (f) goto SKIP;
    }
  SKIP:
    if (!f) ans++;
  }
  cout << ans << endl;
  return 0;
}