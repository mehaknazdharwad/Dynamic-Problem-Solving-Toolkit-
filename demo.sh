#!/bin/bash

# Demo script for Dynamic Programming Toolkit v2.0
# This script demonstrates the enhanced UI and new features

echo "=========================================="
echo "Dynamic Programming Toolkit v2.0 Demo"
echo "=========================================="
echo ""
echo "This demo showcases the enhanced UI and new features:"
echo "1. Interactive menu system"
echo "2. Input validation and error handling"
echo "3. Enhanced output formatting"
echo "4. New Coin Change algorithm"
echo "5. Algorithm information system"
echo ""

cd dp_toolkit

echo "Building the toolkit..."
gcc -o dptoolkit main.c dptoolkit.c
echo "Build complete!"
echo ""

echo "Demo 1: Fibonacci Sequence (calculating F(20))"
echo "============================================="
echo -e "1\n20\n\n4\n\n5" | ./dptoolkit
echo ""

echo "Demo 2: Knapsack Problem"
echo "========================"
echo "Items: weights [2,3,4,5], values [3,4,5,6], capacity 8"
echo -e "2\n4\n8\n2\n3\n3\n4\n4\n5\n5\n6\n\n5" | ./dptoolkit
echo ""

echo "Demo 3: Coin Change Problem"
echo "============================"
echo "Coins: [1,5,10,25], target amount: 30"
echo -e "3\n4\n30\n1\n5\n10\n25\n\n5" | ./dptoolkit
echo ""

echo "Demo 4: Impossible Coin Change"
echo "==============================="
echo "Coins: [5,10], target amount: 3 (impossible)"
echo -e "3\n2\n3\n5\n10\n\n5" | ./dptoolkit
echo ""

echo "Demo complete! The toolkit now features:"
echo "✅ Interactive menu system"
echo "✅ Comprehensive input validation"  
echo "✅ Enhanced output formatting"
echo "✅ Three dynamic programming algorithms"
echo "✅ Built-in algorithm information"
echo "✅ Robust error handling"