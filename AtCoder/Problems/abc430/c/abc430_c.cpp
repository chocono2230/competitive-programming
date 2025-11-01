#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  vector<int> v1(n + 1, 0), v2(n + 1, 0);
  rep(i, n) {
    if (s.at(i) == 'a')
      v1.at(i + 1)++;
    else
      v2.at(i + 1)++;
  }
  rep(i, n) {
    v1.at(i + 1) += v1.at(i);
    v2.at(i + 1) += v2.at(i);
  }
  ll ans = 0;
  rep(i, n) {
    int ai = lower_bound(ALL(v1), a + v1.at(i)) - v1.begin();
    int bi = lower_bound(ALL(v2), b + v2.at(i)) - v2.begin();
    int add = max(0, bi - ai);
    ans += add;
  }
  cout << ans << endl;
  return 0;
}