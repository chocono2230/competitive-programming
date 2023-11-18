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
  vector<set<int>> ms(n);
  rep(i, n) {
    int in;
    cin >> in;
    in--;
    ms.at(i).insert(in);
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (ms.at(a).size() > ms.at(b).size()) {
      swap(ms.at(a), ms.at(b));
    }
    for (auto i : ms.at(a)) {
      ms.at(b).insert(i);
    }
    ms.at(a).clear();
    cout << ms.at(b).size() << endl;
  }
  return 0;
}