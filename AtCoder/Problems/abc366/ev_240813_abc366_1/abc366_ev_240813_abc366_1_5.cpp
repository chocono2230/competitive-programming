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
  int n, d;
  cin >> n >> d;
  vector<int> x(n), y(n);
  rep(i, n) {
    int ix, iy;
    cin >> ix >> iy;
    x.at(i) = ix;
    y.at(i) = iy;
  }
  sort(ALL(x));
  sort(ALL(y));

  int sz = 4000100;
  int c = sz / 2;
  vector<ll> vx(sz, 0), vy(sz, 0);
  auto fc = [&](vector<int> &x, vector<ll> &vx) {
    ll sum = 0;
    rep(i, n) { sum += abs((x.at(i) + c) - 0); }
    int idx = 0;
    rep(i, vx.size()) {
      vx.at(i) = sum;
      while (idx != (int)x.size()) {
        if ((x.at(idx) + c) != i) break;
        idx++;
      }
      int p = n - idx;
      int q = idx;
      sum -= p;
      sum += q;
    }
  };
  fc(x, vx);
  fc(y, vy);
  sort(ALL(vy));
  ll ans = 0;
  rep(i, sz) {
    ll z = (ll)d - vx.at(i);
    int co = upper_bound(ALL(vy), z) - vy.begin();
    ans += co;
  }
  cout << ans << endl;
  return 0;
}