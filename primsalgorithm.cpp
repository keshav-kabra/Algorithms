#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
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

int minedge(graph *g , bool *x)
{
    //a[i] == *(a+i)

    int minedgelength = INT_MAX;
    int vertex;
    for(int i= 1;i<g->totalvertices+1;i++)  //complexity of O(V+E)
    {
        if(x[i] == true )
        {
            adjacencynode *temp = g->arr[i].head;
            while(temp!=NULL)
            {
                if(temp->weight < minedgelength && x[temp->vertex] == false)
                {
                    minedgelength = temp->weight;
                    vertex = temp->vertex;
                }
                temp = temp->next;
            }
        }

    }
    x[vertex] = true;
    return minedgelength;
}

void prims(graph *g , int start_vertex)
{
    int edgedistance;
    bool *x = new bool[g->totalvertices+1];
    for(int i=1;i<g->totalvertices+1;i++) x[i] = false ;

    x[start_vertex] = true;
    int MinSpanningTree = 0;

    for(int i=1;i<g->totalvertices;i++)
    {
        edgedistance = minedge(g,x);
    

        MinSpanningTree += edgedistance; 
        //set that vertice true
    }
    cout<<"MinSpanningTree value is "<<MinSpanningTree;

    

   
}
void readgraph(graph *g)
{
    bool first = true;
    string line;
    ifstream input;
    input.open("prims.txt");
    while(getline(input , line))
    {
        int weight =0 , src=0 , des=0 ;
        stringstream ss(line);
        if(first == true) first = false;
        else
        {
            ss>>src;
            ss>>des;
            ss>>weight;
            addedge(g , src , des , weight);

            
        }
    }
    input.close();
}

main()
{
    //1.create graph
    // graph *g = creategraph(4);
    // addedge(g , 1, 2, 1);
    // addedge(g,1,3,4);
    // addedge(g,2,4,2);
    // addedge(g,2,3,1);
    // addedge(g,3,4,3);
    // printgraph(g);
    // prims(g , 2);
    ifstream input;
    int size;
    input.open("prims.txt");
    bool run = true;
    while(run)
    {
        input>>size;
        run = false;
    }
    graph *g = creategraph(size);
    readgraph(g);
    // printgraph(g);   
    prims(g ,1);
}




