//MinBinaryHeap 
/* operations to performs : 1- extract min
                            2- add a node in O(1) time 
                            3- define extract min and heapify function O(logn)
                            4- decrease key (for this we need to modify out datastructure little)*/

                                        

#include<iostream>
using namespace std;
struct heapnode
{
    int  vertex;
    int distance;
    
};
struct MinBinaryHeap
{
    int size;  
    int *map;  
    heapnode *arr;
};
heapnode* createnode(int vertex , int distance)
{
    heapnode *newnode = new heapnode;
    newnode->distance  = distance;
    newnode ->vertex  = vertex;  

    return newnode;

}
MinBinaryHeap* createheap(int size)
{
    MinBinaryHeap *minbinaryheap = new MinBinaryHeap;
    minbinaryheap->size = size;
    minbinaryheap->arr = new heapnode[size]; //to counter that 0th index position 
    minbinaryheap->map = new int[size]; //index position coresponds to vertex and int value to position of vertex in the heap
    return minbinaryheap;

}

void printheap(MinBinaryHeap *minbinaryheap)
{
    for(int i = 0; i<minbinaryheap->size;i++)
    {
        cout<<"vertex : "<<minbinaryheap->arr[i].vertex <<" distance is :"<<minbinaryheap->arr[i].distance<<endl;
    }

}
void printheapmap(MinBinaryHeap *minbinaryheap)
{
    for(int i= 0;i<5;i++)
    {
        cout<<"vertex "<<i<<" position in heap"<<minbinaryheap->map[i]<<endl;
    }
}

void heapify(MinBinaryHeap *minbinaryheap , int start_index)
{
    //we can find end index from minheap itself
    
    int last_index = minbinaryheap->size-1;
    int dad = start_index;
    int son = 2*dad + 1;
    while(son <= last_index )
    {
        if(son+1 <= last_index && minbinaryheap->arr[son+1].distance < minbinaryheap->arr[son].distance)  son++;
        if(minbinaryheap->arr[dad].distance > minbinaryheap->arr[son].distance)
        {
            swap( minbinaryheap->arr[dad], minbinaryheap->arr[son]);
            //update position in map for every swapping
            swap(minbinaryheap->map[son] , minbinaryheap->map[dad]);
        }
        dad++;
        son = 2*dad +1;
        
    }

   

}

heapnode extractmin(MinBinaryHeap *minbinaryheap)
{
    //take out the first node of the heap
    heapnode minnode = (minbinaryheap->arr[0]);
    swap(minbinaryheap->arr[0] , minbinaryheap->arr[minbinaryheap->size -1]);
    minbinaryheap->size --;
    heapify(minbinaryheap , 0);
    return minnode;
}

void decreasevalue(MinBinaryHeap *minbinaryheap , int vertex , int distance)
{
    //1.find the postion of the node in heap
    int i = minbinaryheap->map[vertex];
    //update the distance at that position
    minbinaryheap->arr[i].distance = distance; 

    //satisfy heap property again
    
    while(i && minbinaryheap->arr[(i-1)/2].distance > minbinaryheap->arr[i].distance)  //if parent > child then swap
    {
        swap(minbinaryheap->arr[(i-1)/2] , minbinaryheap->arr[i]);
        swap(minbinaryheap->map[i] , minbinaryheap->map[(i-1)/2]);
        //update parent and child and respective positions in the 
        i = (i-1)/2;

    }    


}
main()
{
    //create a binary a heap
    MinBinaryHeap *minbinaryheap = createheap(5);
    minbinaryheap->arr[0] = *(createnode(0 , 3));
    minbinaryheap->arr[1] = *(createnode(1 , 2));
    minbinaryheap->arr[2] = *(createnode(2 , 5));
    minbinaryheap->arr[3] = *(createnode(3 , 6));
    minbinaryheap->arr[4] = *(createnode(4 , 7));
    
    //assign the positions in map
    for(int i=0;i<minbinaryheap->size;i++)
    minbinaryheap->map[i] = i;


    //printing heap
    printheap(minbinaryheap);
    printheapmap(minbinaryheap);
    heapify(minbinaryheap , 0);

    
    
    //decrease key
   printheap(minbinaryheap);
   printheapmap(minbinaryheap);
   
   decreasevalue(minbinaryheap , 2 , 1);
   cout<<"printing after decresing value "<<endl;
    printheap(minbinaryheap);
    printheapmap(minbinaryheap);
   



}