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
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ps;
  for (int i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    int j = n / i;
    ps.push_back(i);
    if (j != n && j != i) ps.push_back(j);
  }
  sort(ALL(ps));
  vector<mint> memo(n + 1, 0);
  mint ans = 0;

  for (auto now : ps) {
    vector<bool> flg(now, false);
    rep(i, n) {
      if (s.at(i) == '.') flg.at(i % now) = true;
    }
    mint add = 1;
    rep(i, now) if (flg.at(i) == false) add *= 2;
    // cerr << now << " " << add.val() << " " << memo.at(now).val() << " "
    //      << (add - memo.at(now)).val() << endl;
    add += memo.at(now);
    ans += add;
    int pp = now + now;
    while (pp < memo.size()) {
      memo.at(pp) -= add;
      pp += now;
    }
  }
  // rep(i, n + 1) cerr << memo.at(i).val() << " ";
  // cerr << endl;
  cout << ans.val() << endl;
  return 0;
}