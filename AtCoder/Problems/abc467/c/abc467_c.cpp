#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n - 1);
  rep(i, n - 1) cin >> b.at(i);
  auto fc = [&](int add) {
    auto c = a;
    int res = add;
    c.at(0) += add;
    rep2(i, 1, n) {
      int p = (c.at(i - 1) + c.at(i)) % 2;
      if (p != b.at(i - 1)) {
        c.at(i)++;
        res++;
      }
    }
    return res;
  };
  int ans = min(fc(0), fc(1));
  cout << ans << endl;
  return 0;
}