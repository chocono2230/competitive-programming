#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> p(n);
  rep(i, n) p.at(i) = i + 1;
  do {
    bool ans = false;
    rep(i, n) {
      if (a.at(i) == -1) continue;
      if (a.at(i) != p.at(i)) ans = true;
    }
    if (!ans) {
      cout << "Yes" << endl;
      rep(i, n) {
        if (i != 0) cout << " ";
        cout << p.at(i);
      }
      cout << endl;
      return 0;
    }
  } while (next_permutation(ALL(p)));
  cout << "No" << endl;
  return 0;
}