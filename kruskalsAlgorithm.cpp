/*Assumptions - 1.there exist a spanning tree         => E > N-1  so we can say O(V+E) === O(E)
                2.there are no edges with same weight => hence every we can will not problem to identity 
                3.there                               => 

                */

#include<iostream>
using namespace std;
struct adjacencynode
{
    int vertex;
    int weight;
    adjacencynode *next;
};
struct adjacencylist
{
    int num_of_vertices;
    adjacencynode *head;
};
struct graph
{
    int totalvertices;
    adjacencylist *arr;

};
struct edge
{
    int src , des , weight;
};

struct graphedges
{
    int index;
    int totaledges;
    edge *arr;
};
graphedges* createedgearray(int size)
{
    graphedges *newgraphedges = new graphedges;
    newgraphedges->arr =  new edge[size+1];
    newgraphedges->index = 0;
    newgraphedges->totaledges = size;
    return newgraphedges;
}
adjacencynode* createnode(int vertex , int weight)
{
    adjacencynode *newnode = new adjacencynode;
    newnode->vertex = vertex;
    newnode->weight = weight;
    newnode->next = NULL;
    return newnode;
}

graph* creategraph(int totalvertices)
{
    //create new graph
    graph *g = new graph;
    g->arr = new adjacencylist[totalvertices+1]; //to counter that 0th vertex
    g->totalvertices = totalvertices;
    for(int i=0;i<totalvertices+1;i++)
    g->arr[i].head = NULL , g->arr[i].num_of_vertices = 0;
    return g;
}
void addgraphedges( graphedges *newgraphedges, int src , int des  , int weight )
{
    newgraphedges->index++;
    newgraphedges->arr[newgraphedges->index].src = src; 
    newgraphedges->arr[newgraphedges->index].des = des;
    newgraphedges->arr[newgraphedges->index].weight = weight;
}

void addedge(graph *g, int src , int des , int weight)
{
    //create edge
    adjacencynode *newnode = createnode(des , weight);
    newnode->next = g->arr[src].head;
    g->arr[src].head = newnode;
    g->arr[src].num_of_vertices++;

    //also add reversly if undirected graph
    adjacencynode *newbacknode = createnode(src , weight);
    newbacknode->next = g->arr[des].head;
    g->arr[des].head = newbacknode;
    g->arr[des].num_of_vertices++;


}
void printedges(graphedges *newgraphedges)
{
    cout<<"index value is "<<newgraphedges->index<<endl;
    for(int i=1;i<=newgraphedges->index;i++)
    cout<<" src "<<newgraphedges->arr[i].src<<" des "<<newgraphedges->arr[i].des<<" weight "<<newgraphedges->arr[i].weight<<endl;
}

void printgraph(graph *g)
{
    for(int i=1;i<g->totalvertices+1;i++)
    {
        cout<<i<<"---->";
        adjacencynode *temp = g->arr[i].head;
        while(temp!=NULL)
        {
            cout<<temp->vertex<<"("<<temp->weight<<")"<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
bool formcycle(edge e , bool *x)
{
    x[e.des] = true;
    x[e.src] = true;
    //1.run loop for all the vertices

    







    return true;
}
void kruskal(graph *g , graphedges *newgraphedges)
{
    //1.sort edges 
    sortedges(newgraphedges);
    int MinSpannigdistance = 0;
    bool *x = new bool[newgraphedges->index+1];
    //run loop for all edges
    for(int i=0;i<=newgraphedges->index;i++)
    {
        //check if edge is forming the loop or cycle
        if(!formcycle(newgraphedges->arr[i] , x))
        MinSpannigdistance += newgraphedges->arr[i].weight;
    
    }
    cout<<"the min spanning tree distane is "<<MinSpannigdistance;

}
void sortedges(graphedges *newgraphedges)
{
    for(int i=0;i<=newgraphedges->index;i++)
    {
        for(int j=0;j<=newgraphedges->index-1;j++)
        {
            if(newgraphedges->arr[j+1].weight < newgraphedges->arr[j].weight)
            swap(newgraphedges->arr[j] , newgraphedges->arr[j+1]);
        }
    }
}

main()
{
    int size = 4;
    graph *g = creategraph(size);
    addedge(g , 1,2,1);
    addedge(g , 1,3,4);
    addedge(g , 2,4,2);
    addedge(g , 2,3,5);
    addedge(g , 3,4,3);
    printgraph(g);
    graphedges *newgraphedges = createedgearray(5);
    addgraphedges(newgraphedges , 1 ,2,1);
    addgraphedges(newgraphedges , 1,3,4);
    addgraphedges(newgraphedges , 2,4,2);
    addgraphedges(newgraphedges ,3,4,3 );
    addgraphedges(newgraphedges ,2, 3, 2);
    printedges(newgraphedges);

    sortedges(newgraphedges);
    printedges(newgraphedges);
}