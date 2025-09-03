// main.c
#include <stdio.h>
#include <stdlib.h>
#include "dptoolkit.h"

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function to display main menu
void display_menu() {
    printf("\n");
    printf("=====================================\n");
    printf("  Dynamic Programming Toolkit v2.0  \n");
    printf("=====================================\n");
    printf("\n");
    printf("Available Problems:\n");
    printf("1. Fibonacci Sequence\n");
    printf("2. 0/1 Knapsack Problem\n");
    printf("3. Coin Change Problem\n");
    printf("4. About & Algorithm Info\n");
    printf("5. Exit\n");
    printf("\n");
    printf("Enter your choice (1-5): ");
}

// Function to display algorithm information
void display_algorithm_info() {
    printf("\n");
    printf("=========================================\n");
    printf("        ALGORITHM INFORMATION           \n");
    printf("=========================================\n");
    printf("\n");
    printf("1. FIBONACCI SEQUENCE:\n");
    printf("   - Uses dynamic programming with memoization\n");
    printf("   - Time Complexity: O(n)\n");
    printf("   - Space Complexity: O(n)\n");
    printf("   - Calculates: F(n) = F(n-1) + F(n-2)\n");
    printf("\n");
    printf("2. 0/1 KNAPSACK PROBLEM:\n");
    printf("   - Uses dynamic programming with memoization\n");
    printf("   - Time Complexity: O(n * capacity)\n");
    printf("   - Space Complexity: O(n * capacity)\n");
    printf("   - Finds maximum value within weight constraint\n");
    printf("\n");
    printf("3. COIN CHANGE PROBLEM:\n");
    printf("   - Uses dynamic programming with memoization\n");
    printf("   - Time Complexity: O(amount * n_coins)\n");
    printf("   - Space Complexity: O(amount)\n");
    printf("   - Finds minimum coins needed for amount\n");
    printf("\n");
    printf("Press Enter to continue...");
    getchar();
}

// Function to handle Fibonacci problem
void handle_fibonacci() {
    int n;
    printf("\n");
    printf("=================================\n");
    printf("     FIBONACCI SEQUENCE         \n");
    printf("=================================\n");
    printf("\n");
    printf("Enter the position (n >= 0): ");
    
    if (scanf("%d", &n) != 1) {
        clear_input_buffer();
        printf("Error: Invalid input. Please enter a valid number.\n");
        return;
    }
    clear_input_buffer();
    
    if (n < 0) {
        printf("Error: Position must be non-negative.\n");
        return;
    }
    
    if (n > 50) {
        printf("Warning: Large numbers may take time. Proceeding...\n");
    }
    
    printf("\nCalculating Fibonacci number at position %d...\n", n);
    
    Fibonacci *fib = create_fibonacci(n);
    if (!fib) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    
    DPProblem *fib_problem = create_dp_problem(fib, (int (*)(void *))fibonacci_solve);
    if (!fib_problem) {
        printf("Error: Problem creation failed.\n");
        destroy_fibonacci(fib);
        return;
    }
    
    int result = dp_solve(fib_problem);
    
    printf("\n");
    printf("Result:\n");
    printf("-------\n");
    printf("F(%d) = %d\n", n, result);
    printf("\n");
    printf("Sequence leading to F(%d): ", n);
    for (int i = 0; i <= n && i <= 10; i++) {
        printf("%d", fib->memo[i]);
        if (i < n && i < 10) printf(", ");
        else if (i == 10 && n > 10) printf("...");
    }
    printf("\n");
    
    destroy_dp_problem(fib_problem);
    destroy_fibonacci(fib);
    
    printf("\nPress Enter to continue...");
    getchar();
}

// Function to handle Knapsack problem
void handle_knapsack() {
    int n, capacity;
    printf("\n");
    printf("=================================\n");
    printf("     0/1 KNAPSACK PROBLEM       \n");
    printf("=================================\n");
    printf("\n");
    printf("Enter number of items: ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        clear_input_buffer();
        printf("Error: Invalid number of items. Must be positive.\n");
        return;
    }
    
    printf("Enter knapsack capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        clear_input_buffer();
        printf("Error: Invalid capacity. Must be positive.\n");
        return;
    }
    clear_input_buffer();
    
    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));
    
    if (!weights || !values) {
        printf("Error: Memory allocation failed.\n");
        free(weights);
        free(values);
        return;
    }
    
    printf("\nEnter weights and values for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        if (scanf("%d", &weights[i]) != 1 || weights[i] <= 0) {
            printf("Error: Invalid weight for item %d.\n", i + 1);
            free(weights);
            free(values);
            clear_input_buffer();
            return;
        }
        
        printf("Item %d - Value: ", i + 1);
        if (scanf("%d", &values[i]) != 1 || values[i] <= 0) {
            printf("Error: Invalid value for item %d.\n", i + 1);
            free(weights);
            free(values);
            clear_input_buffer();
            return;
        }
    }
    clear_input_buffer();
    
    printf("\nProblem Summary:\n");
    printf("----------------\n");
    printf("Capacity: %d\n", capacity);
    printf("Items:\n");
    for (int i = 0; i < n; i++) {
        printf("  Item %d: Weight=%d, Value=%d, Ratio=%.2f\n", 
               i + 1, weights[i], values[i], (float)values[i]/weights[i]);
    }
    
    printf("\nSolving knapsack problem...\n");
    
    Knapsack *knapsack = create_knapsack(weights, values, n, capacity);
    if (!knapsack) {
        printf("Error: Knapsack creation failed.\n");
        free(weights);
        free(values);
        return;
    }
    
    DPProblem *knapsack_problem = create_dp_problem(knapsack, (int (*)(void *))knapsack_solve);
    if (!knapsack_problem) {
        printf("Error: Problem creation failed.\n");
        destroy_knapsack(knapsack);
        free(weights);
        free(values);
        return;
    }
    
    int result = dp_solve(knapsack_problem);
    
    printf("\n");
    printf("Result:\n");
    printf("-------\n");
    printf("Maximum value achievable: %d\n", result);
    printf("Knapsack capacity: %d\n", capacity);
    
    destroy_dp_problem(knapsack_problem);
    destroy_knapsack(knapsack);
    free(weights);
    free(values);
    
    printf("\nPress Enter to continue...");
    getchar();
}

