#include <iostream>
using namespace std;
struct node {
   int data;
   struct node *left, *right;
};
void printSubtreeNodes(node *root, int k) {
   if (root == NULL || k < 0) return;
   if (k==0){
      cout<<root->data<<"\t";
      return;
   }
   printSubtreeNodes(root->left, k-1);
   printSubtreeNodes(root->right, k-1);
}
int printKNodes(node* root, node* target , int k){
   if (root == NULL) return -1;
   if (root == target){
      printSubtreeNodes(root, k);
      return 0;
   }
   int dl = printKNodes(root->left, target, k);
   if (dl != -1){
      if (dl + 1 == k)
         cout<<root->data<<"\t";
      else
         printSubtreeNodes(root->right, k-dl-2);
      return 1 + dl;
   }
   int dr = printKNodes(root->right, target, k);
      if (dr != -1){
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printSubtreeNodes(root->left, k-dr-2);
         return 1 + dr;
      }
      return -1;
   }
   node *insertNode(int data){
      node *temp = new node;
      temp->data = data;
      temp->left = temp->right = NULL;
      return temp;      
}
int main(){
   node * root = insertNode(6);
   root->left = insertNode(3);
   root->right = insertNode(9);
   root->left->right = insertNode(4);
   root->right->left = insertNode(8);
   root->right->right = insertNode(10);
   root->right->right->left = insertNode(5);
   root->right->right->right = insertNode(1);
   node * target = root->right;
   int K = 2;
   cout<<"Nodes at distance "<<K<<" from the target node are :\n";
   printKNodes(root, target, K);
   return 0;
}
