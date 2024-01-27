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
  vector gr(2 * n, vector<int>());
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b) swap(a, b);
    gr.at(a).push_back(b);
  }
  auto dfs = [&](const auto &self, int now, int r) -> bool {
    if (now == r) return true;
    assert(gr.at(now).size() == 1);
    int nx = gr.at(now).front();
    if (now + 1 == nx) return self(self, nx + 1, r);
    if (nx >= r) return false;
    bool z = self(self, now + 1, nx);
    if (!z) return false;
    return self(self, nx + 1, r);
  };
  if (dfs(dfs, 0, 2 * n))
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}