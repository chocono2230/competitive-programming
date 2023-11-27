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
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  rep2(a, 1, n + 1) {
    int m = k - a % k;
    if (m == k) m = 0;
    if ((m + m) % k != 0) continue;
    int p = n / k;
    if (m != 0 && n / k * k + m <= n) p++;
    ans += (ll)p * p;
  }
  cout << ans << endl;
  return 0;
}