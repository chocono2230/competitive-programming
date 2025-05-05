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
  vector<tuple<int, int, int>> edges;
  rep(i, n) { edges.push_back({i + 1, i, -1}); }
  rep(i, m) {
    int l, r, s;
    cin >> l >> r >> s;
    l--;
    edges.push_back({r, l, -s});
    edges.push_back({l, r, s});
  }
  const ll INF = 1e18;
  vector<ll> d(n + 1, INF);
  d.at(n) = 0;
  auto fc = [&]() -> bool {
    bool res = false;
    for (auto [i, j, s] : edges) {
      ll nx = d.at(i) + s;
      if (nx < d.at(j)) {
        res = true;
        d.at(j) = nx;
      }
    }
    return res;
  };
  rep(i, n) fc();
  if (fc())
    cout << -1 << endl;
  else
    cout << -1 * d.front() << endl;

  return 0;
}