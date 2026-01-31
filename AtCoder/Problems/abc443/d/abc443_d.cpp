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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    vector<bool> chk(n, false);
    rep(i, n) { q.push({a.at(i), i}); }
    ll ans = 0;
    while (!q.empty()) {
      auto [c, i] = q.top();
      q.pop();
      if (chk.at(i)) continue;
      chk.at(i) = true;
      // cerr << i + 1 << " " << a.at(i) << " " << c << endl;
      ans += a.at(i) - c;
      if (i != 0 && !chk.at(i - 1)) {
        q.push({c + 1, i - 1});
      }
      if (i != n - 1 && !chk.at(i + 1)) {
        q.push({c + 1, i + 1});
      }
    }
    cout << ans << endl;
  }
  return 0;
}