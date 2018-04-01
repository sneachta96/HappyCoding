//PROBLEM NAME : AVL TREE (SPOJ)
//PROBLEM LINK : http://www.spoj.com/problems/SDITSAVL/
//STATUS : ACCEPTED :D

#include<iostream>
#include<vector>


using namespace std;
struct node {               //NODE DEFINATION
  long long int key;
  struct node *left;
  struct node *right;
  long long int height;
  long long int left_child ;
  long long int right_child;
  long long int count ;
};

 

long long int height(struct node *n){  //THIS RETURNS THE HEIGHT OF ANY NODE
  if(n == NULL){
    return 0;
  }
  else{
    return n->height;
  }
}

struct node *rightRotate(struct node *y){   // THIS ROTATES THE NODE Y RIGHT AND REPLACES IT BY ITS LEFT CHILD ,X
  struct node *x = y->left;
  struct node *z = x->right;
  x->right = y;
  y->left = z;
  y->height = max(height(y->left),height(y->right))+1;
  x->height = max(height(x->left),height(x->right))+1;
  y->left_child = x->right_child;
  x->right_child = (y->right_child+y->left_child)+1;
  return x;
}
struct node *leftRotate(struct node *y){      // THIS ROTATES THE NODE Y LEFT AND REPLACES IT BY ITS RIGHT CHILD, X
  struct node *x = y->right;
  struct node *z = x->left;
  x->left = y;
  y->right = z;
  y->height = max(height(y->left),height(y->right))+1;
  x->height = max(height(x->left),height(x->right))+1;
  //cout<<x->left_child<<" "<<x->right_child<<endl;
  //cout<<y->left_child<<" "<<y->right_child<<endl;
  y->right_child = x->left_child;
  x->left_child = (y->left_child + y->right_child)+1;
  return x;

}

long long int getBalance(struct node *n){   //THIS IS TO OBTAIN THE BALANCE BETWEEN THE NODES
  if(n == NULL){
    return 0;
  }
  return height(n->left) - height(n->right);
}

struct node *insert(struct node *n, long long int key){
  if(n == NULL){
    //cout<<"ey"<<endl;
    struct node* temp = new node();
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    temp->left_child = 0;
    temp->right_child = 0;
    temp->count = 1;
    //cout<<"dfs"<<endl;
    return temp;
  }
  if(key == n->key){    //IF THE KEY IS ALREADY THERE, THEN SIMPLE INCREMENT THE COUNT OF THE VALUE
    n->count+=1;
    return n;
  }
  if(key < n->key){
    n->left = insert(n->left,key);
  }
  else if(key > n->key){
    n->right = insert(n->right,key);
  }
  else{
    return n;
  }
  n->height = max(height(n->left),height(n->right))+1;
  if(n->right != NULL ){  //UPDATE THE VALUE OF NODES IN THE RIGHT SUBTREE
  n->right_child = (n->right->right_child)+ (n->right->left_child)+1;
}
  if(n->left != NULL){    //UPDATE THE VALUE OF THE NODES IN THE LEFT SUBTREE
  n->left_child = (n->left->right_child)+ (n->left->left_child)+1;
  //if(n->key == 20)cout<<n->left_child<<endl;
}
  //cout<<n->height<<endl;
  long long int balance = getBalance(n);
  if(balance > 1 && key < n->left->key){
    return rightRotate(n);
  }
  if(balance < -1 && key > n->right->key){
    return leftRotate(n);
  }
  if(balance > 1 && key > n->left->key){
    n->left = leftRotate(n->left);
    return rightRotate(n);
  }
  if(balance < -1 && key < n->right->key){
    n->right = rightRotate(n->right);
    return leftRotate(n);
  }
  //n->left_child = (n->left->left_child)+1;


  return n;

}

struct node *getMin(struct node *n){
  struct node *curr = n;
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}
struct node *deleteNode(struct node* root, long long int key){
  if(root==NULL){
    return root;
  }
  if(key < root->key){
    root->left = deleteNode(root->left,key);
    root->left_child-=1;
  }
  else if(key > root->key){
    root->right = deleteNode(root->right,key);
    root->right_child-=1;
  }
  else{
    if((root->left == NULL) || (root->right == NULL)){
      struct node *temp = root->left ? root->left : root->right;
      if(temp == NULL){
        temp = root;
        root = NULL;
      }
      else{
        root = temp;
      }
    }
    else{
      struct node *temp = getMin(root->right);
      root->key = temp->key;
      root->right_child = (root->right_child)-1;
      root->right = deleteNode(root->right,temp->key);
    }
  }
  if(root == NULL){
    return root;
  }
  root->height = 1 + max(height(root->left),height(root->right));
  if(root->right != NULL ){
  root->right_child = (root->right->right_child)+ (root->right->left_child)+1;
}
  if(root->left != NULL){
  root->left_child = (root->left->right_child)+ (root->left->left_child)+1;
  //if(n->key == 20)cout<<n->left_child<<endl;
}
  long long int balance  = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}
void inorder(struct node * root){
  if(root==NULL){
    return ;
  }
  if(root->left != NULL){
    inorder(root->left);
  }
  cout<<root->key<<" "<<root->left_child<<" "<<root->right_child<<endl;
  if(root->right != NULL){
    inorder(root->right);
  }
}

long long int findkthsmallest(struct node *root,long long int k){
  if(root == NULL){
    return -1;
  }
  if(k == root->left_child+1){
    return root->key;
  }
  if(root->left_child >= k){
    return findkthsmallest(root->left,k);
  }
  else{
    return findkthsmallest(root->right,k-(root->left_child+1));
  }
}
bool ifPresent(struct node * root, long long int key){
  if(root==NULL){
    return false;
  }
  if(root->key == key){
    return true;
  }
  else if(root->key < key){
    return ifPresent(root->right,key);
  }
  else{
    return ifPresent(root->left,key);
  }
}
long long int findRank(struct node *root, long long int key){
   if(root->key == key){
     return root->left_child+ 1;
   }
   else if ( root->key < key){
     return  (root->left_child)+ 1 + findRank(root->right,key);
   }
   else{
     return findRank(root->left,key);
   }

}
long long int smallest(struct node *root){
  while(root->left != NULL){
    root = root->left;
  }
  return root->key;
}
int main(){
  long long int n;
  cin>>n;
  struct node *root = NULL;

  for(long long int i = 1; i<= n;i++){
    long long int x;
    cin>>x;
    if(x == 1){
      long long int y;
      cin>>y;
      root = insert(root,y);
    }
    else{
       long long int y;
       cin>>y;
       if(ifPresent(root,y)==false){
         cout<<"Data tidak ada"<<endl;
       }
       else{
         cout<<findRank(root,y)<<endl;
       }
     }
  }
}
