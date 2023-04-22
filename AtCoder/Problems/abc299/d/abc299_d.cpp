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
  int z = 20;
  int l = 1, r = n;
  while (z--) {
    if (l + 1 == r) {
      cout << "! " << l << endl;
      break;
    }
    int mid = (l + r) / 2;
    cout << "? " << mid << endl;
    int x;
    cin >> x;
    if (x == 0)
      l = mid;
    else
      r = mid;
  }
  return 0;
}