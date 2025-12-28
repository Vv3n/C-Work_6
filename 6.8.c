#include <stdio.h>
#define SIZE 5

int find_and_update(int *arr_ptr, int size, int search_value, int new_value);
void print_array(int array[], int size);

int main(){
    int number[SIZE];
    int search_val;
    int new_val;
    int status;
    int i;

    printf("Enter %d integer elements for the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &number[i]);
    }

    printf("\nEnter value to search (Search Value): ");
    scanf("%d", &search_val);
    printf("Enter new value to replace it with (New Value): ");
    scanf("%d", &new_val);

    printf("\n--- ARRAY UPDATE REPORT ---\n");
    printf("Array BEFORE Update: ");
    print_array(number, SIZE);

    status = find_and_update(number, SIZE, search_val, new_val);

    printf("Array AFTER Update: ");
    print_array(number, SIZE);

     if(status == 1){
        printf("Status: Success\n");
    }
    else{
        printf("Status: Failed\n");
    }

    return 0;
}

void print_array(int array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int find_and_update(int *arr_ptr, int size, int search_value, int new_value){
    for (int i = 0; i < size; i++) {
        if ( *(arr_ptr + i) == search_value ) {
            *(arr_ptr + i) = new_value;
            return 1;
        }
    }
    return 0;
}