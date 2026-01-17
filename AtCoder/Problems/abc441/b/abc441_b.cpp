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
  int q;
  cin >> q;
  while (q--) {
    string in;
    cin >> in;
    int ans = 0;
    for (auto c : in) {
      bool ss = (find(ALL(s), c) != s.end());
      bool tt = (find(ALL(t), c) != t.end());
      if (ss && !tt) {
        ans = 1;
        break;
      }
      if (tt && !ss) {
        ans = 2;
        break;
      }
    }
    if (ans == 0)
      cout << "Unknown" << endl;
    else if (ans == 1)
      cout << "Takahashi" << endl;
    else
      cout << "Aoki" << endl;
  }
  return 0;
}