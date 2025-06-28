# Stack & Queue 


### 큐로 원형 순회 구조 만들기 

```cpp
  queue<int> q;
  for (int i = 1; i <= n; i++) q.push(i);

  while (!q.empty()) {
      for (int i = 0; i < k - 1; i++) {
          q.push(q.front());
          q.pop();
      }
      ans.push_back(q.front());
      q.pop();
  }
```

- 기존 vector + index 로 관리할 때 idx 관리의 어려움을 queue로 해결할 수 있었다! 
