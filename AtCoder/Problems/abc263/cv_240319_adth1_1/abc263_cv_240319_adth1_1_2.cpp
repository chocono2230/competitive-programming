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
  vector<int> v;
  auto rc = [&](const auto &self) -> void {
    if (v.size() == n) {
      rep(i, n) {
        if (i != 0) cout << " ";
        cout << v.at(i);
      }
      cout << endl;
      return;
    }
    int z = n - v.size() - 1;
    int now = 0;
    if (v.size() > 0) now = v.back();
    rep2(i, now + 1, m + 1) {
      if (i + z > m) break;
      v.push_back(i);
      self(self);
      v.pop_back();
    }
  };
  rc(rc);
  return 0;
}