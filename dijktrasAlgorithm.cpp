#include<iostream>
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
    g->adjacencylistarr = (adjacencylist*)malloc((n+1)*sizeof(adjacencylist));
    if(!g->adjacencylistarr)   
    {
        cout<<"cant allocate memory ..!";
        exit(0);
    }
    for(int i =0;i<n+1;i++) 
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
    for(int i=0;i<=g.num_vertices;i++)
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

int mindistance(int *distance , bool *x , int size)
{
    int min = INT_MAX , index;
    for(int i=1;i<=size;i++)
    {
        if(x[i] == false && distance[i] <  min)
        min = distance[i],index = i ;

    }
    return index;
}
void printdistances(int distance[] , int size)
{
    for(int i=1;i<= size;i++)
    cout<<"vertex "<<i<<"distance "<<distance[i]<<endl;

}

void dijktras(graph *g , int src)
{
    //declare sets
    
    bool *x = (bool*)malloc((g->num_vertices+1)*sizeof(bool));
    int *distance = (int*)malloc((g->num_vertices+1)*sizeof(int));
    for(int i=1;i<=g->num_vertices;i++) x[i] = false,distance[i] = INT_MAX;


    distance[src] = 0;
    for(int i=1; i<= g->num_vertices;i++)
    {
        int u = mindistance(distance , x , g->num_vertices);
        x[u] = true;
        cout<<u <<" is set true"<<endl;
        
        //now visit adjacency nodes and update distances
        adjacencynode *temp = g->adjacencylistarr[u].head;
        while(temp != NULL)
        {
            int v = temp->vertex;
            if(x[v] == false && x[u] != INT_MAX && (distance[u] + temp->distance) < distance[v] )
            {
                distance[v] = distance[u] + temp->distance; 
                cout<<"edge value is "<<temp->distance<<endl; 
            }

            temp = (*temp).next;
            //print distance of every vertex


        }


    }

    printdistances(distance, g->num_vertices);
}

int main()
{
    graph *g = creategraph(6);
   
    // displaygraph(*g);
    dijktras(g ,4 );
    return 0;    
}