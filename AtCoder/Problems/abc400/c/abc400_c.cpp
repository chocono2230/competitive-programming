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
  ll n;
  cin >> n;
  ll ans = 0;
  ll pw = 2;
  rep(_i, 2) {
    ll t = n / pw;
    if (t < 0) break;
    ll p = max(0LL, (ll)sqrt(t) - 5);
    while (1) {
      if ((p + 1) * (p + 1) > t) break;
      p++;
    }
    ans += p;
    pw *= 2;
  }
  cout << ans << endl;
  return 0;
}