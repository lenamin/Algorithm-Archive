# CPP Cheat Sheet 

### Type Casting
- 문자에서 숫자로 형변환
  ```cpp
  #include <string>
  
  string sNum = "1234";
  string sNum_d = "1234.56";
  
  int inum = stoi(sNum);
  long lnum = stol(sNum);
  double dnum = stod(sNum_d);
  float fnum = stof(sNum_d);
  ```
- 숫자에서 문자로 형변환
  ```cpp
  #include <string>

  int inum = 1234;
  long lnum = 1234;
  double dnum = 1234.56;
  float fnum = 1234.56f;

  string intToString = to_string(inum);
  string longToString = to_string(lnum);
  string doubleToString = to_string(dnum);
  string floatToString = to_string(fnum);
  ```

### 부분 합 구하기 
- 특정 구간의 일부 합을 구할 때 매번 합을 구하게 되면 효율이 떨어져 시간 초과가 날 수 있다.
- 각 자리수의 합을 구한 배열을 미리 구해놓고 (배열 값 받을 때)
  > S[i] = S[i-1] + A[i]

### 입력 출력 시간초과 막기 위한 코드 
```cpp
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```
