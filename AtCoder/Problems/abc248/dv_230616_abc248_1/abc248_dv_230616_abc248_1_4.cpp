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
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  int q;
  cin >> q;
  vector<int> ans(q, 0);
  vector ql(n, vector<pair<int, int>>());
  vector qr(n, vector<pair<int, int>>());
  rep(i, q) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;
    ql.at(l).push_back({x, i});
    qr.at(r).push_back({x, i});
  }
  vector<int> now(n + 1, 0);
  rep(i, n) {
    for (auto [x, idx] : ql.at(i)) {
      ans.at(idx) -= now.at(x);
    }
    now.at(a.at(i))++;
    for (auto [x, idx] : qr.at(i)) {
      ans.at(idx) += now.at(x);
    }
  }
  rep(i, q) cout << ans.at(i) << endl;
  return 0;
}