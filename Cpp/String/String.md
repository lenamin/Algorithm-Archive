# String 


### [숫자처럼 정렬해야 하는 문자열 처리 문제](https://www.acmicpc.net/problem/2870) 정리
문자열 속에 섞여 있는 숫자들을 추출해서 이를 숫자 기준으로 정렬 (비내림차순) 하는 문제

#### 1. 사용자 정의 정렬 함수 `cmp()` 
- 숫자는 문자열로 표현되어 있어도 숫자처럼 정렬되도록 해야 함 
- 기준은 1) 길이가 짧으면 작은 숫자 2) 길이 같을 때는 사전 순 비교 

  ```cpp
  bool cmp(string &a, string &b) {
      // 길이 기준으로 정렬 (숫자가 작을수록 길이가 짧음)
      if (a.size() != b.size()) return a.size() < b.size();

      // 길이가 같으면 사전 순 비교 (문자열 "123" < "456" 그대로 성립)
      return a < b;
  }
  ```
<br><br>

#### 2. `stoi` 사용했을 때 runtime error (out_of_range) 발생한 이유 
- 문제조건을 놓쳤다 : 100~200자까지 들어올 수 있음. `long long` 타입을 사용해도 담을 수 없는 범위임 
- 그래서 `1` 에서 정리한 함수를 정의해 문자열을 숫자처럼 정렬할 수 있도록 함 


<br><br>

#### 3. 숫자의 앞자리 0 처리방법 
- 내가 구현한 방식 (비어있지 않고, 기존 ts가 0이면 현재 숫자로 덮어씀)
  ```cpp
  if (isdigit(c)) {
    if (!ts.empty() && ts == "0") {
        ts = c;
    } else {
        ts.push_back(c);
    }
  }
  ```

- `find_first_not_of("0")` 함수 사용도 가능함 
  ```cpp
     aa.erase(0, aa.find_first_not_of('0'));
     bb.erase(0, bb.find_first_not_of('0'));
  ```


