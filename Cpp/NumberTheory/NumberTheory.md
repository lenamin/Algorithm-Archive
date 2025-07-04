# Number Theory 

## Euclidean Algorithm
### lcm (최소공배수) 구하기 
: 두 수를 곱하고 gcd(a, b) 로 나누기 <br>
```cpp
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
```
<br>

### gcd (최대공약수) 구하기
: 0일 때 우선 a 반환 
: 아닐 때, gcd재귀호출하는데 파라미터로 (b, a % b) 넣어주기  <br>

```cpp
int gcd(int a, int b) {
    if (b == 0) { return a; } // b가 0이면 a가 최대공약수 
    else {
        return gcd(b, a % b); // 재귀호출: b와 a % b로 다시 계산 
    }
}
```