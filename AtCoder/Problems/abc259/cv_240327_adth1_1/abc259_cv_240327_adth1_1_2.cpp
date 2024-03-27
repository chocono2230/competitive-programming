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
  auto fc = [](const string &s) {
    vector<pair<char, int>> res;
    char x = s.front();
    int co = 1;
    rep2(i, 1, s.size()) {
      if (s.at(i) != x) {
        res.push_back({x, co});
        x = s.at(i);
        co = 0;
      }
      co++;
    }
    res.push_back({x, co});
    return res;
  };
  auto sv = fc(s);
  auto tv = fc(t);
  if (sv.size() != tv.size()) {
    cout << "No" << endl;
    return 0;
  }
  rep(i, sv.size()) {
    auto [s1, s2] = sv.at(i);
    auto [t1, t2] = tv.at(i);
    if (s1 != t1 || t2 < s2) {
      cout << "No" << endl;
      return 0;
    }
    if (s2 == t2) continue;
    if (s2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}