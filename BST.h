// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode_R(TreeNodePtr * t,int value){
  if((*t)==NULL){
   (*t)=(TreeNodePtr)malloc(sizeof(struct TreeNode));
	 if(*t){
		(*t)->leftPtr=NULL;
		(*t)->rightPtr=NULL;
		(*t)->data=value;
   }
   else printf("%d not inserted. No memory available.\n",value);
  }
  else{
     if((*t)->data>=value) insertNode_R(&(*t)->leftPtr,value);
        
     else insertNode_R(&(*t)->rightPtr,value);
      
   }
}

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){//new_node!=NULL
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
   }
		/*First Node*/
		if(!b->root)/*b->root!=NULL*/	b->root=new_node;
		else {
while(!inserted){//loop continue as long as inserted=0
   if(t->data >=value){
     /* move/insert to the left*/
      if(!t->leftPtr){
         t->leftPtr=new_node;
         inserted=1;
      }
      else
         t=t->leftPtr;
     }
  	 
   else{
	      /* move/ insert to the right*/
      if(!t->rightPtr){
         t->rightPtr=new_node;
         inserted=1;
      }
      else{
         t=t->rightPtr;
      }
    }
	
   
  }//end while		
  }//end else;
  b->size++;
  }//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
      inOrder( treePtr->leftPtr ); //Recursion to the left
      printf("%3d",treePtr->data) ;  //print the value 
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder(TreeNodePtr treePtr){
   if(treePtr!=NULL){
      printf("%3d",treePtr->data);
      preOrder(treePtr->leftPtr);
      preOrder(treePtr->rightPtr);
   }
}

void postOrder(TreeNodePtr treePtr){
   if(treePtr!=NULL){
      postOrder(treePtr->leftPtr);
      postOrder(treePtr->rightPtr);
      printf("%3d",treePtr->data);
   }
}


void printTree(TreeNodePtr treePtr,int x){
   int i;
   if(treePtr!=NULL){
      printTree(treePtr->rightPtr,x+1);
      for(i=0;i<x;i++)printf("   ");
      printf("%3d\n",treePtr->data);
      printTree(treePtr->leftPtr,x+1);
      
   }
}