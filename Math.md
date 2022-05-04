# 소수
<pre>
    1과 자기자신으로만 나누어지는 수
    약수가 2개인 수
    2부터 N-1까지의 수로 나누어지지 않는 수     
</pre>

**소수 판정법**

<pre>
    합성수 N에서 1을 제외한 가장 작은 약수는 n^(1/2)이하 이다.
    
    합성수 N에서 1을 제외한 가장 작은 약수를 x라고 하자. 
    N/x 또한 1이 아닌 N의약수이기 때문에 x <= (N/x)이다.
    우변의 분모 x를 좌변으로 옮기면 x^2 <= N이므로 x <= N^(1/2)이다.
</pre>

<p>
  합성수 N에서 1을 제외한 가장 작은 약수는 N^(1/2)이하 이다.
  즉, <strong>2부터 N^(1/2)까지의 수로 나누어지지 않으면 소수이다.</strong>
</p>

**sqrt는 쓰면 안된다. (실수의 저장/연산 과정에서 반드시 오차가 발생할 수 밖에 없다. sqrt는 실수 연산이기 때문에 오차가 발생할 수 있다.)**

<code>

    vector<int> sieve(int n)
    {
        vector<int> primes;
        vector<bool> state(n + 1, true);
        state[1] = false;
        for (int i = 2; i <= n; i++)
        {
            if (!state[i])
                continue;
            for (int j = 2 * i; j <= n; j += i)
                state[j] = false;
        }
        for (int i = 2; i <= n; i++)
        {
            if (state[i])
                primes.push_back(i);
        }
        return primes;
    }
    
</code>

<div style="font-size:200%">
    수학적으로 개선할 부분이 있다. <br>
    위 코드에서 i가 4까지 다 돌았다고 가정하자. <br>
    2~36까지 {4,6,8 ... }, {6,9,12 ... } {4, 8, 12 ... } 각 합성수들이 false로 걸러져 있다.<br>
    그리고 i가 5일 때 15, 20, 25, 30, 35를 false로 만들 차례이다. <br>
    그런데 이 5의 배수들을 보면 이미 합성수로 판정이 되어있는 값들이 많다.<br>
    25와 35만 아직 true고 나머지는 false이다. 그리고 i가 5까지 걸치는 과정에서 소수인 2와 3을 걸쳤다.<br>
    이 말은 자연스럽게 5보다 작은 소인수를 가지는 합성수들은 이미 걸러졌다는 의미이다.<br>
    25를 보자. 25보다 작은 5의 배수를 보면 10 = 2 x 5, 15 = 3 x 5, 20 = 4 x 5이다. 얘네들은 각각 2, 3, 4로<br>
    나누어 떨어지고, 다른 말로 표현하면 이들은 5보다 더 작은 소인수가 존재한다는 의미이다.<br>
    즉, 커서가 5인 지금 신경을 쓰지 않더라도 이전에 다른 커서에서 이미 false로 바뀌었다는 의미이고,<br>
    5^2 = 25부터 false로 바꿔나가면 된다.
</div>
<br>


<code>
// 시간 복잡도 O(NlglgN)

vector<int> sieve(int n)
{
    vector<int> primes;

    // 자료형을 bool인 배열로 둔다면 시간이 꽤 느려진다.
    // 그 이유는 bool은 true와 false로 저장하는 자료형인데 정확한 크기는 char처럼 1byte이다.
    // 밑에처럼 벡터로 선언한다면 bool 한 칸이 1byte가 아니라 1bit만 차지하도록 최적화가 이루어진다.
    // 그래서 공간도 8배 적게 쓰고, cache hit rate가 올라가서 시간도 빨라진다.
    // 즉, state를  int 배열이나 bool 배열로 선언하기 보단 vector로 선언하면 더 효율적이다.

    vector<bool> state(n + 1, true);
    state[1] = false;
    for (int i = 2; i * i <= n; i++) // i * i가 n보다 커지게 되면 더 이상 아무 값도 바뀌지 않는다.
    {
        if (!state[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            state[j] = false;
    }
    for (int i = 2; i <= n; i++)
    {
        if (state[i])
            primes.push_back(i);
    }
    return primes;
}
</code>

# 최대공약수


# 연립합동방정식


# 이항계수

![excel-function-per-com-02](https://user-images.githubusercontent.com/76881971/166615138-6d1c0274-11f7-42d8-acce-858d55e59c19.png)

![1_SSZ5d73vC2R7srpdjcVqxg](https://user-images.githubusercontent.com/76881971/166615468-279d04ab-a54a-401d-aa22-88e85dc0de04.png)

## n-1 C r-1 + n-1 C r = n C r

<code>
    const int C = 10007;

    int dp[1005][1005];

    int f(int n, int r)
    {
        if (n == r)
            return 1;
        if (r == 0)
            return 1;
        if (dp[n][r] > 0)
            return dp[n][r];
        return dp[n][r] = (f(n - 1, r - 1) % C + f(n - 1, r)) % C;
    }
</code>

# 거듭제곱

<code>
    int p(int n, int k) {

        if (k == 0)
            return 1;


        int temp = p(n, k / 2);

        int r = 1LL * temp * temp;

        // k가 홀수일 
        if (k % 2)
             r = 1LL * r * n % C;

        return r;
    }
</code>

# 행렬(Matrix)
