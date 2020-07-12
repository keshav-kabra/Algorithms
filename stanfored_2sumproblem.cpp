#include<bits/stdc++.h>
using namespace std;

 long long binarysearch(long long *a , long long start ,long long end  ,long long value_to_find , int i)
 {
    long long mid ; 
                while(start <= end)
                {
                    mid = (end - start)/2 + start;
                    if(a[mid] == value_to_find)
                    {
                        // cout<<"ith value is"<<a[i]<<endl;
                        // cout<<value_to_find<<"\n";
                        return 1; 
                    }
                    else if(a[mid] < value_to_find)
                    {
                        start = mid + 1; mid = (end - start) / 2 + start;
                    }
                    else if(a[mid] > value_to_find)
                    {
                        end = mid - 1; mid = (end - start) / 2 + start;
                    }
                }    
                return 0;
 }
long long calculatesum(long long *a , long long index , long long firstpositiveindex )
{
    long long start = 0 , end  = index , mid = (end-start)/2+start;
    long long count = 0;
    long long temp = 0;

    for(int t= -10000;t<=10000;t++)
    {
        for(int i =0; i<=index;i++)
        {
            while(a[i] == a[i+1]) i++;  
            long long value_to_find = t - a[i]; 
            //find complement of a[i] if exist then count ++
            // for(int j=i+1;j<=index;j++)
            // if(a[j] == value_to_find) count++;
            start = i+1;
            count += binarysearch(a,start , end,value_to_find , i);
            if(count>temp) 
            {
                temp = count;
                break;
            }
                      
        }
        cout<<" t th value "<<t<<endl;
    }
    return count;
        
}
long long twosum()
{
    int firstPositiveIndex = 0;
    long long *a = (long long*)malloc(1000000*sizeof(long long)); 
    long long  index = -1;
    ifstream input;
    input.open("prob-2sum.txt");
    while(!input.eof())
    {
        
        input>>a[++index];
    }
    cout<<"[GOOD JOB..!!] reading done"<<endl;
    //sort the array
    sort(a , a+index+1);
    cout<<"[GOOD JOB..!!] array sorted"<<endl;

    //find first positive index
    for(int i = 0; i <= index; i++)
    {
        if(a[i] + a[i + 1] > a[i])
        {
            firstPositiveIndex= ++i;
            break;
        }
    }
    long long count =calculatesum(a,index , firstPositiveIndex);
    return count;

}
main()
{
    int count = twosum(); 
    cout<<"total number of pairs are "<<count;
}











               
