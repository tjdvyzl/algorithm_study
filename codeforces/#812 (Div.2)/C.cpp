#include <iostream>
using namespace std;
#include <string.h>
#include <vector>

int tc;

vector<int> vec; // 제곱수들 저장

int arr[200005];

bool v[200005];

int main() {

  for (int i = 0; i * i <= 200000; i++) {
    vec.push_back(i * i);
  }

  cin >> tc;

  while (tc--) {
    memset(arr, 0, sizeof(arr));
    memset(v, false, sizeof(v));

    int n;
    cin >> n;

    int bound = -1;

    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] > 2 * (n - 1)) {
        bound = i - 1;
        break;
      }
    }

    bound = (bound == -1) ? vec.size() - 1 : bound;

    for (int i = n - 1; i >= 0; i--) {
      if (v[i])
        continue;
      int t = bound;
      while (t >= 0) {
        if (vec[t] - i >= n)
          t--;
        else
          break;
      }

      for (int e = t; e >= 0; e--) {
        if (vec[e] - i <= 0 || v[vec[e] - i])
          continue;
        arr[i] = vec[e] - i;
        arr[vec[e] - i] = i;
        v[vec[e] - i] = true;
        v[i] = true;
        break;
      }
    }

    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
}