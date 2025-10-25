#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <vector>
#define int long long

// ANSI color codes
#define RESET   "\u001b[0m"
#define BOLD    "\u001b[1m"
#define GREEN   "\u001b[32m"
#define CYAN    "\u001b[36m"
#define YELLOW  "\u001b[33m"

using namespace std;
using namespace std::chrono;

vector<int> dp(1000000, 0);

int check(int n)
{
    int original = n;  // keep the original key
    int cnt = 0;

    while (n != 1)
    {
        if (n < 1000000 && dp[n] != 0)
        {
            cnt += dp[n];  // use memoized value
            break;
        }

        cnt++;

        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }

    if (original < 1000000)
        dp[original] = cnt;  // store only for the starting number

    return cnt;
}
main() {
    cout << GREEN << BOLD << "\n========== Program Start ==========" << RESET << "\n";

    auto start = high_resolution_clock::now();

    // Your code here
    int fans=LLONG_MIN;
    int ans=-1;
    for(int i=1;i<1000000;i++)
    {
        if(check(i)>fans)
        {
            fans=check(i);
            ans=i;
        }
    }
    cout<<ans<<endl;
    // check(13);
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