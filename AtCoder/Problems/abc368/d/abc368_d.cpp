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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> tree(n, vector<int>());
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree.at(a).push_back(b);
    tree.at(b).push_back(a);
  }
  vector<bool> v(n, false);
  int st = 0;
  rep(i, k) {
    int in;
    cin >> in;
    in--;
    st = in;
    v.at(in) = true;
  }

  vector<int> flg(n, 0);

  auto rc = [&](const auto &self, int now, int bf) -> bool {
    bool res = v.at(now);
    for (auto nx : tree.at(now)) {
      if (nx == bf) continue;
      res |= self(self, nx, now);
    }
    if (res) flg.at(now) = 1;
    return res;
  };
  rc(rc, st, -1);
  cout << reduce(ALL(flg)) << endl;
  return 0;
}