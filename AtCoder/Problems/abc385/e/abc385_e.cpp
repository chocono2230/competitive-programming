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
  int ans = 0;
  rep(i, n) {
    vector<int> sz;
    for (auto now : tree.at(i)) {
      sz.push_back(tree.at(now).size() - 1);
    }
    sort(ALL(sz));
    rep(j, sz.size()) {
      if (sz.at(j) == 0) continue;
      int nw = 1;
      nw += sz.size() - j;
      nw += (sz.size() - j) * sz.at(j);
      // cerr << i + 1 << " " << j << " " << nw << endl;
      ans = max(ans, nw);
    }
  }
  cout << n - ans << endl;
  return 0;
}