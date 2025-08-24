#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  ll ans = 0;
  rep(i, n) ans += min(a.at(i), b.at(i));
  while (q--) {
    char c;
    int x, v;
    cin >> c >> x >> v;
    x--;
    ans -= min(a.at(x), b.at(x));
    if (c == 'A') {
      a.at(x) = v;
    } else {
      b.at(x) = v;
    }
    ans += min(a.at(x), b.at(x));
    cout << ans << endl;
  }
  return 0;
}