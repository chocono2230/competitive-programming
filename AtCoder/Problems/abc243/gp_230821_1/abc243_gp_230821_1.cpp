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
    ll x;
    cin >> x;
    vector<ll> dp(2, 0);
    dp.back() = 1;
    ll now = 1, sum = 1;
    int bidx = 2;
    while (1) {
      now++;
      if (now * now * now * now > x) break;
      if (bidx * bidx <= now) {
        sum += dp.at(bidx);
        bidx++;
      }
      dp.push_back(sum);
    }

    ll rx = sqrt(x) - 3;
    while (1) {
      if ((rx + 1) * (rx + 1) > x) break;
      rx++;
    }

    ll ans = 0;
    for (ll i = 1; i < now; i++) {
      ans += (rx - i * i + 1) * dp.at(i);
    }
    cout << ans << endl;
  }
  return 0;
}