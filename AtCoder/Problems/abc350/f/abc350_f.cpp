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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> next(s.size(), -1);
  vector<pair<int, int>> state(n, {-1, 0});
  rep(i, n - 1) state.at(i).first = i + 1;
  stack<int> stk;
  rep(i, n) {
    if (s.at(i) == '(') stk.push(i);
    if (s.at(i) == ')') {
      int p = stk.top();
      next.at(p) = i;
      next.at(i) = p;
      stk.pop();
    }
  }
  string ans;
  auto rc = [&](const auto &self, int now, bool flg) -> void {
    int bi = now;
    int ei = next.at(now);
    string t;
    int pp = 1;
    if (flg) pp = -1;
    char st = '(';
    char ed = ')';
    if (flg) swap(st, ed);
    assert(s.at(bi) == st);
    int i = now + pp;
    while (i != ei) {
      if (s.at(i) == st) {
        int z = next.at(i);
        self(self, z, !flg);
        i = z;
      } else {
        char add = s.at(i);
        if (flg) {
          if ('a' <= add && add <= 'z') {
            add = add - 'a' + 'A';
          } else {
            add = add - 'A' + 'a';
          }
        }
        ans.push_back(add);
      }
      i += pp;
    }
    return;
  };
  rep(i, s.size()) {
    if (s.at(i) == '(') {
      int idx = next.at(i);
      rc(rc, idx, true);
      i = idx;
    } else
      ans.push_back(s.at(i));
  }
  cout << ans << endl;
  return 0;
}