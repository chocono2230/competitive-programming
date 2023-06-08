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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a.at(i).at(j);
  vector<string> ans(h);
  rep(i, h) rep(j, w) {
    int now = a.at(i).at(j);
    if (now == 0)
      ans.at(i).push_back('.');
    else
      ans.at(i).push_back('A' + (now - 1));
  }
  for (auto s : ans) cout << s << endl;
  return 0;
}