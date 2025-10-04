#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  string x, y;
  cin >> x >> y;
  string a = "Ocelot", b = "Serval", c = "Lynx";
  if (y == a) {
    cout << "Yes" << endl;
    return 0;
  }
  if (y == b) {
    if (x == b || x == c) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (y == c && x == c) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}