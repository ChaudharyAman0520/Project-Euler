#include <iostream>
#include <chrono>

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

    long long a,b=0;
    a=(100*101)/2;
    a=a*a;
    b=(100*(101)*(201))/6;
    cout<<a-b<<endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << GREEN << BOLD << "\n========== Program End   ==========" << RESET << "\n";
    cout << CYAN << BOLD << "⏱️  Time taken: " << YELLOW << duration.count() << " ms" << RESET << "\n";
    cout << GREEN << "====================================\n" << RESET;

    return 0;
}