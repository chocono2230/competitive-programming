#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, w;
    cin >> n >> w;
    vector<int> c(n);
    rep(i, n) cin >> c.at(i);
    int w2 = 2 * w;
    vector<ll> m(w2, 0);
    rep(i, n) { m.at(i % w2) += c.at(i); }
    ll sum = 0;
    rep(i, w) sum += m.at(i);
    ll ans = sum;
    rep2(i, 1, 2 * w) {
      sum += m.at((i + w - 1) % w2);
      sum -= m.at(i - 1);
      ans = min(ans, sum);
    }
    cout << ans << endl;
  }
  return 0;
}