#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 3일 연속 오르면 -> 팔고
    // 3일 연속 내리면 -> 산다 

    // 현금 잔액
    int bcash = n; // 준현이의 잔액
    int tcash = n; // 성민이의 잔액

    // 주식보유수량
    int bstock = 0; // 준현이 주식보유수량
    int tstock = 0; // 성민이 주식보유수량

    int ucnt = 0; // 연속적으로 오른 횟수
    int dcnt = 0; // 연속적으로 내린 횟수

    int prev = -1;  // 이전 currentPrice 값 
    int currentPrice, lastPrice;

    for (int i = 0; i < 14; i++) {    
        cin >> currentPrice;

        // 준현이 매매 로직 
        if (i == 0) {
            // m가격일 때 매수하려면 m / bnp 수량만큼 살 수 있다 
            prev = currentPrice;
            bstock += (bcash / currentPrice);
            bcash = bcash - (bstock * currentPrice); // 잔여 수 
        }
        
        if (bcash / currentPrice != 0) { // 잔액이 현재 주식을 살 수 있을만큼 남아있으면 
            // 매수 
            int nums = (bcash / currentPrice);
            bstock += nums;
            bcash = bcash - (nums * currentPrice); // 잔여 수 
        }

        if (i == 13) {
            // 준현이 전량 매도할거임 
            int buyPrice = bstock * currentPrice;
            bcash += buyPrice;
            bstock = 0;
            
            // 성민이도 전량 매도해야하네 
            int buyPrice2 = tstock * currentPrice;
            tcash += buyPrice2;
            tstock = 0;

            lastPrice = currentPrice;
        }
        // --- 준현이 매매 로직 끝 

        if (prev > currentPrice) { // 가격 내릴 때
            ucnt = 0;
            dcnt++;

            if ((tcash / currentPrice != 0) && dcnt == 3) { // 3번 연속 내리면 전량 매수한다 (매수하는건 보유현금이 줄어들지)
                int nums = (tcash / currentPrice);
                tstock += nums; // 몇 개 살 수 있는지 구해서 
                tcash -= (nums * currentPrice);
                dcnt = 0;
                // cout << "성민이가 매수한 날짜 : " << i << '\n';
            }
        } else if (prev < currentPrice) { // 오를 때
            dcnt = 0;
            ucnt++;

            if (tstock != 0 && ucnt == 3) { // 3번 연속 올랐으니까 전량 매도한다 (매도하는건 보유현금이 늘어나는 것)) 
                tcash += (tstock * currentPrice);
                tstock = 0;
                ucnt = 0;
                // cout << "성민이가 매도한 날짜 : " << i << '\n';
            }
        } // 같으면 아무것도 값 유지

        
        prev = currentPrice;
        // cout << "성민이의 자산은 : " << tcash << " 이고, 성민이 보유 주식 수량은 " << tstock << " 이다." << '\n';
    }

    // cout << "현준이의 자산은 : " << bcash << " 이고, 현준이 보유 주식 수량은 " << bstock << " 이다." << '\n';
    // cout << "성민이의 자산은 : " << tcash << " 이고, 성민이 보유 주식 수량은 " << tstock << " 이다." << '\n';

    if (bcash > tcash) cout << "BNP";
    else if (bcash < tcash) cout << "TIMING";
    else if (bcash == tcash) cout << "SAMESAME";

}

/* 리팩토링 코드 

#include <bits/stdc++.h>
using namespace std;

void buy(int& cash, int& stock, int price) {
    int units = cash / price;
    stock += units;
    cash -= units * price;
}

void sell(int& cash, int& stock, int price) {
    cash += stock * price;
    stock = 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(14);
    for (int i = 0; i < 14; i++) cin >> prices[i];

    // 준현
    int b_cash = n, b_stock = 0;

    // 성민
    int t_cash = n, t_stock = 0;
    int up = 0, down = 0;

    for (int i = 0; i < 14; i++) {
        int price = prices[i];

        // 준현: 매일 살 수 있으면 삼
        buy(b_cash, b_stock, price);

        // 성민: 3일 연속 하락 or 상승 판단
        if (i >= 1) {
            if (prices[i] > prices[i - 1]) {
                up++;
                down = 0;
            } else if (prices[i] < prices[i - 1]) {
                down++;
                up = 0;
            } else {
                up = down = 0;
            }
        }

        if (down >= 3) {
            buy(t_cash, t_stock, price);
        }
        if (up >= 3 && t_stock > 0) {
            sell(t_cash, t_stock, price);
        }
    }

    // 마지막 날 정산 (공통)
    int final_price = prices.back();
    sell(b_cash, b_stock, final_price);
    sell(t_cash, t_stock, final_price);

    // 결과 출력
    if (b_cash > t_cash) cout << "BNP\n";
    else if (b_cash < t_cash) cout << "TIMING\n";
    else cout << "SAMESAME\n";

    return 0;
}


*/