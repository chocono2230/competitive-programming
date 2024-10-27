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
  vector<int> p(n), q(n);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
    q.at(p.at(i)) = i;
  }
  // rep(i, 10) {
  //   auto nxp = p;
  //   rep(j, n) { nxp.at(j) = p.at(p.at(j)); }
  //   swap(p, nxp);
  //   rep(j, n) cerr << p.at(j) + 1 << " ";
  //   cerr << endl;
  // }
  vector db(60, vector<int>(n));
  rep(i, n) { db.at(0).at(i) = q.at(i); }
  rep(i, 60 - 1) {
    rep(j, n) { db.at(i + 1).at(j) = db.at(i).at(db.at(i).at(j)); }
  }
  vector<int> ans(n);
  rep(i, n) {
    int now = i;
    rep(j, 60) {
      if ((k & (1LL << j)) == 0) continue;
      now = db.at(j).at(now);
    }
    ans.at(i) = p.at(now);
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}