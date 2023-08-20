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
  vector gr(n, vector<int>());
  rep(i, n) {
    int co;
    cin >> co;
    rep(j, co) {
      int in;
      cin >> in;
      in--;
      gr.at(i).push_back(in);
    }
  }

  vector<int> ans;
  vector<bool> chk(n, false);
  auto dfs = [&](auto self, int now) -> void {
    for (auto nx : gr.at(now)) {
      if (chk.at(nx)) continue;
      self(self, nx);
      chk.at(nx) = true;
    }
    ans.push_back(now);
  };
  dfs(dfs, 0);
  rep(i, ans.size() - 1) {
    if (i != 0) cout << " ";
    cout << ans.at(i) + 1;
  }
  cout << endl;
  return 0;
}