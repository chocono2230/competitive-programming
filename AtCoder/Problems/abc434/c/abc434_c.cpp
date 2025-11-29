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
    int n, h;
    cin >> n >> h;
    vector<tuple<int, int, int>> tlu(n);
    rep(i, n) {
      int a, b, c;
      cin >> a >> b >> c;
      tlu.at(i) = {a, b, c};
    }
    bool ans = false;
    int ln = h, un = h, tn = 0;
    for (auto [t, l, u] : tlu) {
      int d = t - tn;
      ln = max(0, ln - d);
      un += d;
      if (ln > u || un < l) {
        ans = true;
        break;
      }
      ln = max(ln, l);
      un = min(un, u);
      tn = t;
    }
    if (!ans)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}