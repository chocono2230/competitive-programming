#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  vector<ll> v(10);
  v.at(0) = x;
  v.at(1) = y;
  rep2(i, 2, 10) {
    ll now = v.at(i - 1) + v.at(i - 2);
    string s = to_string(now);
    reverse(ALL(s));
    v.at(i) = stoll(s);
  }
  cout << v.back() << endl;
  return 0;
}