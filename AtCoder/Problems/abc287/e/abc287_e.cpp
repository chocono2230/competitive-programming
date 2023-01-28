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
  vector<pair<string, int>> s(n);
  rep(i, n) cin >> s.at(i).first;
  rep(i, n) s.at(i).second = i;
  sort(ALL(s));
  vector<int> ans(n, 0);
  auto fc = [](const string &t, const string &s) -> int {
    rep(i, min(t.size(), s.size())) {
      if (t.at(i) != s.at(i)) return i;
    }
    return min(t.size(), s.size());
  };
  rep(i, n) {
    if (i != 0) ans.at(s.at(i).second) = fc(s.at(i).first, s.at(i - 1).first);
    if (i != n - 1)
      ans.at(s.at(i).second) =
          max(ans.at(s.at(i).second), fc(s.at(i).first, s.at(i + 1).first));
  }
  for (auto i : ans) cout << i << endl;
  return 0;
}