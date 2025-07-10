#include <iostream>
#include <chrono>
#include <iomanip>

// ANSI color codes
#define RESET   "\u001b[0m"
#define BOLD    "\u001b[1m"
#define GREEN   "\u001b[32m"
#define CYAN    "\u001b[36m"
#define YELLOW  "\u001b[33m"
#define int long long
using namespace std;
using namespace std::chrono;
int sieve[2000001];
main() {
    cout << GREEN << BOLD << "\n========== Program Start ==========" << RESET << "\n";

    auto start = high_resolution_clock::now();

    for(int i=0;i<=2000000;i++)
    {
        sieve[i]=1;
    }
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i*i<=2000000;i++)
    {
        if(sieve[i]==1)
        {
            for(int j=i*i;j<=2000000;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=2000000;i++)
    {
        if(sieve[i]==1)
        {
            ans+=i;
        }
    }
    cout<<ans<<endl;
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