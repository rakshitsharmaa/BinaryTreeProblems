#include<iostream>
using namespace std;
#include<queue>
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}
Node* TreeFrmPreAndIn(int* in,int* pre,int s,int e){
     static int i=0;
    if(s>e){
        return NULL;
    }
    Node *root = new Node(pre[i++]);
    if (s==e)
    {
        return root;
    }
    int index=search(in,s,e,root->data);
    root->left=TreeFrmPreAndIn(in,pre,s,index-1);
    root->right=TreeFrmPreAndIn(in,pre,index+1,e);
return root;
}
void BFS(Node* root){
queue<Node*> q;
q.push(root);
q.push(NULL);
while (!q.empty())
{
    Node* f = q.front();
    if (f==NULL)
    {
        cout<<endl;
        q.pop();
        if (!q.empty())
        {
            q.push(NULL);
        }
        
    }
    else{
    cout<<f->data<<" ";
    q.pop();
    if (f->left)
    {
        q.push(f->left);
    }
    if (f->right)
    {
        q.push(f->right);
    }
    }
}
}

int main(){
int in[]={3,2,8,4,1,6,7,5};
int pre[]={1,2,3,4,5,6,7,8};
int n=sizeof(in)/sizeof(int);
Node* root=TreeFrmPreAndIn(in,pre,0,n-1);
BFS(root);
}