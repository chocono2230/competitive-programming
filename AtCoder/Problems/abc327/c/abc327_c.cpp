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
  int n = 9;
  vector a(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a.at(i).at(j);
  rep(i, n) rep(j, n) a.at(i).at(j)--;
  bool ans = false;
  rep(i, n) {
    vector<int> p(n, 0);
    rep(j, n) { p.at(a.at(i).at(j)) = 1; }
    if (reduce(ALL(p)) != 9) ans = true;
  }
  rep(j, n) {
    vector<int> p(n, 0);
    rep(i, n) { p.at(a.at(i).at(j)) = 1; }
    if (reduce(ALL(p)) != 9) ans = true;
  }
  rep(i, 3) rep(j, 3) {
    int si = i * 3, sj = j * 3;
    vector<int> p(n, 0);
    rep(di, 3) rep(dj, 3) { p.at(a.at(si + di).at(sj + dj)) = 1; }
    if (reduce(ALL(p)) != 9) ans = true;
  }
  if (ans)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}