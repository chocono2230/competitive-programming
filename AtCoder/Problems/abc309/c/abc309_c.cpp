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
  int n, k;
  cin >> n >> k;
  ll sum = 0, now = 0;
  vector<pair<int, int>> ab(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    ab.at(i) = {a, b};
    sum += b;
  }
  if (sum <= k) {
    cout << 1 << endl;
    return 0;
  }
  sort(ALL(ab));
  for (auto [a, b] : ab) {
    sum -= b;
    now = a;
    if (sum <= k) {
      cout << now + 1 << endl;
      return 0;
    }
  }
  cout << now + 1 << endl;
  return 0;
}