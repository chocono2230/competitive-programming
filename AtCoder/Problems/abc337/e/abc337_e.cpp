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
  int m = 0;
  rep(i, 10) {
    if ((1 << (i + 1)) < n) continue;
    m = (i + 1);
    break;
  }
  cout << m << endl;
  rep(i, m) {
    vector<int> o;
    rep(j, n) {
      if ((j & (1 << i)) != 0) o.push_back(j);
    }
    cout << o.size();
    rep(j, o.size()) { cout << " " << o.at(j) + 1; }
    cout << endl;
  }
  string s;
  cin >> s;
  int bans = 0;
  rep(i, s.size()) {
    if (s.at(i) == '1') bans |= (1 << i);
  }
  int ans = bans + 1;
  cout << ans << endl;
  return 0;
}