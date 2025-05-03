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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> gr(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    gr.at(a).push_back(b);
    gr.at(b).push_back(a);
  }
  bool ans = false;
  int co = 0, st = 0;
  if (m != n) {
    cout << "No" << endl;
    return 0;
  }
  auto rc = [&](const auto &self, int now, int pr) -> void {
    co++;
    if (gr.at(now).size() != 2) return;
    for (auto nx : gr.at(now)) {
      if (nx == pr) continue;
      if (nx == st) {
        if (co == n) ans = true;
        return;
      }
      self(self, nx, now);
    }
  };
  rc(rc, 0, -1);
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}