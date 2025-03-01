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
  int n, q;
  cin >> n >> q;
  vector<int> pos(n);
  rep(i, n) pos.at(i) = i;
  vector<int> mv(n);
  rep(i, n) mv.at(i) = i;
  vector<int> rmv(n);
  rep(i, n) rmv.at(i) = i;
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      pos.at(a) = rmv.at(b);
    }
    if (mode == 2) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      int ma = rmv.at(a);
      int mb = rmv.at(b);
      swap(mv.at(ma), mv.at(mb));
      swap(rmv.at(a), rmv.at(b));
    }
    if (mode == 3) {
      int in;
      cin >> in;
      in--;
      cout << mv.at(pos.at(in)) + 1 << endl;
    }
  }
  return 0;
}