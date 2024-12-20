#include <stdio.h>

void bestDaysToBuyAndSell(int prices[], int size, int *buyDay, int *sellDay) {
    if (size < 2) {
        *buyDay = -1; 
        *sellDay = -1;
        return;
    }

    int minPriceDay = 0; 
    int maxProfit = 0;  
    *buyDay = 0;
    *sellDay = 0;

    for (int i = 1; i < size; i++) {
       
        int profit = prices[i] - prices[minPriceDay];

       
        if (profit > maxProfit) {
            maxProfit = profit;
            *buyDay = minPriceDay;
            *sellDay = i;
        }

        if (prices[i] < prices[minPriceDay]) {
            minPriceDay = i;
        }
    }
}

int main() {
    int size;


    printf("Enter the number of days: ");
    scanf("%d", &size);

    if (size < 2) {
        printf("Not enough data to determine buy/sell days.\n");
        return 0;
    }

    int prices[size];

    printf("Enter the prices for %d days:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &prices[i]);
    }

    int buyDay, sellDay;

    bestDaysToBuyAndSell(prices, size, &buyDay, &sellDay);

    if (buyDay == -1 || sellDay == -1) {
        printf("Not enough data to determine buy/sell days.\n");
    } else {
        printf("Best day to buy: %d\n", buyDay);
        printf("Best day to sell: %d\n", sellDay);
    }

    return 0;
}
