#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    map<string , int> map;
    map["keshav"] ++;
    map["nj"] ++;
    map["jj"] ++;

    for(auto itr = map.begin();itr != map.end();itr++)
    {
        cout<<itr->first<<"  "<<itr->second;
    }
    
    return 0;
}
