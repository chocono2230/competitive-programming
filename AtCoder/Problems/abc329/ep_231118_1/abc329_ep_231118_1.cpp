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
  string s, t;
  cin >> s >> t;
  queue<int> q;
  rep(i, n - m + 1) {
    bool f = false;
    rep(j, m) {
      if (s.at(i + j) != t.at(j)) f = true;
    }
    if (!f) q.push(i);
  }

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    rep(j, m) { s.at(now + j) = '#'; }
    rep2(d, 1, m) {
      if (d + now <= n - m) {
        bool f = false;
        bool p = false;
        rep(j, m) {
          if (s.at(now + d + j) != '#' && s.at(now + d + j) != t.at(j))
            f = true;
          if (s.at(now + d + j) != '#') p = true;
        }
        if (!f && p) q.push(now + d);
      }
      if (now - d >= 0) {
        d *= -1;
        bool f = false;
        bool p = false;
        rep(j, m) {
          if (s.at(now + d + j) != '#' && s.at(now + d + j) != t.at(j))
            f = true;
          if (s.at(now + d + j) != '#') p = true;
        }
        if (!f && p) q.push(now + d);
        d *= -1;
      }
    }
  }
  bool ans = string(n, '#') == s;
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}