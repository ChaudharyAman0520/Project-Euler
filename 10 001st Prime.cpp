#include <iostream>
#include <chrono>
#include <iomanip>
#define int long long
// ANSI color codes
#define RESET   "\u001b[0m"
#define BOLD    "\u001b[1m"
#define GREEN   "\u001b[32m"
#define CYAN    "\u001b[36m"
#define YELLOW  "\u001b[33m"

using namespace std;
using namespace std::chrono;
bool isPrime(int n)
{
    if(n<=1)
    {
        return false;
    }
    if(n<=3)
    {
        return true;
    }
    if(n%2==0||n%3==0)
    {
        return false;
    }
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)
        {
            return false;
        }
    }
    return true;
}
main() {
    cout << GREEN << BOLD << "\n========== Program Start ==========" << RESET << "\n";

    auto start = high_resolution_clock::now();

    int i=1;
    int cnt=0;
    while(true)
    {
        if(isPrime(i))
        {
            cnt++;
        }
        if(cnt==10001)
        {
            cout<<i<<endl;
            break;
        }
        i++;
    }

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

    return 0;
}