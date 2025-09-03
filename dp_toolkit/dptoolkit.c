// dptoolkit.c
#include <stdio.h>
#include <stdlib.h>
#include "dptoolkit.h"

// Helper function to initialize memoization array for Fibonacci
int *init_fibonacci_memo(int n)
{
    int *memo = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; ++i)
    {
        memo[i] = -1;
    }
    return memo;
}

// Fibonacci functions
Fibonacci *create_fibonacci(int n)
{
    Fibonacci *fib = (Fibonacci *)malloc(sizeof(Fibonacci));
    fib->n = n;
    fib->memo = init_fibonacci_memo(n);
    return fib;
}

void destroy_fibonacci(Fibonacci *fib)
{
    if (fib)
    {
        free(fib->memo);
        free(fib);
    }
}

int fibonacci_solve_helper(Fibonacci *fib, int n)
{
    if (fib->memo[n] != -1)
    {
        return fib->memo[n];
    }
    if (n <= 1)
    {
        fib->memo[n] = n;
    }
    else
    {
        fib->memo[n] = fibonacci_solve_helper(fib, n - 1) + fibonacci_solve_helper(fib, n - 2);
    }
    return fib->memo[n];
}

int fibonacci_solve(Fibonacci *fib)
{
    return fibonacci_solve_helper(fib, fib->n);
}

// Helper function to initialize memoization array for Knapsack
int **init_knapsack_memo(int n, int capacity)
{
    int **memo = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; ++i)
    {
        memo[i] = (int *)malloc((capacity + 1) * sizeof(int));
        for (int j = 0; j <= capacity; ++j)
        {
            memo[i][j] = -1;
        }
    }
    return memo;
}

// Knapsack functions
Knapsack *create_knapsack(int *weights, int *values, int n, int capacity)
{
    Knapsack *knapsack = (Knapsack *)malloc(sizeof(Knapsack));
    knapsack->weights = weights;
    knapsack->values = values;
    knapsack->n = n;
    knapsack->capacity = capacity;
    knapsack->memo = init_knapsack_memo(n, capacity);
    return knapsack;
}

void destroy_knapsack(Knapsack *knapsack)
{
    if (knapsack)
    {
        for (int i = 0; i <= knapsack->n; ++i)
        {
            free(knapsack->memo[i]);
        }
        free(knapsack->memo);
        free(knapsack);
    }
}

int knapsack_solve_helper(Knapsack *knapsack, int i, int w)
{
    if (i < 0 || w == 0)
    {
        return 0;
    }
    if (knapsack->memo[i][w] != -1)
    {
        return knapsack->memo[i][w];
    }
    if (knapsack->weights[i] > w)
    {
        knapsack->memo[i][w] = knapsack_solve_helper(knapsack, i - 1, w);
    }
    else
    {
        int include = knapsack->values[i] + knapsack_solve_helper(knapsack, i - 1, w - knapsack->weights[i]);
        int exclude = knapsack_solve_helper(knapsack, i - 1, w);
        knapsack->memo[i][w] = (include > exclude) ? include : exclude;
    }
    return knapsack->memo[i][w];
}

int knapsack_solve(Knapsack *knapsack)
{
    return knapsack_solve_helper(knapsack, knapsack->n - 1, knapsack->capacity);
}

// Solver functions
DPProblem *create_dp_problem(void *instance, int (*solve)(void *instance))
{
    DPProblem *problem = (DPProblem *)malloc(sizeof(DPProblem));
    problem->instance = instance;
    problem->solve = solve;
    return problem;
}

void destroy_dp_problem(DPProblem *problem)
{
    if (problem)
    {
        free(problem);
    }
}

int dp_solve(DPProblem *problem)
{
    return problem->solve(problem->instance);
}

// Coin Change functions
CoinChange *create_coin_change(int *coins, int n_coins, int amount)
{
    CoinChange *coin_change = (CoinChange *)malloc(sizeof(CoinChange));
    coin_change->coins = coins;
    coin_change->n_coins = n_coins;
    coin_change->amount = amount;
    coin_change->memo = (int *)malloc((amount + 1) * sizeof(int));
    for (int i = 0; i <= amount; i++)
    {
        coin_change->memo[i] = -1;
    }
    return coin_change;
}

void destroy_coin_change(CoinChange *coin_change)
{
    if (coin_change)
    {
        free(coin_change->memo);
        free(coin_change);
    }
}

int coin_change_solve_helper(CoinChange *coin_change, int amount)
{
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    
    if (coin_change->memo[amount] != -1)
    {
        return coin_change->memo[amount];
    }
    
    int min_coins = -1;
    for (int i = 0; i < coin_change->n_coins; i++)
    {
        int sub_result = coin_change_solve_helper(coin_change, amount - coin_change->coins[i]);
        if (sub_result != -1)
        {
            if (min_coins == -1 || sub_result + 1 < min_coins)
            {
                min_coins = sub_result + 1;
            }
        }
    }
    
    coin_change->memo[amount] = min_coins;
    return min_coins;
}

int coin_change_solve(CoinChange *coin_change)
{
    return coin_change_solve_helper(coin_change, coin_change->amount);
}
