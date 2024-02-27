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
  vector<int> q(n);
  rep(i, n) {
    int in;
    cin >> in;
    in--;
    q.at(in) = i;
  }
  int qe;
  cin >> qe;
  while (qe--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int ans = a;
    if (q.at(b) < q.at(a)) ans = b;
    cout << ans + 1 << endl;
  }
  return 0;
}