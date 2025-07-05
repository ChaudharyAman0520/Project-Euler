#include <bits/stdc++.h>
#include <chrono>
#include <numeric>
#define int long long
using namespace std;
using namespace std::chrono;

main() {
    auto start = high_resolution_clock::now();

    int ans=1;
    for(int i=2;i<=20;i++)
    {
        ans=(ans*i)/__gcd(ans,i);
    }
    cout<<ans<<endl;
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}