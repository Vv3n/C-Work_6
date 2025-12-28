#include <stdio.h>
#define SIZE 5

int calculate_net_balance(int *trans_array, int size, int *status_ptr);

int main(){
    int transactions[SIZE];
    int net_balance;
    int finance_status;
    int i;

    printf("Enter %d transaction (Income +, Expense -):\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Transaction %d: ", i + 1);
        scanf("%d", &transactions[i]);
    }

    net_balance = calculate_net_balance( transactions, SIZE,  &finance_status);

    printf("\n--- PERSONAL FINANCE REPOET ---\n");
    printf("Transactions Recorded: ");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", transactions[i]);
    }
    printf("\n");
    printf("Net Balance: %d\n", net_balance);
    
    if(finance_status == 1){
        printf("Status: PROFIT\n");
    }
    else{
        printf("Status: LOSS\n");
    }

    return 0;
}

int calculate_net_balance(int *trans_array, int size, int *status_ptr){
    int sum = 0;
    for( int i = 0; i < size; i++ ){
        sum += *(trans_array + i);
    }

    if( sum >= 0 ){
        *status_ptr = 1;
    }
    else{
        *status_ptr = 0;
    } 
    return sum;
}