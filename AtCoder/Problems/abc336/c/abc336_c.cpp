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
  auto fc = [](ll x) -> string {
    string res;
    if (x == 0) return "0";
    while (x != 0) {
      ll p = x % 5;
      res.push_back('0' + p * 2);
      x /= 5;
    }
    reverse(ALL(res));
    return res;
  };
  ll n;
  cin >> n;
  n--;
  cout << fc(n) << endl;
  return 0;
}