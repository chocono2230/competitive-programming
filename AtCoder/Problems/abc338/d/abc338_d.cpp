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
  vector<int> x(m);
  rep(i, m) {
    cin >> x.at(i);
    x.at(i)--;
  }
  vector<ll> imos(n * 2 + 5, 0);
  ll base = 0;
  rep(i, m - 1) {
    int pos = x.at(i), nx = x.at(i + 1);
    int l = nx - pos;
    if (l < 0) l = nx + n - pos;
    int r = pos - nx;
    if (r < 0) r = pos + n - nx;
    int d = abs(l - r);
    base += min(l, r);
    // cerr << i << " " << l << " " << r << endl;
    if (d == 0) continue;
    if (l < r) {
      if (nx > pos) {
        imos.at(pos) += d;
        imos.at(nx) -= d;
      } else {
        imos.at(pos) += d;
        imos.at(nx + n) -= d;
      }
    } else {
      if (pos > nx) {
        // cerr << i << " " << pos << " " << nx << " " << d << endl;
        imos.at(nx) += d;
        imos.at(pos) -= d;
      } else {
        // cerr << i << " " << nx << " " << pos + n << " " << d << endl;
        imos.at(nx) += d;
        imos.at(pos + n) -= d;
      }
    }
  }
  // cerr << "TTTT" << endl;
  // rep(i, imos.size()) cerr << i << " " << imos.at(i) << endl;
  vector<ll> sum(n * 2 + 5, 0);
  ll now = 0;
  rep(i, imos.size()) {
    now += imos.at(i);
    sum.at(i) = now;
  }
  ll ans = 4e18;
  // cerr << base << endl;
  rep(i, n) {
    ll add = base + sum.at(i) + sum.at(i + n);
    // cerr << i << " " << add << endl;
    ans = min(ans, add);
  }
  cout << ans << endl;

  return 0;
}