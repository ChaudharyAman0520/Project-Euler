#include <iostream>
#include <chrono>
#include <iomanip>
#include <unordered_map>
#define int long long

// ANSI color codes
#define RESET   "\u001b[0m"
#define BOLD    "\u001b[1m"
#define GREEN   "\u001b[32m"
#define CYAN    "\u001b[36m"
#define YELLOW  "\u001b[33m"

using namespace std;
using namespace std::chrono;
unordered_map<int,int> mp;
int calc(int n)
{
    int sum=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }
    return sum;
}
void build()
{
    for(int i=1;i<10000;i++)
    {
       mp[i]=calc(i);
    }
}
main() {
    cout << GREEN << BOLD << "\n========== Program Start ==========" << RESET << "\n";

    auto start = high_resolution_clock::now();

    // Your code here
    int sum=0;
    build();
    for(int i=1;i<10000;i++)
    {
        for(int j=i+1;j<10000;j++)
        {
            if(mp[i]==j&&mp[j]==i)
            {
                sum+=(i+j);
            }
        }
    }
    cout<<sum<<endl;

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