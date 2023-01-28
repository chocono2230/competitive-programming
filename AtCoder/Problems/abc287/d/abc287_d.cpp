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
  vector<bool> ans(t.size() + 1, false);
  bool x = false;
  auto cc = [&](int l, int r) -> bool {
    if (s.at(l) == '?' || t.at(r) == '?') return true;
    return s.at(l) == t.at(r);
  };
  rep(i, t.size()) {
    x |= !cc(s.size() - i - 1, t.size() - i - 1);
    ans.at(ans.size() - i - 2) = x;
  }
  x = false;
  rep(i, t.size()) {
    x |= !cc(i, i);
    ans.at(i + 1) = (x | ans.at(i + 1));
  }
  for (auto f : ans) {
    if (!f)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}