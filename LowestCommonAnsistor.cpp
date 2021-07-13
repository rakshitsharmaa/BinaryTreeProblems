#include<iostream>
using namespace std;
#include<queue>

class node
{
public:
    int data;
    node* left;
    node* right;
 node(int d){
     data=d;
     left=NULL;
     right=NULL;
 }
};
void BuildTreeFrmLevelOrder(node** root){
    int d;
    cin>>d;
        *root=new node(d);
    queue<node*> q;
    q.push(*root);
    while (!q.empty())
    {
        node* n=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if (c1!=-1)
        {
        n->left=new node(c1);    
        q.push(n->left);
        }
        if (c2!=-1)
        {
            n->right=new node(c2);
            q.push(n->right);
        }    
    }
}
node* LCA(node* root,int a,int b){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data==a or root->data==b)
    {
        return root;
    }
    node* leftAns=LCA(root->left,a,b);
    node* rightAns=LCA(root->right,a,b);
    if (leftAns!=NULL and rightAns!=NULL)
    {
        return root;
    }
    if (leftAns!=NULL)
    {
        return leftAns;
    }
    if (rightAns!=NULL)
    {
        return rightAns;
    }
    return NULL;
}

int main(){
    node* root;
    BuildTreeFrmLevelOrder(&root);
    cout<<LCA(root,4,7)->data<<endl;
    cout<<LCA(root,6,9)->data<<endl;
}



