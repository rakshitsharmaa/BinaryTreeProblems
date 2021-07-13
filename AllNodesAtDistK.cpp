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

void levelOrderBuild(node** root){
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


void printKLevelDown(node* target,int level){
    if (target==NULL)
    {
        return;
    }
    if (level==0)
    {
        cout<<target->data<<" ";
        return;
    }
    printKLevelDown(target->left,level-1);
    printKLevelDown(target->right,level-1);
}
int printAtDistanceK(node* root,node* target,int k){
    if (root==NULL)
    {
        return -1;
    }
    if (root==target)
    {
        printKLevelDown(target,k);
        return 0;
    }
    int DL=printAtDistanceK(root->left,target,k);
    if (DL!=-1)
    {
        if (DL+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printKLevelDown(root->right,k-2-DL);
        }
        return DL +1;

    }
    int DR=printAtDistanceK(root->right,target,k);
    if (DR!=-1)
    {
        if (DR+1==k)
        {
            cout<<root->data<<" ";
        }
        else{
            printKLevelDown(root->left,k-2-DR);
        }
        return DR+1;
        
    }
    return -1;
    
}

int main(){
    node* root;
    int arr[]={1,2,3,4,5,-1,-1,6,7,8,9,-1,-1,10,11,-1,-1,-1,-1,-1,-1,-1,-1};
    int n=sizeof(arr)/sizeof(int);

levelOrderBuild(&root);
printAtDistanceK(root,root->left->left,2);

}