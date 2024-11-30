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
  vector<int> x(m);
  rep(i, m) {
    cin >> x.at(i);
    x.at(i)--;
  }
  vector<int> a(m);
  rep(i, m) cin >> a.at(i);
  if (x.front() != 0) {
    cout << -1 << endl;
    return 0;
  }
  stack<pair<int, int>> stk;
  int bf = n;
  ll ans = 0;
  rrep(i, m) {
    stk.push({x.at(i), bf});
    int pos = x.at(i);
    int now = a.at(i);
    while (!stk.empty() && now != 0) {
      auto [begin, end] = stk.top();
      stk.pop();
      if (end - begin > now) {
        int p = begin + now;
        stk.push({p, end});
        end = p;
      }
      now -= end - begin;
      ans += (ll)(begin - pos + end - pos - 1) * (end - begin) / 2;
    }
    bf = x.at(i);
    if (now != 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (!stk.empty()) ans = -1;
  cout << ans << endl;
  return 0;
}