#include <iostream>
#include <chrono>
#include <iomanip>
#include<vector>
#define int long long

// ANSI color codes
#define RESET   "\u001b[0m"
#define BOLD    "\u001b[1m"
#define GREEN   "\u001b[32m"
#define CYAN    "\u001b[36m"
#define YELLOW  "\u001b[33m"

using namespace std;
using namespace std::chrono;

main() {
    cout << GREEN << BOLD << "\n========== Program Start ==========" << RESET << "\n";

    auto start = high_resolution_clock::now();

    // Your code here
    vector<vector<int>> dp(21,vector<int>(21,0));
    dp[0][0]=1;
    for(int i=0;i<21;i++)
    {
        dp[i][0]=1;
        dp[0][i]=1;
    }

    for(int i=1;i<21;i++)
    {
        for(int j=1;j<21;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[20][20]<<endl;
    
    auto end = high_resolution_clock::now();

    auto ns = duration_cast<nanoseconds>(end - start).count();
    auto us = duration_cast<microseconds>(end - start).count();
    auto ms = duration_cast<milliseconds>(end - start).count();
    double sec = ns / 1e9;

    cout << GREEN << BOLD << "\n========== Program End   ==========" << RESET << "\n";
    cout << CYAN << BOLD << "⏱️  Time taken:\n" << RESET;
    cout << YELLOW << "   » " << ns << " ns\n";
    cout << YELLOW << "   » " << us << " µs\n";
    cout << YELLOW << "   » " << ms << " ms\n";
    cout << YELLOW << "   » " << fixed << setprecision(6) << sec << " s" << RESET << "\n";
    cout << GREEN << "====================================\n" << RESET;

}