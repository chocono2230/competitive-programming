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
  int x = 10000, y = 10000;
  rep(i, n) {
    int a, b;
    string c;
    cin >> a >> b >> c;
    x -= b;
    y -= a;
    if (c == "take") x += b - a;
  }
  cout << y - x << endl;
  return 0;
}