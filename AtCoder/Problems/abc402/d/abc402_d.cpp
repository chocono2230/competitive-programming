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
  n *= 2;
  map<pair<int, int>, int> mp;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a *= 2;
    b *= 2;
    int d = b - a;
    int d2 = n - d;
    int t1 = a + d / 2;
    int t2 = b + d2 / 2;
    if (t2 > n) t2 -= n;
    if (t1 > t2) swap(t1, t2);
    mp[{t1, t2}]++;
  }
  ll ans = (ll)m * (m - 1) / 2;
  for (auto p : mp) {
    // cerr << p.first.first << " " << p.first.second << " " << p.second <<
    // endl;
    ans -= (ll)p.second * (p.second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}