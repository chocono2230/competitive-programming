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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) {
    cin >> a.at(i);
    a.at(i)--;
  }
  vector<int> b(m);
  rep(i, m) {
    cin >> b.at(i);
    b.at(i)--;
  }
  vector gr(n, vector<int>());
  rep(i, m) {
    gr.at(a.at(i)).push_back(b.at(i));
    gr.at(b.at(i)).push_back(a.at(i));
  }
  vector<int> d(n, -1);
  auto dfs = [&](const auto &self, int now) -> bool {
    bool res = false;
    for (auto nx : gr.at(now)) {
      if (d.at(nx) == -1) {
        d.at(nx) = 1 - d.at(now);
        res |= self(self, nx);
      } else {
        if (d.at(nx) != 1 - d.at(now)) {
          return true;
        }
      }
    }
    return res;
  };
  rep(i, n) {
    if (d.at(i) == -1) {
      d.at(i) = 0;
      auto r = dfs(dfs, i);
      if (r) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}