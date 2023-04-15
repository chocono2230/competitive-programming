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
  vector a(n, vector<int>(n, 0));
  vector b(n, vector<int>(n, 0));
  rep(i, n) rep(j, n) cin >> a.at(i).at(j);
  rep(i, n) rep(j, n) cin >> b.at(i).at(j);
  rep(_i, 4) {
    bool f = false;
    rep(i, n) rep(j, n) {
      if (a.at(i).at(j) == 1 && b.at(i).at(j) == 0) f = true;
    }
    if (!f) {
      cout << "Yes" << endl;
      return 0;
    }
    // rep(i, n) {
    //   rep(j, n) cout << a.at(i).at(j) << " ";
    //   cout << endl;
    // }
    // cout << endl;
    auto nx = a;
    rep(i, n) rep(j, n) nx.at(i).at(j) = a.at(n - j - 1).at(i);
    swap(a, nx);
  }
  cout << "No" << endl;
  return 0;
}