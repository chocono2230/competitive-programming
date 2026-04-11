#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int t, x;
  cin >> t >> x;
  int bf = 1001001001;
  rep(i, t + 1) {
    int in;
    cin >> in;
    if (abs(bf - in) >= x) {
      cout << i << " " << in << endl;
      bf = in;
    }
  }
  return 0;
}