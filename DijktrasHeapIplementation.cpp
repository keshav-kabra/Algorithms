#include<bits/stdc++.h>
using namespace std;
struct adjacencynode
{
    int vertex;
    int distance;
    adjacencynode *next;
};
struct adjacencylist
{
    int num_members;
    adjacencynode *head;
};
struct graph
{
    int num_vertices;
    adjacencylist *adjacencylistarr;
};

adjacencynode* createnode(int d , int v)
{
    adjacencynode *newnode = new adjacencynode();
    newnode->distance = d;
    newnode ->vertex = v;
    newnode ->next = NULL;
    return newnode;
}


graph* creategraph(int n)
{
    graph *g = (graph*)malloc(1*sizeof(graph));
    g->num_vertices = n;
    g->adjacencylistarr = (adjacencylist*)malloc((n)*sizeof(adjacencylist));
    if(!g->adjacencylistarr)   
    {
        cout<<"cant allocate memory ..!";
        exit(0);
    }
    for(int i =0;i<n;i++) 
    {
        g->adjacencylistarr[i].head = NULL;
        g->adjacencylistarr[i].num_members = 0;
    }
    return g;
}

void addedge(graph *g,int src , int des , int distance )
{
    adjacencynode *newnode = createnode(distance , des);
    newnode->next = g->adjacencylistarr[src].head;
    g->adjacencylistarr[src].head = newnode;
    g->adjacencylistarr[src].num_members++;

    //for des to src
    adjacencynode *newnodeback = createnode(distance , src);
    newnodeback ->next = g->adjacencylistarr[des].head;
    g->adjacencylistarr[des].head = newnodeback;
    g->adjacencylistarr[des].num_members++;

}

void displaygraph(graph g)
{
    for(int i=0;i<g.num_vertices;i++)
    {
        adjacencynode *list = g.adjacencylistarr[i].head;
        if(list == NULL) continue;
        cout<<i<<"---->";       
        while(list!=NULL)
        {
            cout<<list->vertex<<"\t";
            list = list ->next;
        }
        cout<<endl;
    }

}

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
heapnode* createheapnode(int vertex , int distance)
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
    swap(minbinaryheap->arr[0] , minbinaryheap->arr[minbinaryheap->size-1]);
    swap(minbinaryheap->map[0] , minbinaryheap->map[minbinaryheap->size-1]);

    minbinaryheap->size--;
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
bool isempty(MinBinaryHeap *minbinaryheap)
{
    return minbinaryheap->size == 0;
}
bool isInMinHeap(struct MinBinaryHeap *minbinaryheap, int v) 
{ 
   if (minbinaryheap->map[v] < minbinaryheap->size) 
     return true; 
   return false; 
} 
void  dijktras(graph *g , int src)
{
    //1.create dist array
    int *dist = new int[g->num_vertices];
    int vertices = g->num_vertices;

    //2.create min heap
    MinBinaryHeap *minbinaryheap = createheap(g->num_vertices);

    //3. initialize the values
    for(int i=0;i<g->num_vertices;i++) //6
    {
        dist[i] = INT_MAX;
        minbinaryheap->arr[i] = *(createheapnode(i , dist[i])); 
        minbinaryheap->map[i] = i;
    }

    //4.update distance of source vertex
    dist[src] = 0;
    minbinaryheap->arr[src] = *createheapnode(src , dist[src]);
    minbinaryheap->map[src] = src;
    minbinaryheap->size = vertices;
    decreasevalue(minbinaryheap , src , dist[src]);

    //5. run while loop till heap is empty and take out an edge every time
    while(minbinaryheap->size != 0  )
    {

        heapnode minnode = extractmin(minbinaryheap);
        int u = minnode.vertex;
        cout<<" current vertex "<<u<<endl;
        adjacencynode *temp = g->adjacencylistarr[u].head;
        while(temp != NULL)
        {
            int v = temp->vertex;
            cout<<"checking vertex "<<v<<" distance to compare "<<dist[v]<<" and "<<dist[u] +temp->distance <<endl;
            if(dist[u] +temp->distance < dist[v] && dist[u] != INT_MAX )
            {
                dist[v] = dist[u]+temp->distance;
                cout<<"distance of node "<<v<<" updated to "<<dist[v]<<endl;
                decreasevalue(minbinaryheap , v , dist[v]);
              


            }
            temp = temp->next;
        }

    }
   
    for(int i=0;i<g->num_vertices;i++) cout<<"vertex "<<i<<"distance "<<dist[i]<<endl;
}

main()
{
    //1. create graph
    graph *g = creategraph(6);
    //2. add edges to the graph
    addedge(g, 0, 1, 1); 
    addedge(g, 0, 2, 3); 
    addedge(g, 1, 3, 5); 
    addedge(g, 2, 4, 1); 
    addedge(g, 3, 4, 1); 
    addedge(g, 3, 5, 1); 
    addedge(g, 4, 5, 6);
    addedge(g , 1, 2,1); 
   
    displaygraph(*g);
    dijktras(g , 0);

    
}