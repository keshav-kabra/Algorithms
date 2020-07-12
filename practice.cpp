#include<bits/stdc++.h>
using namespace std;
main()
{
    vector<int> bookpages;
    vector<int> result;
    int testcase , n , x ;
    int int_pages;
    cin>>testcase;
    string pages;
    int count = 0;
    while(testcase>0)
    {
        cin>>n;
        cin>>x;
        cin.ignore();
        getline(cin , pages) ;
        stringstream ss(pages);
        while(ss>>int_pages)
        {
            bookpages.push_back(int_pages);
        }


        // for(int i=0;i<n;i++)
        // {
        //     int pages = 0;
        //     cin>>pages;
        //     bookpages.push_back(pages);
        // }
        //print the pages 
        // for(int i=0;i<n;i++) cout<<bookpages[i]<<endl;

        for(int i=0;i<n;i++) if(bookpages[i] < x) count++;
        for(int i=0;i<n;i++)
        for(int j=i;j<n;j++) 
        if(bookpages[i] * bookpages[j] < x && bookpages[i] != bookpages[j] ) count++;
        cout<<count<<endl;
        testcase--;
    }
}