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

void dfs(vector<vector<int>> &tree, vector<int> &col, int now) {
  for (auto nx : tree.at(now)) {
    if (col.at(nx) != -1) continue;
    col.at(nx) = 1 - col.at(now);
    dfs(tree, col, nx);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<int> col(n, -1);
  col.front() = 0;
  dfs(tree, col, 0);

  while (q--) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    if (col.at(c) == col.at(d))
      cout << "Town" << endl;
    else
      cout << "Road" << endl;
  }
  return 0;
}