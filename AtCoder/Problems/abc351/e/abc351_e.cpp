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
  vector<int> p0x, p0y, p1x, p1y;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 2 == 0) {
      p0x.push_back({x + y});
      p0y.push_back({x - y});
    } else {
      x++;
      p1x.push_back({x + y});
      p1y.push_back({x - y});
    }
  }
  auto fc = [](vector<int> &v) {
    ll res = 0;
    sort(ALL(v));
    ll ss = 0;
    int co = 0;
    for (auto a : v) {
      res += (ll)a * co - ss;
      ss += a;
      co++;
    }
    return res;
  };
  ll ans = fc(p0x) + fc(p0y) + fc(p1x) + fc(p1y);
  cout << ans / 2 << endl;
  return 0;
}