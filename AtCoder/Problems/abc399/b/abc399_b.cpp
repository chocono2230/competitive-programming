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
  vector<int> p(n);
  rep(i, n) cin >> p.at(i);
  vector<pair<int, int>> pi(n);
  rep(i, n) pi.at(i) = {p.at(i), i};
  sort(ALL(pi), greater<pair<int, int>>());
  vector<int> ans(n, -1);
  int now = 1;
  rep(i, n) {
    if (i != 0 && pi.at(i).first != pi.at(i - 1).first) {
      now = i + 1;
    }
    ans.at(pi.at(i).second) = now;
  }
  for (auto now : ans) cout << now << endl;
  return 0;
}