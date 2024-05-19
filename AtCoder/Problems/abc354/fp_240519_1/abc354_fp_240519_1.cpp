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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    const int INF = 1001001001;
    int lis = 0;
    auto fc = [&]() {
      vector<int> res(n, -1), mns(n, INF);
      rep(i, n) {
        int now = a.at(i);
        int idx = lower_bound(ALL(mns), now) - mns.begin();
        res.at(i) = idx;
        lis = max(lis, idx + 1);
        mns.at(idx) = now;
      }
      return res;
    };
    auto l = fc();
    rep(i, n) a.at(i) *= -1;
    reverse(ALL(a));
    auto r = fc();
    reverse(ALL(r));
    vector<int> ans;
    rep(i, n) {
      if (l.at(i) + r.at(i) + 1 == lis) ans.push_back(i);
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) {
      if (i != 0) cout << " ";
      cout << ans.at(i) + 1;
    }
    cout << endl;
  }
  return 0;
}