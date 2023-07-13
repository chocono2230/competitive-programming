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
  vector<int> a(n, 0);
  rep2(i, 1, n) cin >> a.at(i);
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  int ok = 0, ng = *max_element(ALL(a)) + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    auto fc = [&]() -> bool {
      auto dfs = [&](auto self, int now, int bf) -> int {
        int res = 0;
        for (auto nx : tree.at(now)) {
          if (nx == bf) continue;
          res += self(self, nx, now);
        }
        return max(0, res - 1) + (a.at(now) >= mid ? 1 : 0);
      };
      auto r = dfs(dfs, 0, -1);
      return r != 0;
    };
    if (fc())
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << endl;
  return 0;
}