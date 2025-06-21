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
  int n, q;
  cin >> n >> q;
  vector<bool> t(n, false);
  int co = 0;
  rep(i, q) {
    int in;
    cin >> in;
    in--;
    if (!t.at(in)) {
      co++;
      if (in != 0 && t.at(in - 1)) co--;
      if (in != n - 1 && t.at(in + 1)) co--;
    } else {
      co--;
      if (in != 0 && t.at(in - 1)) co++;
      if (in != n - 1 && t.at(in + 1)) co++;
    }
    cout << co << endl;
    t.at(in) = !t.at(in);
  }
  return 0;
}