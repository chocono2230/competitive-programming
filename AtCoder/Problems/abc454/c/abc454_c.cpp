#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
  }
  vector<bool> chk(n, false);
  auto dfs = [&](const auto &self, int now) -> void {
    chk.at(now) = true;
    for (auto nx : gr.at(now)) {
      if (chk.at(nx)) continue;
      self(self, nx);
    }
  };
  dfs(dfs, 0);
  int ans = 0;
  rep(i, n) if (chk.at(i)) ans++;
  cout << ans << endl;
  return 0;
}