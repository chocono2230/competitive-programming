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
  ll k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, n) {
    cin >> x.at(i);
    x.at(i)--;
  }
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector db(60, vector<int>(n, 0));
  db.front() = x;
  rep(i, 60 - 1) {
    rep(j, n) { db.at(i + 1).at(j) = db.at(i).at(db.at(i).at(j)); }
  }
  auto ans = a;
  rep(i, 60) {
    if ((k & (1LL << i)) == 0) continue;
    auto nxans = ans;
    rep(j, n) { nxans.at(j) = ans.at(db.at(i).at(j)); }
    swap(ans, nxans);
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}