# Number Theory 

```cpp
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
```

```cpp
int gcd(int a, int b) {
    if (b == 0) { return a; } // b가 0이면 a가 최대공약수 
    else {
        return gcd(b, a % b); // 재귀호출: b와 a % b로 다시 계산 
    }
}
```