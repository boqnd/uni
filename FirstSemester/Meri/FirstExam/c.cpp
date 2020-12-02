#include <iostream>
using namespace std;
int main()
{
    int n, flag=1;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++)
        cin>>nums[i];
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]>=nums[i+1])
            flag=0;
        for(int k=nums[i];k;k/=10)
        {
            if(k/10==0&&nums[i]%10!=k)
                flag=0;
        }
    }
    if(flag)
    {
        double average=0;
        for(int i=0;i<n;i++)
            average+=nums[i];
        cout<<"YES"<<endl<<average/n;
    }
    else
        cout<<"NO";
    return 0;
}