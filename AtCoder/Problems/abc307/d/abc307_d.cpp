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
  string s;
  cin >> s;
  stack<char> stk;
  int co = 0;
  for (auto c : s) {
    if (c == '(') {
      co++;
      stk.push(c);
      continue;
    }
    if (c != ')' || co == 0) {
      stk.push(c);
      continue;
    }
    co--;
    while (1) {
      auto cc = stk.top();
      stk.pop();
      if (cc == '(') break;
    }
  }
  string ans;
  while (!stk.empty()) {
    ans.push_back(stk.top());
    stk.pop();
  }
  reverse(ALL(ans));
  cout << ans << endl;
  return 0;
}