#include <cmath>
#include <iostream>
using namespace std;

#define MAX 987654321
#define FIO ios_base::sync_with_stdio(0), cin.tie(0);

typedef long long ll;
ll pos_cnt[60] = {1, 1, 2, 4, 8, 16};   // 각 자리수 마다 숫자의 개수
ll cnt[60] = {0, 1, 3, 8, 20, 48, 112}; // 각 자리수 마다 1의 개수
ll sum[60] = {0, 1};
// cnt[i-1] * 2 + cnt[i-1] == cnt[i]

ll A, B;

// 2진수로 표현했을 때 자릿수 리턴
ll getDigit(ll input) {
  if (input == 0)
    return 0;
  return 1 + getDigit(input / 2);
}

ll getSum(ll input) {
  ll res = 0;
  ll bound = 0;
  while (input) {
    if (bound > 0) {
      res += (input - bound) + 1;
      input -= bound;
    }
    ll inputDigit = getDigit(input);
    res += sum[inputDigit - 1];
    bound = (ll)pow(2, inputDigit - 1);
  }
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  ll s = sum[0] + sum[1];

  for (int i = 2; i <= 53; i++) {
    pos_cnt[i] = pos_cnt[i - 1] * 2;
    cnt[i] = cnt[i - 1] * 2 + pos_cnt[i - 1];
    s += cnt[i];
    sum[i] = s;
  }

  cin >> A >> B;

  cout << getSum(B) - getSum(A - 1) << "\n";
}
