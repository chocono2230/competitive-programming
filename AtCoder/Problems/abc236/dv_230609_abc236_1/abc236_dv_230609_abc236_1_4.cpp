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

int dfs(const vector<vector<int>> &a, vector<int> &v, int lv) {
  if (lv == v.size()) {
    map<int, vector<int>> mp;
    rep(i, v.size()) { mp[v.at(i)].push_back(i); }
    int res = 0;
    for (auto &[p, q] : mp) {
      int mn = min(q.front(), q.back()), mx = max(q.front(), q.back());
      res ^= a.at(mn).at(mx);
    }
    return res;
  }
  if (v.at(lv) != -1) return dfs(a, v, lv + 1);
  int res = 0;
  rep(i, v.size()) {
    if (v.at(i) != -1 || i == lv) continue;
    v.at(i) = v.at(lv) = lv;
    res = max(res, dfs(a, v, lv + 1));
    v.at(i) = v.at(lv) = -1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  n *= 2;
  vector a(n, vector<int>(n, 0));
  rep(i, n) rep2(j, i + 1, n) {
    int in;
    cin >> in;
    a.at(i).at(j) = a.at(j).at(i) = in;
  }
  vector<int> v(n, -1);
  cout << dfs(a, v, 0) << endl;
  return 0;
}