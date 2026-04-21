#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    if ((n % 2 == 1) || ((a + b) % 2 == 0)) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
    string ans;
    string s = string(n - 1, 'R') + "D" + string(n - 1, 'L') + "D";
    string t = string(n - 1, 'L') + "D" + string(n - 1, 'R') + "D";
    if (a == n - 1) {
      rep(i, n / 2 - 1) ans += s;
      rep(i, b / 2) ans += "DRUR";
      ans += "RD";
      int z = n / 2 - b / 2 - 1;
      rep(i, z) ans += "RURD";
    } else if (a % 2 == 0) {
      rep(i, a / 2) ans += s;
      rep(i, b / 2) ans += "DRUR";
      ans += "DR";
      int z = n / 2 - b / 2 - 1;
      rep(i, z) ans += "RURD";
      if (a != n - 2) {
        ans += "D";
        z = n / 2 - a / 2 - 1;
        rep(i, z) ans += t;
        ans.pop_back();
      }
    } else {
      rep(i, a / 2) ans += s;
      rep(i, b / 2) ans += "DRUR";
      ans += "RD";
      int z = n / 2 - b / 2 - 1;
      rep(i, z) ans += "RURD";
      ans += "D";
      z = n / 2 - a / 2 - 1;
      rep(i, z) ans += t;
      ans.pop_back();
    }
    if (ans.size() != n * n - 2) {
      cerr << ans << endl;
    }
    assert(ans.size() == n * n - 2);
    cout << ans << endl;
  }
  return 0;
}