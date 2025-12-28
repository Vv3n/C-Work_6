#include <stdio.h>
#define MONTHS 3

int analyze_profitability(int *rev_ptr, int *exp_ptr, int size, int *status_ptr);
void get_monthly_data(int array[], int size, const char *type);
void print_monthly_data(int array[], int size, const char *type);

int main(){
    int monthly_revenue[MONTHS];
    int monthly_expense[MONTHS];
    int net_profit;
    int business_status;


    get_monthly_data(monthly_revenue, MONTHS, "REVENUE");
    get_monthly_data(monthly_expense, MONTHS, "EXPENSE");

    net_profit = analyze_profitability(monthly_revenue, monthly_expense, MONTHS, &business_status);

    printf("\n--- 3 MONTH FINANCIAL ANALYSIS REPORT ---\n");
    print_monthly_data(monthly_revenue, MONTHS, "REVENUE");
    print_monthly_data(monthly_expense, MONTHS, "EXPENSE");

    printf("\nNET PROFIT: %d\n", net_profit);
    if(business_status == 1){
        printf("BUSINESS STATUS: PROJECT IS PROFITABLE");
    }
    else{
        printf("BUSINESS STATUS: PROJECT IS UNPROFITABLE");
    }
    
    return 0;
}

void get_monthly_data(int array[], int size, const char *type){
    printf("\nEnter %d months of %s values:\n", size, type);
    for(int i = 0; i < size; i++){
        printf("Month %d %s: ", i + 1, type);
        scanf("%d", &array[i]);
    }
}

void print_monthly_data(int array[], int size, const char *type){
    long total = 0;
    for(int i = 0; i < size; i++){
        total += array[i];
    }
    printf("TOTAL %s: %ld\n", type, total);
}

int analyze_profitability(int *rev_ptr, int *exp_ptr, int size, int *status_ptr){
    int total_revenue = 0;
    int total_expense = 0;

    for( int i = 0; i < size; i++ ){
        total_revenue += *(rev_ptr + i);
        total_expense += *(exp_ptr + i);
    }

    int net_profit = total_revenue - total_expense;
    *status_ptr = (net_profit >= 0) ? 1 : 0;

    return net_profit;
}