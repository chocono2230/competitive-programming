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
  set<string> se;
  vector v = {'H', 'D', 'C', 'S'};
  vector v2 = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  set<char> s1, s2;
  for (auto i : v) s1.insert(i);
  for (auto i : v2) s2.insert(i);
  bool f = false;
  rep(i, n) {
    string s;
    cin >> s;
    se.insert(s);
    if (s1.find(s.at(0)) == s1.end()) f = true;
    if (s2.find(s.at(1)) == s2.end()) f = true;
  }
  f |= (se.size() != n);
  if (!f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}