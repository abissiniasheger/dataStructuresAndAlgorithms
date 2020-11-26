#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct  Node* left;
	struct  Node* right;
	struct Node* parent;
}Node;

Node* createNewNode(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	
	return newNode;
}

Node* root = NULL;

Node* buildMaxHeap(Node* root);

void pickTheLastNode(Node* root, int indexOfLastNode, int rootIndex, Node** lastNode);

void maxHeapifyLeftSubtree(Node** leftTree);
void maxHeapifyRightSubtree(Node** rightTree);
void doComparison(Node** test);
int main()
{
	int unsortedArray[] = {1, 12, 9, 5, 6, 10, 2, 30, 50, 70, 15, 20, 80, 300, 1000, 100, -2, 44, 25};
	int length = sizeof(unsortedArray)/sizeof(unsortedArray[0]);
	printf("%d\n", length);
	
	int depth = 2; // floor(length(unsortedArray)/2)
	
	// Create the root node
	
	root = createNewNode(unsortedArray[0]);
	Node* curr = root;
	//Node* prev = NULL;
	
	//int index = 0;
	
	// Build the left subtree
	// The limit of the for loop should be replaced by the lenght of the array
    /*
    for (int i = 1; i <= 5; i = 2*i + 1)
	{
		Node* newNode = createNewNode(unsortedArray[i]);
		curr->left = newNode;
		newNode->parent = curr;
		//prev = curr;
		curr = newNode;
		index = i;
	}
	
	// Back track to the root node and fill in the right nodes
	while (curr != root)
	{
		int tmp = 2*index + 2;
		if (tmp <= 5)// should be chenged into the length of the array
		{
			Node* newNode = createNewNode(unsortedArray[tmp]);
			curr->right = newNode;
			newNode->parent = curr;
		}
        curr = curr->parent;
        index = (index - 1)/2;	
	}
	
	// Reset the index
	index = 0;
	
	// Build the right subtree
	// The limit of the for loop should be replaced by the lenght of the array
    
    for (int i = 2; i <= 5; i = 2*i + 2)
	{
		Node* newNode = createNewNode(unsortedArray[i]);
		curr->right = newNode;
		newNode->parent = curr;
		//prev = curr;
		curr = newNode;
		index = i;
	}
	
	// Back track to the root node and fill in the left nodes
	while (curr != root)
	{
		int tmp = 2*index + 1;
		if (tmp <= 5)// should be chenged into the length of the array
		{
			Node* newNode = createNewNode(unsortedArray[tmp]);
			curr->left = newNode;
			newNode->parent = curr;
		}
        curr = curr->parent;
        index = (index - 2)/2;	
	}*/
	
	int index = 0;
	
	// Build the left subtree
	// The limit of the for loop should be replaced by the lenght of the array
    
    for (int i = 1; i < length; i = 2*i + 1)
	{
		Node* newNode = createNewNode(unsortedArray[i]);
		curr->left = newNode;
		newNode->parent = curr;
		//prev = curr;
		curr = newNode;
		index = i;
	}
	
	// Back track to the root node and fill in the right nodes
	while (curr != root)
	{
		int tmp = 2*index + 2;
		if (tmp < length)// should be chenged into the length of the array
		{
			Node* newNode = createNewNode(unsortedArray[tmp]);
			curr->right = newNode;
			newNode->parent = curr;
		}
		// check if the right node has children
		// check if the node has a left child
		
		if (tmp*2 + 1 < length)
		{
		    Node* newNode = createNewNode(unsortedArray[tmp * 2 + 1]);
			curr->right->left = newNode;
			newNode->parent = curr->right;
		}
		
		// check if the node has a right child
		
		if (tmp*2 + 2 < length)
		{
		    Node* newNode = createNewNode(unsortedArray[tmp * 2 + 2]);
			curr->right->right = newNode;
			newNode->parent = curr->right;
		}
        curr = curr->parent;
        index = (index - 1)/2;	
	}
	
	// Reset the index
	index = 0;
	
	// Build the right subtree
	// The limit of the for loop should be replaced by the lenght of the array
    
    for (int i = 2; i < length; i = 2*i + 2)
	{
		Node* newNode = createNewNode(unsortedArray[i]);
		curr->right = newNode;
		newNode->parent = curr;
		//prev = curr;
		curr = newNode;
		index = i;
	}
	
	// Back track to the root node and fill in the left nodes
	while (curr != root)
	{
		int tmp = 2*index + 1;
		if (tmp < length)// should be chenged into the length of the array
		{
			Node* newNode = createNewNode(unsortedArray[tmp]);
			curr->left = newNode;
			newNode->parent = curr;
		}
		// check if the right node has children
		// check if the node has a left child
		
		if (tmp*2 + 1 < length)
		{
		    Node* newNode = createNewNode(unsortedArray[tmp * 2 + 1]);
			curr->left->left = newNode;
			newNode->parent = curr->left;
		}
		
		// check if the node has a right child
		
		if (tmp*2 + 2 < length)
		{
		    Node* newNode = createNewNode(unsortedArray[tmp * 2 + 2]);
			curr->left->right = newNode;
			newNode->parent = curr->left;
		}
        curr = curr->parent;
        index = (index - 2)/2;	
	}

    int indexOfLastNode = length - 1;
    int sortedArray[19] = {};
    
    
    while (indexOfLastNode > 0)
    {
        Node* lastNode = NULL;
        root = buildMaxHeap(root);
	    pickTheLastNode(root, indexOfLastNode, 0, &lastNode);
	
	    //printf("%d\n", lastNode->value);
	
	    // swap the first and last node values
	    int tmp = root->value;
	    root->value = lastNode->value;
	    lastNode->value = tmp;
	    sortedArray[indexOfLastNode] = lastNode->value;
	    // remove last node
	    if (indexOfLastNode %2 != 0)
	    {
	       lastNode->parent->left = NULL; 
	    }
	    else
	    {
	        lastNode->parent->right = NULL;
	    }
	    
	    lastNode->parent = NULL;
	    free(lastNode);
        indexOfLastNode--;
    }

	sortedArray[indexOfLastNode] = root->value;
	//printf("%d", root->value);
	/*
	root = buildMaxHeap(root);
	printf("%d\n", root->value);
	
	
	curr = root;
	 int i = 0;
	 int sortedArray[12] = {};
    // Traverse till the end of the left tree
	 while(curr->left != NULL)
	 {
		 curr = curr->left;
		 i = 2 * i + 1;
	 }
	 
	 // Fill in the left tree in to the sortedArray
	 
	 while(curr != root)
	 {
		 if (curr->right != NULL)
		 {
		     int k = 2 * i + 2;
			 sortedArray[k] = (curr->right)->value;
			 if (2*k + 1 <= length)
			 {
			     sortedArray[2*k + 1] = curr->right->left->value;
			 }
			 
			 if (2*k + 2 <= length)
			 {
			     sortedArray[2*k + 2] = curr->right->right->value;
			 }
		 }
		 
		 sortedArray[i] = curr->value;
		 curr = curr->parent;
		i = (i - 1)/2;
	 }
	
	// Traverse till the end of the right tree
	 while(curr->right != NULL)
	 {
		 curr = curr->right;
		 i = 2 * i + 2;
	 }
	 // Fill in the right tree in to the sortedArray
	 
	 while(curr != root)
	 {
		 if (curr->left != NULL)
		 {
		     int k = 2 * i + 1;
			 sortedArray[k] = (curr->left)->value;
			 if (2*k + 1 < length) // change with the length of the array
			 {
			     sortedArray[2*k + 1] = curr->left->left->value;
			 }
			 
			 if (2*k + 2 < length)
			 {
			     sortedArray[2*k + 2] = curr->left->right->value;
			 }
		 }
		 
		 sortedArray[i] = curr->value;
		 curr = curr->parent;
		i = (i - 2)/2;
	 }
	 
	sortedArray[i] = root->value;

	*/
    for (int k = 0; k < length; k++)
	{
		printf("%d ", sortedArray[k]);
	}

	
	return 0;
}


