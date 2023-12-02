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
  vector<string> p(n);
  rep(i, n) { cin >> p.at(i); }
  vector ss(n + 1, vector<ll>(n + 1, 0));
  rep(i, n + 1) rep(j, n + 1) {
    if (i != 0 && j != 0) {
      ss.at(i).at(j) -= ss.at(i - 1).at(j - 1);
      if (p.at(i - 1).at(j - 1) == 'B') ss.at(i).at(j)++;
    }
    if (i != n) ss.at(i + 1).at(j) += ss.at(i).at(j);
    if (j != n) ss.at(i).at(j + 1) += ss.at(i).at(j);
  }
  auto fc = [&](int y, int x) {
    ll h = y / n, w = x / n;
    ll hm = y % n, wm = x % n;
    ll res = ss.back().back() * h * w;
    res += h * ss.back().at(wm);
    res += w * ss.at(hm).back();
    res += ss.at(hm).at(wm);
    return res;
  };
  while (q--) {
    int a, b;
    cin >> a >> b;
    int c, d;
    cin >> c >> d;
    c++;
    d++;
    ll ans = fc(c, d);
    ans -= fc(a, d);
    ans -= fc(c, b);
    ans += fc(a, b);
    cout << ans << endl;
  }
  return 0;
}