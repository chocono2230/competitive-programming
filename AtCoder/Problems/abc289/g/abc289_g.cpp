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
  int n, m;
  cin >> n >> m;
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  vector<int> c(m);
  rep(i, m) cin >> c.at(i);
  sort(ALL(b), greater<int>());
  vector<ll> base(n + 1, 0);
  rep(i, n) { base.at(i + 1) = (ll)b.at(i) * (i + 1); }
  rep(i, n + 1) cerr << base.at(i) << " ";
  cerr << endl;

  int mxi = max_element(ALL(base)) - base.begin();
  vector<ll> dd;
  rep2(i, mxi, n + 1) { dd.push_back(base.at(mxi) - base.at(i)); }
  rep(i, dd.size()) cerr << dd.at(i) << " ";
  cerr << endl;
  vector<ll> ds(dd.size() + 1, 0);
  rep(i, dd.size()) ds.at(i + 1) = ds.at(i) + dd.at(i);
  vector<ll> ans(m, 0);
  rep(i, m) {
    auto itr = upper_bound(ALL(dd), c.at(i));
    if (itr == dd.begin()) {
      ans.at(i) = (ll)mxi * c.at(i) + base.at(mxi);
      continue;
    }
    itr--;
    int p = itr - dd.begin();
    cerr << i << " " << p << " " << mxi << " " << c.at(i) << endl;
    rep(j, n + 1) cerr << j * c.at(i) + base.at(j) << " ";
    cerr << endl;
    cerr << (ll)(p + mxi) * c.at(i) << " " << base.at(p + mxi) << " "
         << ds.at(p + 1) << endl;
    cerr << "----" << endl;
    ans.at(i) = (ll)(p + mxi) * c.at(i) + base.at(p + mxi) - ds.at(p);
  }
  rep(i, m) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}