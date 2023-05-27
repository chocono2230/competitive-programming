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
  queue<int> q;
  rep(i, n) {
    if (tree.at(i).size() == 1) {
      q.push(i);
      break;
    }
  }
  vector<bool> er(n, false);
  vector<int> ans;
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    int cc = -1;
    for (auto nx : tree.at(now)) {
      if (er.at(nx)) continue;
      cc = nx;
      break;
    }
    ans.push_back(tree.at(cc).size());
    for (auto nx : tree.at(cc)) {
      if (nx == now) continue;
      for (auto nnx : tree.at(nx)) {
        if (nnx == cc) continue;
        if (er.at(nnx)) continue;
        q.push(nnx);
      }
      er.at(nx) = true;
    }
    er.at(now) = er.at(cc) = true;
  }
  sort(ALL(ans));
  rep(i, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}