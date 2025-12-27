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
  string s, t;
  cin >> s >> t;
  auto fc = [](char y, char x) {
    int a = x - '0';
    int b = y - '0';
    if (a <= b)
      return b - a;
    else
      return b + 10 - a;
  };
  int ans = 1001001001;
  rep(i, n - m + 1) {
    int add = 0;
    rep(j, m) { add += fc(s.at(i + j), t.at(j)); }
    ans = min(ans, add);
    // cerr << add << endl;
  }
  cout << ans << endl;
  return 0;
}