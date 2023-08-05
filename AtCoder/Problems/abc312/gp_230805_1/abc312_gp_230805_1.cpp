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

int dfs(vector<vector<int>> &tree, int now, int bf, ll &ans) {
  int sum = 0;
  for (auto nx : tree.at(now)) {
    if (nx == bf) continue;
    int r = dfs(tree, nx, now, ans);
    ll add = (ll)sum * r;
    ans -= add;
    sum += r;
  }
  ans -= sum * (tree.size() - sum - 1);
  return sum + 1;
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

  ll ans = n;
  ans *= (n - 1);
  ans /= 2;
  ans *= (n - 2);
  ans /= 3;
  cerr << ans << endl;
  dfs(tree, 0, -1, ans);
  cout << ans << endl;
  return 0;
}