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
  vector<tuple<int, int, int>> aci(n);
  rep(i, n) {
    int a, c;
    cin >> a >> c;
    aci.at(i) = {a, c, i};
  }
  sort(ALL(aci));
  stack<pair<int, int>> stk;
  for (auto [a, c, i] : aci) {
    while (!stk.empty()) {
      auto [cx, ix] = stk.top();
      if (cx > c) {
        stk.pop();
        continue;
      }
      break;
    }
    stk.push({c, i});
  }
  vector<int> ans;
  while (!stk.empty()) {
    ans.push_back(stk.top().second);
    stk.pop();
  }
  sort(ALL(ans));
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}