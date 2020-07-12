#include<iostream>
using std::cout; 
using std::cin;
using std::swap;
using std::endl;
struct huffmannode
{
	int key;
	int weight;
	huffmannode *left , *right;
};
void max_heapify(huffmannode *huffmanNode , int start , int end)
{
	
	int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && huffmanNode[son].weight < huffmanNode[son + 1].weight)
            son++;
        if (huffmanNode[dad].weight > huffmanNode[son].weight)
            return;
        else {
            swap(huffmanNode[dad], huffmanNode[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heapsort(huffmannode *huffman , int lastindex)
{
	for(int i= (lastindex-1)/2 ; i>=0;i--)
		max_heapify(huffman , i , lastindex);
	for(int i = lastindex ;i>=0;i--)
	{
		swap(huffman[0] , huffman[i]);
		max_heapify(huffman , 0, i-1);
	}
}

int findmax(huffmannode *huffman)
{
	if(huffman->left == NULL && huffman->right == NULL)
	return 0;
	else
	{
		int left = findmax(huffman->left);
		int right = findmax(huffman->right);
		if(left>right) return left+1;
		else return right+1;
	}
	
}
void printtree(huffmannode *huffman)
{
	if(huffman->right ==NULL && huffman->left ==NULL) return;
	//do inorder traversal
	cout<<huffman->weight;
	printtree(huffman->left);
	printtree(huffman->right);
}	
int findmin(huffmannode *huffman)
{
	if(huffman->left == NULL && huffman->right ==NULL)
	return 0;
	else
	{
		int left = findmin(huffman->left);
		int right = findmin(huffman->right);
		if(left < right) return left +1;
		else return right +1;
	}
}
		

main()
{
	int size = 4;
	int key , weight;
	huffmannode *huffman = new huffmannode[size];
	for(int i=0;i<size;i++)
	{
		
		huffman[i].key =  i;
		
		cin>>weight;
		huffman[i].weight = weight;
		huffman[i].left = huffman[i].right = NULL;
	}
	//heap sort
	heapsort(huffman , size-1); // we will pass the last index of the arr to the heap...

	int index = size-1;
	while(index != 0)
	{
		//1.create two new nodes
		huffmannode *node1 = new huffmannode;
		huffmannode *node2 = new huffmannode;
		*node1 = huffman[0];
		*node2 = huffman[1];
		huffman[0].key = 0;
		huffman[0].weight = node1->weight+node2->weight;
		huffman[0].left = node1;
		huffman[0].right= node2;
		swap(huffman[index] , huffman[1]);
		index--;
		heapsort(huffman , index);

	} 
	//print tree

	
	int max = findmax(huffman);
	int min = findmin(huffman);
	cout<<"max lenght of the encoding  is "<<max;
	cout<<"min lenght of the encoding  is "<<min;
}