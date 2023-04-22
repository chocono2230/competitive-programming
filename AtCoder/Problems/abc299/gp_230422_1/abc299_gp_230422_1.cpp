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
  vector<int> a(n);
  vector<pair<int, int>> mx(m, {1, 1});
  rep(i, n) {
    cin >> a.at(i);
    a.at(i)--;
    mx.at(a.at(i)).first = i;
    mx.at(a.at(i)).second = a.at(i);
  }
  sort(ALL(mx));
  int mxi = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  rep(i, mx.at(mxi).first + 1) { q.push({a.at(i), i}); }
  int l = 0, r = mx.at(mxi).first + 1;
  mxi = 1;
  vector<int> ans;
  vector<bool> flg(m, false);
  while (!q.empty()) {
    auto [now, idx] = q.top();
    // cerr << now + 1 << " " << idx << endl;
    q.pop();
    if (idx < l) continue;
    if (flg.at(now)) continue;
    // cerr << now << " " << idx << " " << mx.at(mxi - 1).second << endl;
    ans.push_back(now);
    l = idx;
    flg.at(now) = true;
    if (mxi != m && now == mx.at(mxi - 1).second) {
      int pr = r;
      while (mxi != m) {
        r = mx.at(mxi).first + 1;
        mxi++;
        if (!flg.at(mx.at(mxi - 1).second)) break;
      }
      if (mxi == m) r = n;
      rep2(i, pr, r) { q.push({a.at(i), i}); }
    }
  }
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}