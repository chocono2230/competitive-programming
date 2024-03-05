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
  vector<int> p(n);
  vector<int> p2q(n, 0);
  rep(i, n) {
    cin >> p.at(i);
    p.at(i)--;
  }
  vector<int> q(n);
  rep(i, n) {
    cin >> q.at(i);
    q.at(i)--;
    p2q.at(q.at(i)) = i;
  }
  vector<pair<int, int>> lr(n, {-1, -1});
  if (p.front() != 0) {
    cout << -1 << endl;
    return 0;
  }

  auto rc = [&](const auto &self, int pl, int pr, int ql, int qr) -> bool {
    // cerr << pl << " " << pr << " " << ql << " " << qr << endl;
    if (pr - pl != qr - ql) return false;
    int now = p.at(pl);
    int mpos = p2q.at(now);
    int ld = mpos - ql;
    if (mpos < ql || pr <= mpos) return false;
    if (ld != 0) {
      lr.at(now).first = p.at(pl + 1);
      auto r = self(self, pl + 1, pl + 1 + ld, ql, ql + ld);
      if (!r) return false;
    }
    int rd = qr - mpos - 1;
    if (rd != 0) {
      lr.at(now).second = p.at(pl + ld + 1);
      auto r = self(self, pl + ld + 1, pl + ld + 1 + rd, mpos + 1, qr);
      if (!r) return false;
    }
    return true;
  };
  auto r = rc(rc, 0, n, 0, n);
  if (!r) {
    cout << -1 << endl;
    return 0;
  }
  for (auto [a, b] : lr) cout << a + 1 << " " << b + 1 << endl;

  return 0;
}