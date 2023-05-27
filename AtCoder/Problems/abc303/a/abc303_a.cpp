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
  string s, t;
  cin >> s >> t;
  auto fc = [](char x, char y) -> bool {
    if (x == y) return true;
    if (x == '1' && y == 'l') return true;
    if (x == '0' && y == 'o') return true;
    swap(x, y);
    if (x == '1' && y == 'l') return true;
    if (x == '0' && y == 'o') return true;
    return false;
  };
  bool f = false;
  rep(i, n) {
    if (!fc(s.at(i), t.at(i))) f = true;
  }
  if (!f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}