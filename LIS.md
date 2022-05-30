<h1>LIS (가장 긴 증가하는 부분 수열)</h1>

<h3>O(N^2) 코드 </h3>

<code>
  
    int arr[1005];
    
    int dp[1005];
  
    memset(dp, 1, sizeof(dp));
  
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
  
</code>
  
  <hr>
  
<h3>O(NlgN) 코드 </h3>

<code>
 
    int N;

    vector<int> vec;

    int lower_bound(int input)
    {
        int l = 0, r = vec.size(), mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (vec[mid] < input)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return r;
    }

    int main()
    {
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            int input;
            cin >> input;
            if (vec.empty())
            {
                vec.push_back(input);
            }
            else
            {
                int t = lower_bound(input);
                if (t == vec.size())
                {
                    vec.push_back(input);
                }
                else
                {
                    vec[t] = input;
                }
            }
        }
    }
  
</code>
  
<hr>

**참고**
https://jason9319.tistory.com/113
