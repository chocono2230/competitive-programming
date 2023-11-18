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
  s.push_back('$');
  map<char, int> mp;
  int now = 1;
  rep2(i, 1, s.size()) {
    if (s.at(i) != s.at(i - 1)) {
      mp[s.at(i - 1)] = max(now, mp[s.at(i - 1)]);
      now = 0;
    }
    now++;
  }
  int ans = 0;
  for (auto p : mp) ans += p.second;
  cout << ans << endl;
  return 0;
}