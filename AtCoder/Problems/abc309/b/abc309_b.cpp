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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  vector<string> ans = s;
  rep(z, 1) {
    int i = z, j = z;
    int chk = n - z - 1;
    if (chk < i) break;
    int f = 0;
    vector<char> vv;
    while (f != 4) {
      vv.push_back(s.at(i).at(j));
      // cerr << z << " " << i << " " << j << " " << f << " " << vv.back() <<
      // endl;
      if (f == 0) j++;
      if (f == 1) i++;
      if (f == 2) j--;
      if (f == 3) i--;
      if (f == 0 && j == chk) f++;
      if (f == 1 && i == chk) f++;
      if (f == 2 && j == z) f++;
      if (f == 3 && i == z) f++;
    }
    vv.push_back(vv.front());
    i = z, j = z;
    int idx = 0;
    f = 0;
    while (f != 4) {
      if (f == 0) j++;
      if (f == 1) i++;
      if (f == 2) j--;
      if (f == 3) i--;
      // cerr << i << " " << j << " " << vv.at(idx) << endl;
      ans.at(i).at(j) = vv.at(idx++);
      if (f == 0 && j == chk) f++;
      if (f == 1 && i == chk) f++;
      if (f == 2 && j == z) f++;
      if (f == 3 && i == z) f++;
    }
  }
  rep(i, n) cout << ans.at(i) << endl;
  return 0;
}