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
  int n, q;
  cin >> n >> q;
  vector<int> pv(n), hv(n, 1);
  rep(i, n) pv.at(i) = i;
  int ans = 0;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int p, h;
      cin >> p >> h;
      p--;
      h--;
      if (hv.at(pv.at(p)) == 2) ans--;
      hv.at(pv.at(p))--;
      pv.at(p) = h;
      hv.at(pv.at(p))++;
      if (hv.at(pv.at(p)) == 2) ans++;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}