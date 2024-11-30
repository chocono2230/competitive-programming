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
  vector<pair<int, int>> xa(m);
  rep(i, m) {
    cin >> xa.at(i).first;
    xa.at(i).first--;
  }
  rep(i, m) { cin >> xa.at(i).second; }
  sort(ALL(xa));
  if (xa.front().first != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0, co = 0, sum = 0;
  rep(i, m) {
    int now = xa.at(i).first;
    co += xa.at(i).second;
    sum += xa.at(i).second;
    if (sum > n) {
      cout << -1 << endl;
      return 0;
    }
    int nx = n;
    if (i != m - 1) nx = xa.at(i + 1).first;
    int d = nx - now;
    if (co < d) {
      cout << -1 << endl;
      return 0;
    }
    ans += (ll)(d - 1) * d / 2;
    co -= d;
    ans += co * d;
  }
  if (co != 0) ans = -1;
  cout << ans << endl;
  return 0;
}