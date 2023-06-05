#include <stdio.h>

#define MAX 100

// Define structure for Bank
typedef struct{
    int account_id;
    char name[100];
    long long int route_no;
    char account_type[20];
    double balance;
}Bank;

// Function to search and print details of a customer
void print_customer_details(Bank customers[], int n, int account_id){
    int i;
    for(i = 0; i < n; i++){
        if(customers[i].account_id == account_id){
            printf("\nCustomer Details: \n");
            printf("Account ID: %d\n", customers[i].account_id);
            printf("Name: %s\n", customers[i].name);
            printf("Route No: %lld\n", customers[i].route_no);
            printf("Account Type: %s\n", customers[i].account_type);
            printf("Balance: %.2lf USD\n", customers[i].balance);
            return;
        }
    }
    printf("\nNo Customer with given Account ID found.\n");
}

// Main function
int main() {
    int i, n, search_account_id;
    Bank customers[MAX];

    printf("Enter the number of customers: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("\nEnter Details for Customer %d\n", i+1);
        printf("Enter Account ID: ");
        scanf("%d", &customers[i].account_id);
        printf("Enter Name: ");
        scanf(" %[^\n]", customers[i].name); // space before % to skip any leading whitespace characters
        printf("Enter Route No: ");
        scanf("%lld", &customers[i].route_no);
        printf("Enter Account Type: ");
        scanf(" %[^\n]", customers[i].account_type);
        printf("Enter Balance: ");
        scanf("%lf", &customers[i].balance);
    }

    printf("\nEnter Account ID to Search: ");
    scanf("%d", &search_account_id);

    print_customer_details(customers, n, search_account_id);

    return 0;
}
