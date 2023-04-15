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
using mint = modint998244353;

int main() {
  mint now = 1;
  int qe;
  cin >> qe;
  queue<int> q;
  q.push(1);
  vector<mint> pw(600005, 1);
  rep2(i, 1, pw.size()) pw.at(i) = pw.at(i - 1) * 10;
  while (qe--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int in;
      cin >> in;
      now *= 10;
      now += in;
      q.push(in);
    }
    if (mode == 2) {
      mint p = pw.at(q.size() - 1);
      p *= q.front();
      now -= p;
      q.pop();
    }
    if (mode == 3) {
      cout << now.val() << endl;
    }
  }
  return 0;
}