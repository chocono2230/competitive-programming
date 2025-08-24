#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<int> co(n, 0);
  rep(j, m) {
    vector<int> pv, nv;
    rep(i, n) {
      if (s.at(i).at(j) == '0')
        nv.push_back(i);
      else
        pv.push_back(i);
    }
    if (pv.size() > nv.size()) {
      for (auto now : nv) co.at(now)++;
    } else {
      for (auto now : pv) co.at(now)++;
    }
  }
  vector<int> ans;
  int mx = *max_element(ALL(co));
  rep(i, n) if (co.at(i) == mx) ans.push_back(i);
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}