#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  list<pair<int, int>> v;
  v.push_back({-1, 0});
  rep(i, n) {
    int now = a.at(i);
    if (now == v.back().first)
      v.back().second++;
    else
      v.push_back({now, 1});
  }
  v.erase(v.begin());
  stack<pair<int, int>> stk;
  for (auto [a, b] : v) {
    b %= 4;
    if (b == 0) continue;
    if (!stk.empty()) {
      auto [c, d] = stk.top();
      if (a != c) {
        stk.push({a, b});
      } else {
        d += b;
        d %= 4;
        if (d == 0)
          stk.pop();
        else
          stk.top().second = d;
      }
    } else {
      stk.push({a, b});
    }
  }
  int ans = 0;
  while (!stk.empty()) {
    ans += stk.top().second;
    stk.pop();
  }
  cout << ans << endl;
  return 0;
}