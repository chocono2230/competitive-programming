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
  vector a(n, vector(n, vector<int>(n, 0)));
  rep(i, n) rep(j, n) rep(k, n) cin >> a.at(i).at(j).at(k);
  vector sums(n, vector(n + 1, vector<ll>(n + 1, 0)));
  rep(i, n) {
    rep(j, n) rep(k, n) {
      sums.at(i).at(j + 1).at(k + 1) = a.at(i).at(j).at(k);
    }
    rep(j, n + 1) rep(k, n + 1) {
      if (j != 0 && k != 0)
        sums.at(i).at(j).at(k) -= sums.at(i).at(j - 1).at(k - 1);
      if (j != n) sums.at(i).at(j + 1).at(k) += sums.at(i).at(j).at(k);
      if (k != n) sums.at(i).at(j).at(k + 1) += sums.at(i).at(j).at(k);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int lx, rx, ly;
    cin >> lx >> rx >> ly;
    int ry, lz, rz;
    cin >> ry >> lz >> rz;
    lx--;
    ly--;
    lz--;
    ll ans = 0;
    rep2(i, lx, rx) {
      ans += sums.at(i).at(ry).at(rz);
      ans -= sums.at(i).at(ry).at(lz);
      ans -= sums.at(i).at(ly).at(rz);
      ans += sums.at(i).at(ly).at(lz);
    }
    cout << ans << endl;
  }
  return 0;
}