Node* buildMaxHeap(Node* root)
{
	// Build max heap for the left tree
	maxHeapifyLeftSubtree(&(root->left));
	// Build max heap for the right tree
	maxHeapifyRightSubtree(&(root->right));
	
/*
Node* curr = root;
	
	// Traverse till the end of the left tree
	
	while(curr->left != NULL)
	{
		curr = curr->left;
	}
	
	//printf("%d\n", curr->value);

// Backtarck to the root node turning each subtree into max heap
	
	while(curr != root)
	{
		if (curr->right != NULL && curr->left != NULL)
		{
			if(curr->value < curr->left->value && curr->left->value > curr->right->value)
			{
				int tmp = curr->left->value;
				curr->left->value = curr->value;
				curr->value = tmp;				
			}
			
			if(curr->value < curr->right->value && curr->left->value < curr->right->value)
			{
				int tmp = curr->right->value;
				curr->right->value = curr->value;
				curr->value = tmp;				
			}
		}
		
		if (curr->left != NULL && curr->right == NULL &&
		    curr->value < curr->left->value)
		{
			int tmp = curr->left->value;
            curr->left->value = curr->value;
            curr->value = tmp;			
		}
		
		if (curr->right != NULL && curr->left == NULL &&
		    curr->value < curr->right->value)
		{
			int tmp = curr->right->value;
            curr->right->value = curr->value;
            curr->value = tmp;			
		}
		
		curr = curr->parent;
	}



// Traverse till the end of the right tree
	
	while(curr->right != NULL)
	{
		curr = curr->right;
	}
	
	// Backtarck to the root node turning each subtree into max heap
	
	while(curr != root)
	{	
		if (curr->right != NULL && curr->left != NULL)
		{
			if(curr->value < (curr->left)->value)
			{
				int tmp = curr->left->value;
				curr->left->value = curr->value;
				curr->value = tmp;				
			}
			
			if(curr->value < (curr->right)->value)
			{
				int tmp = curr->right->value;
				curr->right->value = curr->value;
				curr->value = tmp;				
			}
		}
		
		if (curr->left != NULL && curr->right == NULL &&
		    curr->value < curr->left->value)
		{
			int tmp = curr->left->value;
            curr->left->value = curr->value;
            curr->value = tmp;			
		}
		
		if (curr->right != NULL && curr->left == NULL &&
		    curr->value < curr->right->value)
		{
			int tmp = curr->right->value;
            curr->right->value = curr->value;
            curr->value = tmp;			
		}
		
		curr = curr->parent;
	}
*/
	
	if (root->left != NULL && root->right == NULL &&
		root->value < root->left->value)
	{
		int tmp = root->left->value;
        root->left->value = root->value;
        root->value = tmp;			
	}
	
	if (root->right != NULL && root->left == NULL &&
	    root->value < root->right->value)
	{
		int tmp = root->right->value;
        root->right->value = root->value;
        root->value = tmp;			
	}
	if (root->right != NULL && root->left != NULL)
	{
		if(root->value < (root->left)->value && (root->left)->value > (root->right)->value )
		{
			int tmp = root->left->value;
			root->left->value = root->value;
			root->value = tmp;				
		}
		
		if(root->value < (root->right)->value && (root->right)->value > (root->left)->value)
		{
			int tmp = root->right->value;
			root->right->value = root->value;
			root->value = tmp;				
		}
	}
		
    return root;	
}

