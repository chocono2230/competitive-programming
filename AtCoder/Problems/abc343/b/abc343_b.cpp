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
  vector a(n, vector<int>(n));
  rep(i, n) rep(j, n) cin >> a.at(i).at(j);
  rep(i, n) {
    vector<int> ans;
    rep(j, n) {
      if (a.at(i).at(j) == 1) ans.push_back(j);
    }
    rep(j, ans.size()) {
      if (j != 0) cout << " ";
      cout << ans.at(j) + 1;
    }
    cout << endl;
  }
  return 0;
}