#include<bits/stdc++.h>
using namespace std;
main()
{
    int ans=0;
    for(int i=1;i<1000;i++)
    {
        if(i%3==0||i%5==0)
        {
            cout<<i<<endl;
            ans+=i;
        }
    }
    cout<<ans<<endl;
}