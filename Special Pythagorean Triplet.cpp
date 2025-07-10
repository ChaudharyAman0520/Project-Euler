#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
// ANSI color codes
#define RESET   "\u001b[0m"
#define BOLD    "\u001b[1m"
#define GREEN   "\u001b[32m"
#define CYAN    "\u001b[36m"
#define YELLOW  "\u001b[33m"

using namespace std;
using namespace std::chrono;

int main() {
    cout << GREEN << BOLD << "\n========== Program Start ==========" << RESET << "\n";

    auto start = high_resolution_clock::now();

    for(int i=1;i<=998;i++)
    {
        for(int j=i+1;j<=999;j++)
        {
            cout<<sqrt((i*i)+(j*j));
            int c=sqrt((i*i)+(j*j));
            if(i+j+c==1000&&c>j)
            {
                cout<<"i = "<<i<<" j = "<<j<<" c = "<<c<<endl;
                cout<<i*j*c<<endl;
                break;
            }
        }
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