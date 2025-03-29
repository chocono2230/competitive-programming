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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    rep(i, 2 * n) {
      cin >> a.at(i);
      a.at(i)--;
    }
    vector<int> pos(n, -1);
    vector<bool> ng(n, false);
    int ans = 0;
    rep(i, 2 * n) {
      int now = a.at(i);
      if (pos.at(now) == -1) {
        pos.at(now) = i;
        continue;
      }
      int prv = pos.at(now);
      if (prv == i - 1) {
        ng.at(now) = true;
        continue;
      }
      pair<int, int> pp(-1, -1);
      if (prv != 0 && !ng.at(a.at(prv - 1))) pp.first = a.at(prv - 1);
      if (prv != i - 2 && !ng.at(a.at(prv + 1))) pp.second = a.at(prv + 1);
      if (pp.first == a.at(i - 1) || pp.second == a.at(i - 1)) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}