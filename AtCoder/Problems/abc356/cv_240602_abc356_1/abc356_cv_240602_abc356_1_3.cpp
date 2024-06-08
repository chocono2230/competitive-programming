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
  int n, m, pc;
  cin >> n >> m >> pc;
  vector cv(m, vector<int>());
  vector<bool> cc(m, false);
  rep(i, m) {
    int sz;
    cin >> sz;
    rep(j, sz) {
      int in;
      cin >> in;
      in--;
      cv.at(i).push_back(in);
    }
    char c;
    cin >> c;
    cc.at(i) = (c == 'o');
  }

  int ans = 0;
  rep(bit, 1 << n) {
    bool f = false;
    rep(i, m) {
      int now = 0;
      for (auto p : cv.at(i)) {
        now |= (1 << p);
      }
      int aa = (now & bit);
      int co = 0;
      rep(k, n) {
        if ((aa & (1 << k)) != 0) co++;
      }
      if ((co >= pc) ^ cc.at(i)) {
        f = true;
        break;
      }
    }
    if (!f) ans++;
  }
  cout << ans << endl;
  return 0;
}