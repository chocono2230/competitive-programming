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
  vector<int> b(n, 0);
  rep2(i, 2, n) {
    b.at(i) = a.at(i) - a.at(i - 1);
    b.at(i) += b.at(i - 1);
    if (i != n - 1) b.at(i + 1) = b.at(i);
    i++;
  }
  // rep(i, n) cerr << b.at(i) << " ";
  // cerr << endl;
  auto fc = [&](int now) {
    int idx = upper_bound(ALL(a), now) - a.begin() - 1;
    int res = b.at(idx);
    if (idx % 2 == 1) {
      res += now - a.at(idx);
    }
    // cerr << now << " " << idx << " " << res << " " << b.at(idx) << endl;
    return res;
  };
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = fc(r) - fc(l);
    cout << ans << endl;
  }
  return 0;
}