// two sum navie solution
 #include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;
void read_arr();
void print_arr(long long *a , long long index );
long long twosumpairs(long long *a , long long index)
{   
    cout<<"comming in this function";
    long long t = 4 , count =0;
    for(long long i =0;i<=index -1;i++) 
    {
        cout<<"\nposition "<<i;
        for(long long j =i+1;j<=index;j++) 
        if(a[i]+a[j] >= -10000 && a[i]+a[j] <= 10000) 
        count++;
    }
    return count;
} 
void read_arr()
{
    cout<<"\ncomming";
    
    long long  num = 0,index =-1;
    long long *a = (long long*)malloc(1000000*sizeof(long long));
    ifstream input;
    input.open("prob-2sum.txt");
    
    while (!input.eof())
    {
        
       input>>a[++index];
       cout<<"\nindex  "<<index;
    }
    long long count =  twosumpairs(a , index);
    cout<<"\ntotal count of  pairs is "<<count;
    // print_arr(a, index);
    return;
    
    

}
void print_arr(long long *a, long long index)
{
    for(long long i=0;i<=index;i++) cout<<a[i]<<"\n";

}
int main()
{
    cout<<"working";
    read_arr();
    
    return 0;

}



// hash table approach
/* #include<bits/stdc++.h>
using namespace std;
class HashTable
{
    private:
        static const int tablesize = 10;
        list<int> table[tablesize];
    public:
        bool isempty();
        int twosum(int T);
        int hashfunction(int key);
        void print_HT();

};

bool HashTable::isempty()
{
    //o(n)
    int sum =0 ;
    for(auto i = 0;i<tablesize;i++)  sum+=table[i].size();
    if(!sum) return true;
    return false;
}

int HashTable::twosum(int T)
{
    int num =0 , count  = 0;
    ifstream input;
    input.open("test.txt");
    while(!input.eof())
    {
        input>>num;
        int hashvalue = hashfunction(num);
        if(table[T-num].front() == (T-num)) count++;
        table[hashvalue].push_front(num); 


    }
    //we are done reading file and inserting values int the table of list
    return count;
}

int HashTable::hashfunction(int key)
{
    return key % 10; //key = 28 then table[8 th list]
}

void HashTable::print_HT()
{
    for(int i=0;i<tablesize;i++) 
    {
        cout<<i<<"--->";
        for(auto itr = table[i].begin();itr != table[i].end();itr++) cout<<*itr<<"\t";
        cout<<"\n";
    }



}



int main()
{
    HashTable HT;
    if(HT.isempty()) cout<<"good going"<<endl;
    int count = HT.twosum(8);
    cout<<"value of count is "<<count<<endl;
    return 0;
}
*/