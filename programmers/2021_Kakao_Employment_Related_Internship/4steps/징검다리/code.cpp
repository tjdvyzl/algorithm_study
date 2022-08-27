#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
  int answer = 0;

  rocks.push_back(distance);

  sort(rocks.begin(), rocks.end());

  int lo = 1, hi = distance;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int cnt = 0;         // 제거한 바위의 수
    int current_pos = 0; // 현재 지
    for (int i = 0; i < rocks.size(); i++) {
      if (rocks[i] - current_pos < mid)
        cnt++;
      else
        current_pos = rocks[i];
    }
    if (cnt <= n) {
      answer = max(answer, mid);
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  return answer;
}
