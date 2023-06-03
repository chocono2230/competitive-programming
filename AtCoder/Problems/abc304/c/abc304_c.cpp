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
  ll n, d;
  cin >> n >> d;
  vector<pair<ll, ll>> xy(n);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }
  vector<bool> ans(n, false);
  queue<int> q;
  q.push(0);
  ans.at(0) = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    auto [i, j] = xy.at(now);
    rep(idx, n) {
      auto [ni, nj] = xy.at(idx);
      if (ans.at(idx)) continue;
      if ((i - ni) * (i - ni) + (j - nj) * (j - nj) <= d * d) {
        ans.at(idx) = true;
        q.push(idx);
      }
    }
  }
  for (auto f : ans) {
    if (f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}