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
  int n, k, x;
  cin >> n >> k >> x;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<string> p;
  vector<int> v(k);
  auto rc = [&](const auto &self, int lv) -> void {
    if (lv == k) {
      string ans;
      rep(i, k) { ans += s.at(v.at(i)); }
      p.push_back(ans);
      return;
    };
    rep(i, n) {
      v.at(lv) = i;
      self(self, lv + 1);
    }
  };
  rc(rc, 0);
  sort(ALL(p));
  cout << p.at(x - 1) << endl;
  return 0;
}