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
  rep(i, 26) {
    stack<pair<bool, int>> stk;
    bool ss = false;
    rep(j, s.size()) {
      auto c = s.at(j);
      if (c == 'a' + i) {
        if (ss) {
          cout << "No" << endl;
          return 0;
        }
        ss = true;
        stk.push({true, j});
      }
      if (c == '(') {
        stk.push({false, j});
      }
      if (c == ')') {
        while (1) {
          auto [x, y] = stk.top();
          stk.pop();
          if (x) {
            ss = false;
          } else {
            break;
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}