// dptoolkit.h
#ifndef DPTOOLKIT_H
#define DPTOOLKIT_H

typedef struct DPProblem
{
    void *instance;
    int (*solve)(void *instance);
} DPProblem;

// Fibonacci structure and functions
typedef struct Fibonacci
{
    int n;
    int *memo;
} Fibonacci;

Fibonacci *create_fibonacci(int n);
void destroy_fibonacci(Fibonacci *fib);
int fibonacci_solve(Fibonacci *fib);

// Knapsack structure and functions
typedef struct Knapsack
{
    int *weights;
    int *values;
    int n;
    int capacity;
    int **memo;
} Knapsack;

Knapsack *create_knapsack(int *weights, int *values, int n, int capacity);
void destroy_knapsack(Knapsack *knapsack);
int knapsack_solve(Knapsack *knapsack);

// Coin Change structure and functions
typedef struct CoinChange
{
    int *coins;
    int n_coins;
    int amount;
    int *memo;
} CoinChange;

CoinChange *create_coin_change(int *coins, int n_coins, int amount);
void destroy_coin_change(CoinChange *coin_change);
int coin_change_solve(CoinChange *coin_change);

// Solver functions
DPProblem *create_dp_problem(void *instance, int (*solve)(void *instance));
void destroy_dp_problem(DPProblem *problem);
int dp_solve(DPProblem *problem);

#endif // DPTOOLKIT_H
