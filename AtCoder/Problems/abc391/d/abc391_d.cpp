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
  int n, w;
  cin >> n >> w;
  vector<pair<int, int>> xy(n);
  vector arr(w, vector<pair<int, int>>());
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    x--;
    xy.at(i) = {x, y};
    arr.at(x).push_back({y, i});
  }
  rep(i, w) sort(ALL(arr.at(i)));
  const int INF = 1001001001;
  vector<int> ans(n, INF);
  int now = 0;
  rep(i, n) {
    bool e = false;
    rep(j, w) {
      if (arr.at(j).size() == i) {
        e = true;
        break;
      }
      now = max(now, arr.at(j).at(i).first);
    }
    if (e) break;
    rep(j, w) { ans.at(arr.at(j).at(i).second) = now; }
  }
  int q;
  cin >> q;
  while (q--) {
    int t, a;
    cin >> t >> a;
    a--;
    if (ans.at(a) <= t)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}