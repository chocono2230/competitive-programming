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

vector<pair<int, int>> ab;
int t;

int dfs(vector<int> &now, int lv, int z) {
  if (lv == now.size()) {
    if (z != t) return 0;
    for (auto [a, b] : ab) {
      if (now.at(a) == now.at(b)) return 0;
    }
    return 1;
  }

  int res = 0;
  if (now.size() - lv - 1 >= t - z) {
    rep(i, z) {
      now.at(lv) = i;
      res += dfs(now, lv + 1, z);
      now.at(lv) = -1;
    }
  }
  if (z != t) {
    now.at(lv) = z;
    res += dfs(now, lv + 1, z + 1);
    now.at(lv) = -1;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> t >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ab.push_back({a, b});
  }
  vector<int> now(n, -1);
  cout << dfs(now, 0, 0) << endl;
  return 0;
}