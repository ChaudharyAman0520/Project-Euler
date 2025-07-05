#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
main()
{
    auto start = high_resolution_clock::now();
    int a=0,b=1,c;
    int ans=0;
    while(true)
    {
        c=a+b;
        a=b;
        b=c;
        if(c>4000000)
        {
            break;
        }
        if(c%2==0)
        {
            ans+=c;
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;
    cout<<ans<<endl;
}