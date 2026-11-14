#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  int l = -1, r = -1;
  rep(i, n) {
    if (a.at(i) != b.at(i)) {
      l = i;
      break;
    }
  }
  rrep(i, n) {
    if (a.at(i) != b.at(i)) {
      r = i;
      break;
    }
  }
  if (l == -1) {
    cout << "Yes" << endl;
    return 0;
  }
  if (l == r) {
    cout << "No" << endl;
    return 0;
  }
  bool ans = false;
  vector<int> c, d;
  rep2(i, l, r + 1) {
    c.push_back(a.at(i));
    d.push_back(b.at(i));
  }
  auto t = c;
  t.push_back(t.front());
  t.erase(t.begin());
  auto s = c;
  s.insert(s.begin(), c.back());
  s.pop_back();
  if (t == d || s == d)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}