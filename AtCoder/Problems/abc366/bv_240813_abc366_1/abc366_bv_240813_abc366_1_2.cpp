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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  int mx = 0;
  rep(i, n) { mx = max(mx, (int)s.at(i).size()); }
  rep(i, n) {
    while (s.at(i).size() != mx) {
      s.at(i).push_back('*');
    }
  }
  vector<string> ans(mx, "");
  rep(i, mx) {
    rrep(j, n) { ans.at(i).push_back(s.at(j).at(i)); }
    rrep(j, n) {
      if (ans.at(i).at(j) != '*') break;
      ans.at(i).pop_back();
    }
    cout << ans.at(i) << endl;
  }
  return 0;
}
