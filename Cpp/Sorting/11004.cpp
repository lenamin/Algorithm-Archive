// K번째 수 구하기 

// 퀵 정렬 
// pivot을 선정해서 이 pivot보다 작은 데이터와 큰 데이터로 분류하는 것을 반복해 정렬하는 알고리즘 
// 1. 가장 오른쪽 끝을 pivot으로 설정한다고 하자 
    // 2. start가 가리키는 데이터가 pivot이 가리키는 데이터보다 작으면 start를 오른쪽으로 한 칸 이동 
    // 3. end가 가리키는 데이터가 pivot이 가리키는 데이터보다 크면 end를 왼쪽으로 한 칸 이동 
    // 4. 위와 반대가 되는 조건이 되면, swap하고 start는 오른쪽, end는 왼쪽으로 한 칸 씩 이동함 
// 5. start == end 만날 때 까지 반복해준다 
// 만나면, 만난 지점에서 가리키는 데이터와 pivot이 가리키는 데이터 비교 -> pivot이 가리키는 데이터가 그면 만난 지점의 오른쪽으로, 작으면 왼쪽으로 삽입 
// 


/*
vector<int> arr;

void quick_sort(vector<int> &arr, int s, int e, int k);
int partition(vector<int> &arr, int s, int e);

int main() {
    int n, m;
    cin >> n >> m;
    
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, 0, n - 1, m - 1); 
    cout << arr[m - 1] << '\n';
}

int partition(vector<int> &arr, int s, int e) {
    if (s + 1 == e) { // 원소가 두 개만 있을 때
        if (arr[s] > arr[e]) {
            swap(arr[s], arr[e]);
        }

        

        return e;
    }

    int m = (s + e) / 2; // 중앙값 찾기 
    // 중앙값 첫번째 요소로 이동시키기 -> s, e 이동 쉽게 할라믄 
    
    swap(arr[s], arr[m]);

    int pivot = arr[s]; // 중앙값을 젤 앞으로 당겼으니까 이걸 pivot이라고 설정해줌 
    int i = s + 1;
    int j = e;

    while (i <= j) {
        // 피벗보다 큰 수가 나올 때 까지 i 증가시키기  (e 범위를 벗어나지 않는 조건 추가)
        while (i <= e && pivot >= arr[i]) i++;

        // 피벗보다 작은 수가 나올 때 까지 j 감소
        // stable sort 를 위해 pivot <= arr[j]가 아닌 pivot < arr[j] 로 해 중복값의 상대적인 순서 유지해주기 
        while (j > s && pivot < arr[j]) j--; 

        if (i < j) { // 잘못된 위치에 있으면 교환함 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[s], arr[j]); // pivot을 최종 위치로 이동한다 
    return j; // pivot 최종 위치 반환 
}

void quick_sort(vector<int> &arr, int s, int e, int k) {
    // if (s == e) { return arr[s]; }
    int p = partition(arr, s, e);

    if (p == k) {
        return;
    } else if (p > k) quick_sort(arr, s, p - 1, k); // 왼쪽 정렬 
    else {
        quick_sort(arr, p + 1, e, k); // 오른쪽 정렬 
    }
}
*/


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // nth_element(arr.begin(), arr.begin() + (m - 1), arr.end());
    sort(arr.begin(), arr.end());
    
    cout << arr[m - 1] << '\n';
}