/*
Node* pickTheLastNode(Node* root, int indexOfLastNode, int rootIndex, Node** lastNode)
{
    int indexOfParent = indexOfLastNode;
	int index = 0;
	Node* curr = root;
   
   while (indexOfParent != 1 && indexOfParent != 2)
   {
	   if (indexOfParent %2 == 0)
	   {
		   indexOfParent = (indexOfParent - 2)/2;
	   }
	   else
	   {
		   indexOfParent = (indexOfParent - 1)/2;
	   }
   }
    if (indexOfParent == 2 && root->right != NULL)
	{
		// Traverse the RIGHT subtree until the last node is found
		curr = root->right;
		
		if (indexOfLastNode %2 == 0)
		{
			
			while (curr->right != NULL)
			{
				curr = curr->right;
			}
		}
        else
        {
			while (curr->left != NULL)
			{
				curr = curr->left;
			}
		}			
	}
	
	if (indexOfParent == 1 && root->left != NULL)
	{
		// Traverse the left subtree until the last node is found
		curr = root->left;
		
		if (indexOfLastNode %2 == 0)
		{
			
			while (curr->right != NULL)
			{
				curr = curr->right;
			}
		}
        else
        {
			while (curr->left != NULL)
			{
				curr = curr->left;
			}
		}			
	}
    return curr;


}

*/

void pickTheLastNode(Node* root, int indexOfLastNode, int rootIndex, Node** lastNode)
{
    int tmp = rootIndex;
    if (root == NULL)
    {
        return;
    }
    pickTheLastNode(root->left, indexOfLastNode, rootIndex*2 + 1, lastNode);
    
    if (rootIndex == indexOfLastNode)
    {
        *lastNode = root;
    }
    pickTheLastNode(root->right, indexOfLastNode, rootIndex*2 + 2, lastNode);
}
void maxHeapifyLeftSubtree(Node** leftTree)
{
    Node* testLeft = *leftTree;
    if (testLeft == NULL)
    {
        return;
    }
    maxHeapifyLeftSubtree(&(testLeft->left));
    maxHeapifyLeftSubtree(&(testLeft->right));
    doComparison(&testLeft);
}

void maxHeapifyRightSubtree(Node** rightTree)
{
    Node* testRight = *rightTree;
    if (testRight == NULL)
    {
        return;
    }
    maxHeapifyRightSubtree(&(testRight->right));
    maxHeapifyLeftSubtree(&(testRight->left));
    doComparison(&testRight);
}
void doComparison(Node** test)
{
    Node* curr = *test;
    if (curr->right != NULL && curr->left != NULL)
	{
		if(curr->value < (curr->left)->value && (curr->left)->value > (curr->right)->value )
		{
			int tmp = curr->left->value;
			curr->left->value = curr->value;
			curr->value = tmp;				
		}
		
		if(curr->value < (curr->right)->value && (curr->right)->value > (curr->left)->value)
		{
			int tmp = curr->right->value;
			curr->right->value = curr->value;
			curr->value = tmp;				
		}
	}
	
	if (curr->left != NULL && curr->right == NULL &&
	    curr->value < curr->left->value)
	{
		int tmp = curr->left->value;
        curr->left->value = curr->value;
        curr->value = tmp;			
	}
	
	if (curr->right != NULL && curr->left == NULL &&
	    curr->value < curr->right->value)
	{
		int tmp = curr->right->value;
        curr->right->value = curr->value;
        curr->value = tmp;			
	}
}