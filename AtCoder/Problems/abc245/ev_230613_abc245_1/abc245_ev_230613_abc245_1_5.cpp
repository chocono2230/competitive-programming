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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  vector<int> c(m);
  rep(i, m) cin >> c.at(i);
  vector<int> d(m);
  rep(i, m) cin >> d.at(i);
  map<int, int> mp;
  auto fc = [&](const vector<int> &v) -> void {
    for (auto now : v) {
      mp[now] = -1;
    }
  };
  fc(a);
  fc(b);
  fc(c);
  fc(d);
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  vector<tuple<int, int, int>> event;
  rep(i, n) {
    int aa = mp[a.at(i)], bb = mp[b.at(i)];
    event.push_back({-aa, -bb, 1});
  }
  rep(i, m) {
    int aa = mp[c.at(i)], bb = mp[d.at(i)];
    event.push_back({-aa, -bb, 0});
  }
  sort(ALL(event));

  map<int, int> co;
  for (auto [x, y, e] : event) {
    y *= -1;
    if (e == 0) {
      co[y]++;
      continue;
    }
    auto itr = co.lower_bound(y);
    if (itr == co.end()) {
      cout << "No" << endl;
      return 0;
    }
    itr->second--;
    if (itr->second == 0) {
      co.erase(itr);
    }
  }
  cout << "Yes" << endl;
  return 0;
}