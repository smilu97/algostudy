#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;

struct Pos {
  lld x, y, sz;
  int index;
  Pos() {}
  Pos(lld x, lld y, int index, lld sz): x(x), y(y), sz(sz), index(index) {}
  Pos move_by_pivot(const Pos &p) const {
    if (y < p.y) return Pos(p.x-x, p.y-y, index, sz);
    return Pos(x-p.x, y-p.y, index, sz);
  }
  lld ccw(const Pos &p) const {
    return x*p.y - y*p.x;
  }
  bool operator<(const Pos &p) const {
    lld tmp = ccw(p);
    if (tmp == 0) return sz > p.sz;
    return tmp < 0;
  }
};

lld n, n2;
Pos pos[4000];

lld make_pivot(const Pos &piv) {
  vector<Pos> ps(n2);
  int k = 0;
  for (int i = 0; i < n2; i++) {
    Pos mp = pos[i].move_by_pivot(piv);
    if (mp.y <= 0) continue;
    ps[k++] = mp;
  }
  ps.resize(k);
  sort(ps.begin(), ps.end());

  vector<bool> met(n, false);
  for (Pos &p: ps) {
    if (met[p.index]) p.sz *= -1;
    else met[p.index] = true;
  }
  sort(ps.begin(), ps.end());

  // printf("(%3d, %3d): ", piv.x, piv.y); for (lld i = 0; i < k; i++) printf("%lf ", atan2(ps[i].y, ps[i].x)); printf("\n");

  lld ans = piv.sz, sum = piv.sz;
  for (int i = 0; i < k; i++) {
    sum += ps[i].sz;
    ans = max(ans, sum);
  }
  return ans;
}

int main(void)
{
  scanf("%lld", &n); n2 = n << 1;
  for (int i = 0; i < n; i++) {
    lld x0, x1, y;
    scanf("%lld%lld%lld", &x0, &x1, &y);
    lld sz = abs(x1 - x0);
    pos[i<<1] = Pos(x0, y, i, sz);
    pos[(i<<1)+1] = Pos(x1, y, i, sz);
  }
  lld ans = 0;
  for (int i = 0; i < n2; i++) ans = max(ans, make_pivot(pos[i]));
  printf("%lld\n", ans);
}
