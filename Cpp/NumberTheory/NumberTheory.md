# Number Theory 

## 에라토스테네스의 체 좀 외우자 제발 
- 작은 소수부터 시작해서 그 배수를 모두 지우면, 남는 수가 소수임 
- 시간복잡도 : O(n log log n)
```cpp
vector<int> arr(n + 1);
for (int i = 0; i <= n; i++) arr[i] = i;
arr[1] = 0;
```
0 부터 n까지 배열에 자기자신을 채운다. (1은 소수가 아니니까 0으로 지운다)


```cpp
for (int i = 2; i <= sqrt(n); i++) {
    if (arr[i] == 0) continue;
    for (int j = i + i; j <= n; j = j + i) {
        arr[j] = 0;
    }
}

```
- i가 아직 남아있으면 (소수라면) 그 배수들은 전부 지운다 -> 이렇게하면 소수의 배수들 전부 제거되고, 남는 값을 소수 뿐 


```cpp
for (int i = m; i <= n; i++) {
    if (arr[i] != 0) cout << arr[i] << '\n';
}
```
남아있는 수들 `arr[i] != 0` 만 출력 



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