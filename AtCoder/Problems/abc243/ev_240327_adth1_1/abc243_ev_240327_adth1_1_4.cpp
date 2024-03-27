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
  vector<tuple<int, int, int>> cab(m);
  const ll INF = 1e18;
  vector wf(n, vector<ll>(n, INF));
  rep(i, n) wf.at(i).at(i) = 0;
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    wf.at(a).at(b) = wf.at(b).at(a) = c;
    cab.at(i) = {c, a, b};
  }
  rep(k, n) rep(i, n) rep(j, n) wf.at(i).at(j) =
      min(wf.at(i).at(j), wf.at(i).at(k) + wf.at(k).at(j));
  int ans = 0;
  for (auto [c, a, b] : cab) {
    if (c > wf.at(a).at(b)) {
      ans++;
      continue;
    }
    rep(k, n) {
      if (k == a || k == b) continue;
      if (wf.at(a).at(k) + wf.at(k).at(b) == c) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}