#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>

// 1000000000 1000000000 4999 10000

#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

long long X, Y, W, S;

long long sum = 0;

int main() {
  FIO;

  cin >> X >> Y >> W >> S;

  while (X != 0 || Y != 0) {
    // 대각선으로 가는 직진 루트가 존재할 때
    if (X > 0 && Y > 0) {
      // 한 블럭 건너는 루트로 2번 이동 < 대각선 이동
      // 이땐 대각선으로 이동할 필요가 없다.
      if (2 * W <= S) {
        sum += X * W + Y * W;
        X = 0, Y = 0;
      }
      // 대각선 직진 루트가 존재하고, 대각선이 더 효율적일 때
      else {
        long long b = (X > Y) ? Y : X;
        sum += b * S;
        X -= b;
        Y -= b;
      }
    }
    // 대각선으로 갈 수 없거나 대각선을 꺾어서 가는 루트가 존재할 때
    else {
      long long b = (X > Y) ? X : Y;
      if (W <= S) {

        sum += b * W;
      } else {
        if (b % 2 == 0) {

          sum += b * S;
        } else {

          sum += (b / 2) * 2 * S;
          sum += W;
        }
      }
      X = 0, Y = 0;
    }
  }

  // 9,223,372,036,854,775,807
  // 9,998,000,000,000

  cout << sum << "\n";
}