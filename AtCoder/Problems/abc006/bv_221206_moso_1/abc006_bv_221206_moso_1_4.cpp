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
  if (n <= 3) {
    if (n == 3)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  vector<ll> v(n + 1, 0);
  v.at(3) = 1;
  rep2(i, 4, n + 1) {
    v.at(i) = v.at(i - 1) + v.at(i - 2) + v.at(i - 3);
    v.at(i) %= 10007;
  }
  cout << v.back() << endl;
  return 0;
}