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
  vector<int> v(10, 0);
  for (auto c : s) {
    v.at(c - '0')++;
  }
  ll now = -1;
  int ans = 0;
  while (1) {
    now++;
    string t = to_string(now * now);
    if ((int)t.size() > n) break;
    vector<int> w(10, 0);
    for (auto c : t) {
      w.at(c - '0')++;
    }
    w.at(0) += n - t.size();
    if (w == v) ans++;
  }
  cout << ans << endl;
  return 0;
}