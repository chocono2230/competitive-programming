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

unsigned long z = 202306305;

unsigned long xor128() {
  static unsigned long x = 123456789, y = 362436069, w = 64813216;
  unsigned long t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "argc error "
         << " " << argc << endl;
    exit(1);
  }
  z = stoi(argv[1]);
  cerr << "Random Seed : " << z << endl;
  int co = stoi(argv[2]);
  rep(_i, 10) xor128();
  rep(i, co) { cout << xor128() % INT_MAX << endl; }
  return 0;
}