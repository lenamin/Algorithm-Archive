# Sorting 

### Merge Sort 활용 : 뒤에서 채우기 ([LeetCode 88: Merge Sorted Array](https://github.com/lenamin/LeetCode/blob/main/0088-merge-sorted-array/0088-merge-sorted-array.cpp))

**1. 왜 뒤에서부터 채워야함?**
- nums1에 빈 공간이 뒤에 있으니까 큰 값부터 채우면 덮어쓰기 문제가 없음
- 별도 배열 만들지 않고 in-place로 해결 가능
- 시간복잡도 O(m+n), 공간복잡도 O(1)

**2. while 조건 vs if 조건**
- `while (s >= 0)`
  - nums2의 원소가 다 소진될 때까지만 반복
  - nums1은 남아 있어도 이미 자리에 있으니 따로 확인 불필요

- `if (f >= 0 && nums1[f] > nums2[s])`
  - nums1도 남아 있고, nums1의 값이 더 크면 nums1[f]를 뒤에 배치 / 아니면 nums2[s]를 배치

**3. 코드 기본 구조**

```cpp
int f = m - 1;          // nums1 유효 구간 끝
int s = n - 1;          // nums2 끝
int k = m + n - 1;      // nums1 마지막 인덱스

while (s >= 0) {        // nums2 다 쓸 때까지
    if (f >= 0 && nums1[f] > nums2[s]) {
        nums1[k--] = nums1[f--];
    } else {
        nums1[k--] = nums2[s--];
    }
}
```


**4. 이런 패턴이 자주 쓰이는 곳**
- Merge Sort 병합 단계
- 투 포인터(two pointers) 문제 (교집합, 합집합, 구간 병합 등)
- 슬라이딩 윈도우 변형

<br><br>

### stable_sort 구현하기
#### `stable_sort` 
  C++ 표준 라이브러리 `<algorithm>`에 포함된 **정렬 함수**로, **동일한 키 값에 대해서는 원래의 입력 순서를 유지**한다.

```cpp
#include <algorithm>

stable_sort(시작_반복자, 끝_반복자, 비교_함수);
```

: `sort()`와 달리 **안정 정렬(stable sort)**을 제공 <br>
: 내부적으로는 일반적으로 **Merge Sort** 기반으로 구현되어 있다고 한다.

<br><br>

#### 시간 복잡도

| 조건              | 시간 복잡도             |
|------------------|--------------------------|
| 평균/최악의 경우  | O(N log² N) (일반적으로) |
| GNU/GCC STL 구현 | O(N log N)               |

> **참고:** `sort()`는 `IntroSort` 기반으로 평균적으로 더 빠르지만, 입력 순서를 보장하지 않는다. (second값도 정렬해버림)

```cpp
// 예시
vector<pair<int, string>> v = {{21, "Alice"}, {19, "Bob"}, {21, "Charlie"}};

stable_sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.first < b.first;
});
// 출력: 19 Bob, 21 Alice, 21 Charlie  → Alice가 Charlie보다 먼저 출력됨
```

<br><br>



### Merge Sort구현에서 실수한 것들
1. 배열 크기만큼 tmp를 한 번 할당하고, 병합할 구간만 복사하자 <br>
  - tmp를 매번 새로 할당하면 불필요한 시간복잡도(O(n)) 증가
  - tmp를 전체 복사하면 비효율적이며, 시간 초과 발생 가능
  - tmp를 한 번만 할당하고, 병합할 범위만 복사
    ```cpp
    for (int i = s; i <= e; i++) { 
        tmp[i] = arr[i];  // 병합할 부분만 복사해야 시간 초과 방지
    }
    ```
    <br>
    
2. swap 횟수는 idx2 - k로 업데이트해야 한다.
  - idx1이 이동할 때 swap을 증가시키면 잘못된 값이 나올 수 있음 (idx1이 이동하는 것은 기존 순서를 유지하는 것이므로 swap이 발생하지 않으니까) 
  
    ```cpp
    while (idx1 <= m && idx2 <= e) {
        if (tmp[idx1] > tmp[idx2]) {  
            arr[k] = tmp[idx2];  
            result += (idx2 - k);  // 오른쪽 값이 앞으로 오면서 swap 발생  
            k++;
            idx2++;
        } else {
            arr[k] = tmp[idx1];  // 왼쪽 값은 순서 그대로 삽입  
            k++;
            idx1++;
        }
    }
    ```
    
    <br>

3. 병합 정렬을 적용할 때 종료 조건을 확실히 처리!! 
  - if (s >= e) return;을 빠뜨리면 무한 재귀 발생
    ```cpp
    void merge_sort(int s, int e) {
        if (s >= e) return;  // 기저 조건 (배열 크기가 1이면 종료)
    }
    ```
