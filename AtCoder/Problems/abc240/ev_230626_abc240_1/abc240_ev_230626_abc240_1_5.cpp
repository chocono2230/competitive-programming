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

int sz = 0;
pair<int, int> dfs(vector<vector<int>> &tree, vector<pair<int, int>> &ans,
                   int now, int bf) {
  if (tree.at(now).size() == 1 && bf != -1) {
    ans.at(now) = {sz, sz};
    sz++;
    return {sz - 1, sz - 1};
  }
  int mn = 1001001001, mx = 0;
  for (auto nx : tree.at(now)) {
    if (nx == bf) continue;
    auto r = dfs(tree, ans, nx, now);
    mn = min(mn, r.first);
    mx = max(mx, r.second);
  }
  ans.at(now) = {mn, mx};
  return {mn, mx};
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<pair<int, int>> ans(n);
  dfs(tree, ans, 0, -1);
  for (auto [a, b] : ans) cout << a + 1 << " " << b + 1 << endl;
  return 0;
}