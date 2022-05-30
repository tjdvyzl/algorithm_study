<h1> lower_bound </h1>
<h3>찾으려는 key 값보다 크거나 같은 숫자가 처음으로 등장하는 idx를 리턴, 존재하지 않다면 end(vec.size()) 리턴 </h3>

<code>  
  
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
  
</code>

<hr>

<h1> upper_bound </h1>
<h3>찾으려는 key 값보다 큰 숫자가 처음으로 등장하는 idx를 리턴, 존재하지 않다면 end(vec.size()) 리턴</h3>
<code>
  
    int upper_bound(int input)
    { 
        int l = 0, r = vec.size(), mid;

        while (l < r)
        {
            mid = (l + r) / 2;

            if (vec[mid] <= input)
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
  
</code>


<hr>

<h1>algorithm 라이브러리 내장 함수 사용</h1>
<code>
  
    cout << lower_bound(3) << "\n";
    cout << upper_bound(3) << "\n";
    cout << lower_bound(vec.begin(), vec.end(), 3) - vec.begin() << "\n";
    cout << upper_bound(vec.begin(), vec.end(), 3) - vec.begin() << "\n";
  
</code>
