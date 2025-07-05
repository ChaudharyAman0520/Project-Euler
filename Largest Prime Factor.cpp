#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
bool isPrime(long long n)
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
    for(long long i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)
        {
            return false;
        }
    }
    return true;
}
int main() {
    auto start = high_resolution_clock::now();

    long long n= 600851475143;
    long long ans=0;
    for(long long i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(isPrime(i))
            {
                ans=max(ans,i);
                if(isPrime(n/i))
                {
                    ans=max(ans,n/i);
                }
            }
        }
    }
    cout<<ans<<endl;
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}