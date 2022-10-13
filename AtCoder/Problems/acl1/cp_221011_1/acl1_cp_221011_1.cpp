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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  mcf_graph<int, ll> mcf(2 + n * m);
  const int INF = 1001001001;

  auto fc = [=](int i, int j) -> int { return i * m + j; };
  ll ans = 0;
  int co = 0;
  rep(i, n) rep(j, m) {
    if (i != n - 1 && s.at(i + 1).at(j) != '#') {
      mcf.add_edge(fc(i, j), fc(i + 1, j), 105, 0);
    }
    if (j != m - 1 && s.at(i).at(j + 1) != '#') {
      mcf.add_edge(fc(i, j), fc(i, j + 1), 105, 0);
    }
    if (s.at(i).at(j) == 'o') {
      mcf.add_edge(n * m, fc(i, j), 1, 0);
      ans += -i - j;
      co++;
    }
    if (s.at(i).at(j) != '#') {
      mcf.add_edge(fc(i, j), n * m + 1, 1, INF - i - j);
    }
  }
  // auto p = mcf.flow(n * m, n * m + 1, co);
  // cerr << p.first << " " << INF * co - p.second << endl;
  ans += (ll)INF * co - mcf.flow(n * m, n * m + 1, co).second;
  cout << ans << endl;
  return 0;
}