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
  string s, t;
  cin >> s >> t;
  vector<pair<int, int>> v;
  rep(i, s.size()) {
    if (s.at(i) == t.at(i)) continue;
    if (s.at(i) > t.at(i))
      v.push_back({0, i});
    else
      v.push_back({1, -i});
  }
  sort(ALL(v));
  cout << v.size() << endl;
  for (auto [p, q] : v) {
    if (p == 1) q *= -1;
    s.at(q) = t.at(q);
    cout << s << endl;
  }
  return 0;
}