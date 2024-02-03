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
  int h, w, n;
  cin >> h >> w >> n;
  int i = 0, j = 0;
  vector<string> s(h, string(w, '.'));
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  int pidx = 2;
  rep(_i, n) {
    int nxpidx = pidx;
    if (s.at(i).at(j) == '.') {
      s.at(i).at(j) = '#';
      nxpidx = (nxpidx - 1 + 4) % 4;
    } else {
      s.at(i).at(j) = '.';
      nxpidx = (nxpidx + 1 + 4) % 4;
    }
    pidx = nxpidx;
    i += di[pidx];
    j += dj[pidx];
    i = (i + h) % h;
    j = (j + w) % w;
  }
  for (auto ss : s) cout << ss << endl;
  return 0;
}