// Function to handle Coin Change problem
void handle_coin_change() {
    int n_coins, amount;
    printf("\n");
    printf("=================================\n");
    printf("     COIN CHANGE PROBLEM        \n");
    printf("=================================\n");
    printf("\n");
    printf("Enter number of coin denominations: ");
    
    if (scanf("%d", &n_coins) != 1 || n_coins <= 0) {
        clear_input_buffer();
        printf("Error: Invalid number of coin types. Must be positive.\n");
        return;
    }
    
    printf("Enter target amount: ");
    if (scanf("%d", &amount) != 1 || amount < 0) {
        clear_input_buffer();
        printf("Error: Invalid amount. Must be non-negative.\n");
        return;
    }
    clear_input_buffer();
    
    if (amount == 0) {
        printf("\nResult: 0 coins needed for amount 0.\n");
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }
    
    int *coins = (int *)malloc(n_coins * sizeof(int));
    if (!coins) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    
    printf("\nEnter coin denominations:\n");
    for (int i = 0; i < n_coins; i++) {
        printf("Coin %d value: ", i + 1);
        if (scanf("%d", &coins[i]) != 1 || coins[i] <= 0) {
            printf("Error: Invalid coin value for coin %d.\n", i + 1);
            free(coins);
            clear_input_buffer();
            return;
        }
    }
    clear_input_buffer();
    
    printf("\nProblem Summary:\n");
    printf("----------------\n");
    printf("Target Amount: %d\n", amount);
    printf("Available Coins: ");
    for (int i = 0; i < n_coins; i++) {
        printf("%d", coins[i]);
        if (i < n_coins - 1) printf(", ");
    }
    printf("\n");
    
    printf("\nSolving coin change problem...\n");
    
    CoinChange *coin_change = create_coin_change(coins, n_coins, amount);
    if (!coin_change) {
        printf("Error: Coin change problem creation failed.\n");
        free(coins);
        return;
    }
    
    DPProblem *coin_problem = create_dp_problem(coin_change, (int (*)(void *))coin_change_solve);
    if (!coin_problem) {
        printf("Error: Problem creation failed.\n");
        destroy_coin_change(coin_change);
        free(coins);
        return;
    }
    
    int result = dp_solve(coin_problem);
    
    printf("\n");
    printf("Result:\n");
    printf("-------\n");
    if (result == -1) {
        printf("No solution possible with given coins.\n");
        printf("The amount %d cannot be made with coins: ", amount);
        for (int i = 0; i < n_coins; i++) {
            printf("%d", coins[i]);
            if (i < n_coins - 1) printf(", ");
        }
        printf("\n");
    } else {
        printf("Minimum coins needed: %d\n", result);
        printf("Target amount: %d\n", amount);
    }
    
    destroy_dp_problem(coin_problem);
    destroy_coin_change(coin_change);
    free(coins);
    
    printf("\nPress Enter to continue...");
    getchar();
}

int main() {
    int choice;
    
    printf("Welcome to Dynamic Programming Toolkit!\n");
    printf("This toolkit helps you solve classic DP problems efficiently.\n");
    
    while (1) {
        display_menu();
        
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("\nError: Invalid input. Please enter a number between 1-5.\n");
            continue;
        }
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                handle_fibonacci();
                break;
            case 2:
                handle_knapsack();
                break;
            case 3:
                handle_coin_change();
                break;
            case 4:
                display_algorithm_info();
                break;
            case 5:
                printf("\nThank you for using Dynamic Programming Toolkit!\n");
                printf("Goodbye! 👋\n");
                return 0;
            default:
                printf("\nError: Invalid choice. Please select 1-5.\n");
                break;
        }
    }
    
    return 0;
}
