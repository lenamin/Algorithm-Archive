#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    // a : 콜라를 받기 위해 마트에 주어야 하는 병 수 (빈 병 수)
    // b : 빈 병을 가져다주면 마트가 주는 콜라 병 수 (돌려받는 )
    // n : 상빈이가 가지고 있는 빈 병의 개수 (전체) 
    // return 상빈이가 받을 수 있는 콜라 병 수 
    
    
    int empty = n; // 상빈이가 현재 가지고 있는 빈 병 수

    // 빈 병 수 n 중 b로 나눴을 때 가장 큰 수 그 몫 * b 
    int sum = 0; 
    
    int g = (empty / a) * a; // 마트에 가져갈 콜라병 개수  
    int t = (g / a) * b; // 마트에서 받을 수 있는 콜라병 개수
    
    while (true) {
        g = (empty / a) * a; // 마트에 가져갈 콜라병 개수  
        t = (g / a) * b; // 마트에서 받을 수 있는 콜라병 개수
        sum += t;
        
        int nextEmpty = empty - g + t; // 가지고 있는 총 개수    
        
        if (nextEmpty >= a) {
             empty = nextEmpty;
        } else { break; }
        
        // cout << "g : " << g << ", t : " << t << ", empty: " << nextEmpty << '\n';
    
        
    }
    
    return sum;
}
