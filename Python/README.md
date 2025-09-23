[Counter 활용하기](https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150)

**1. 원소 개수 확인**

    ```python
    from collections import Counter
    c = Counter("banana")
    c['a']   # 3
    c['x']   # 0 (없는 원소는 기본값 0)
    ```

**2. 최빈값 (most_common)**

    ```python
    c.most_common(1)   # [('a', 3)]
    c.most_common(2)   # [('a', 3), ('n', 2)]
    ```

**3. elements()**
- 빈도수만큼 원소를 반복(iterable로 반환)
    ```python
    list(c.elements())
    # ['b', 'a', 'a', 'a', 'n', 'n']
    ```

**4. update() / subtract()**
- 카운트 증가/감소

    ```python
    c = Counter("banana")
    c.update("aab")     # {'a': 5, 'n': 2, 'b': 2}
    c.subtract("an")    # {'a': 4, 'n': 1, 'b': 2}
    ```


**5. 산술 연산**
```python
c1 = Counter("aab")
c2 = Counter("abc")

c1 + c2   # Counter({'a': 3, 'b': 2, 'c': 1})
c1 - c2   # Counter({'a': 1})   # 음수/0은 제거됨
c1 & c2   # Counter({'a': 1, 'b': 1})  # 교집합(min)
c1 | c2   # Counter({'a': 2, 'b': 1, 'c': 1})  # 합집합(max)
```

**6. dict와의 호환성**
```python
dict(Counter("banana"))  
# {'b': 1, 'a': 3, 'n': 2}
```


### 자주 쓰는 패턴 
- **아나그램 판별**
    ```python
    Counter(s1) == Counter(s2)
    ```

- **최빈값 구하기**
    ```python
    Counter(arr).most_common(1)[0][0]    
    ```

- **차집합 (부족한 자원 찾기)**
    ```python
    Counter(ransomNote) - Counter(magazine)
    ```

- **교집합 (공통 원소)** 
    ```python
    (Counter(A) & Counter(B)).elements()
    ```

### 시간 복잡도
- 생성: O(N)
= 조회/수정: O(1) 평균
- 연산(+, -, &, |): O(U) (U = 유니크 원소 수)