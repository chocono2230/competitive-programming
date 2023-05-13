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
  string s, t;
  cin >> s >> t;
  set<char> se = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
  map<char, int> sm, tm;
  for (auto c : s) sm[c]++;
  for (auto c : t) tm[c]++;
  int as = sm['@'];
  int at = tm['@'];

  bool ans = false;
  rep(i, 26) {
    char now = i + 'a';
    if (se.find(now) != se.end()) {
      if (sm[now] < tm[now]) {
        as -= tm[now] - sm[now];
      } else {
        at -= sm[now] - tm[now];
      }
      if (at < 0 || as < 0) ans = true;
    } else {
      if (sm[now] != tm[now]) ans = true;
    }
  }
  if (!ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}