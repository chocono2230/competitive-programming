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
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = s;
  reverse(ALL(t));
  string st = s + t;
  auto z = z_algorithm(st);
  auto rz = z_algorithm(t + s);
  cerr << st << endl;
  cerr << t + s << endl;
  rep(k, 2 * n) {
    int p = z.at(z.size() - k - 1);
    int q = rz.at(rz.size() - k - 1);
    cerr << p << " " << q << endl;
  }
  return 0;
}