//try to find the kth-smallest element in the array
#include<bits/stdc++.h>

using namespace std;

int randomize_partition(int a[] , int last_index , int start_index)
{
    srand(time(0));
    int random_number = rand()%((last_index-start_index+1)+start_index);
    cout<<"\nrandom number "<<random_number;
    return random_number;
}
int partition(int a[] , int last_index , int start_index)
{
    
    int i = 0, j=start_index+1 ;
    // int random_index = randomize_partition(a , last_index,  start_index);
    // swap(a[start_index], a[random_index]);
    int  pivot = a[start_index];
    for(i=start_index+1;i<=last_index;i++)
    {
        if(a[i]<pivot) 
        {
            swap(a[j],a[i]);
            j++;
        }
    }
    swap(a[j-1],a[start_index]);

    return j-1;


}
int kth_smallest(int* a, int k  , int last_index  , int start_index)
{
    
    //find the pivot element
    int pivot_index = partition(a ,last_index , start_index);
    int size_l = pivot_index-start_index , size_r = last_index - pivot_index;
    if(k == size_l+1) return a[pivot_index];
    if(k <= size_l ) return kth_smallest(a , k , pivot_index-1, start_index);
    if (k > size_l+1) return kth_smallest(a , k-(size_l+1) ,last_index,pivot_index+1 );

}
int main()
{
    int a[10001] , size =0 , k=0, sum=0 ;
    for(int i=0;i<10000;i++) a[i] =0;
    int  result = 0;
    int index= -1;
    
    ifstream input;     
    input.open("Median.txt");
    string num;
    while(!input.eof())
    {
        result = 0;
        input>>num;

        a[++index] = stoi(num);
        size++; 
        k = (index)/2 ;
        result = kth_smallest(a,k+1,size-1, 0);
        cout<<"\nthe median numbers of  the array  is "<<result;
        sum+= result;
        
       
    }
    
    // sum = sum % 10000;
    cout<<"\nthe sum of the medians is"<<sum ;
    // for(int i=0;i<7;i++) cout<<a[i]<<"\t";
    return 0;
}




// if (size %2 == 1) 
        // {
        //     k = (size+1)/2; 
        //     result = kth_smallest(a , k, size-1, 0);
        // }
        // else 
        // {   
        //     k = (size)/2;
        //     int     result1 = kth_smallest(a,k,size-1,0);  
        //     // int result2 =  kth_smallest(a,k+1,size-1,0) ;
        //     // result = 0.5*(result1+result2);
        //     result = result1;
        // }
        