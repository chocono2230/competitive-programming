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
  vector gr(n, vector<int>());
  vector indeg(n, 0);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    gr.at(x).push_back(y);
    indeg.at(y)++;
  }

  set<pair<int, int>> se;
  rep(i, n) { se.insert({indeg.at(i), i}); }
  vector<int> ans(n, -1);
  rep(i, n - 1) {
    auto itr = se.begin();
    auto nxitr = next(itr);
    // cerr << itr->first << " " << itr->second << endl;
    // cerr << nxitr->first << " " << nxitr->second << endl;
    if (itr->first != 0 || nxitr->first == 0) {
      // cerr << i << endl;
      cout << "No" << endl;
      return 0;
    }
    int now = itr->second;
    ans.at(now) = i;
    auto p = *se.begin();
    for (auto nx : gr.at(now)) {
      assert(se.find({indeg.at(nx), nx}) != se.end());
      // cerr << indeg.at(nx) << " " << nx << endl;
      se.erase({indeg.at(nx), nx});
      indeg.at(nx)--;
      se.insert({indeg.at(nx), nx});
    }
    se.erase(p);
    // cerr << endl;
  }
  // cerr << se.begin()->first << " " << se.begin()->second << endl;
  ans.at(se.begin()->second) = n - 1;
  cout << "Yes" << endl;
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}