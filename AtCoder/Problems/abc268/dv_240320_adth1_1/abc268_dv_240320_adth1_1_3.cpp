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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  int sz = 0;
  for (auto &ss : s) sz += ss.size();
  sz += s.size() - 1;
  set<string> se;
  rep(i, m) {
    string is;
    cin >> is;
    se.insert(is);
  }
  vector<int> order(n);
  rep(i, n) order.at(i) = i;
  do {
    vector<int> co(s.size() - 1, 0);
    auto rc = [&](const auto &self, int lv, int sum) -> bool {
      if (lv == co.size()) {
        string t;
        rep(i, n) {
          t += s.at(order.at(i));
          if (i != n - 1) t += string(1 + co.at(i), '_');
        }
        if (t.size() < 3 || t.size() > 16) return false;
        if (se.find(t) == se.end()) {
          cout << t << endl;
          return true;
        }
        return false;
      }
      bool res = false;
      rep(i, 18) {
        if (sum + i + sz > 16) break;
        co.at(lv) = i;
        res |= self(self, lv + 1, sum + i);
        if (res) return res;
      }
      return res;
    };
    if (rc(rc, 0, 0)) return 0;
  } while (next_permutation(ALL(order)));
  cout << -1 << endl;
  return 0;
}