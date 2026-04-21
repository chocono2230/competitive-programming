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
    string s, t;
    cin >> s >> t;
    const string T = "(xx)";
    auto fc = [=](string s) {
      string res;
      for (auto c : s) {
        res.push_back(c);
        auto p = res.substr(max(0, (int)res.size() - 4));
        if (p == T) {
          rep(_i, 4) res.pop_back();
          res.push_back('x');
          res.push_back('x');
        }
      }
      return res;
    };
    if (fc(s) == fc(t))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}