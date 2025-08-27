# Recursion 

### 9분할을 반복문으로 재귀호출 (9가지 경우의 수 모두 돌 수 있게)

```cpp
int newLen = len / 3;

for (int dx = 0; dx < 3; dx++) {
    for (int dy = 0; dy < 3; dy++) {
        solve(x + dx * newLen, y + dy * newLen, newLen);
    }
}
```

- `dx`, `dy` : x축, y축 방향으로 세 칸으로 쪼갬 
- `x + dx * newLen` , `y + dy * newLen` : 각 작은 블록의 시작좌표 
