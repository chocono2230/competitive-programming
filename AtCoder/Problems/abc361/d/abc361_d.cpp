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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int sz = 1;
  rep(i, n + 2) sz *= 3;
  const int INF = 1001001001;
  vector<int> dp(sz, INF);
  auto cc = [&](const char x) {
    if (x == 'B') return 1;
    if (x == 'W') return 2;
    return 0;
  };
  auto fc = [&](const string &state) {
    int res = 0;
    rep(i, state.size()) {
      res *= 3;
      res += cc(state.at(i));
    }
    return res;
  };
  auto rfc = [&](int now) {
    string res;
    while ((int)res.size() != n + 2) {
      int m = now % 3;
      if (m == 0)
        res.push_back('?');
      else if (m == 1)
        res.push_back('B');
      else
        res.push_back('W');
      now /= 3;
    }
    reverse(ALL(res));
    return res;
  };
  string p = s;
  p += "??";
  queue<int> q;
  dp.at(fc(p)) = 0;
  q.push(fc(p));
  while (!q.empty()) {
    auto ns = q.front();
    q.pop();
    auto state = rfc(ns);
    // cerr << ns << " " << state << endl;
    int idx = -1;
    rep(i, n + 2) {
      if (state.at(i) == '?') {
        idx = i;
        break;
      }
    }
    rep(i, n + 1) {
      if (i == idx - 1 || i == idx || i == idx + 1) continue;
      swap(state.at(i), state.at(idx));
      swap(state.at(i + 1), state.at(idx + 1));
      int nxs = fc(state);
      if (dp.at(nxs) == INF) {
        dp.at(nxs) = dp.at(ns) + 1;
        q.push(nxs);
      }
      swap(state.at(i), state.at(idx));
      swap(state.at(i + 1), state.at(idx + 1));
    }
  }
  t += "??";
  auto as = fc(t);
  int ans = dp.at(as);
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}