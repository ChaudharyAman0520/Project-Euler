#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
bool isPalin(int n)
{
    int rev=0,t=n;
    while(n!=0)
    {
        rev=(rev*10)+(n%10);
        n=n/10;
    }
    return rev==t;
}
int main() {
    auto start = high_resolution_clock::now();

    int ans=0;
    for(int i=999;i>=100;i--)
    {
        for(int j=i;j>=100;j--)
        {
            int prod=i*j;
            if(prod<=ans) 
            {
                break;
            }
            if(isPalin(prod))
            {
                ans=prod;
            }
        }
    }
    cout<<ans<<endl; 

    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}