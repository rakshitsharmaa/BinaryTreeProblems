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
void BuildTreeFrmPreOrder(node* &root){
    int d;
    cin>>d;
    if (root==NULL)
    {
        root=new node(d);
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* c=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
        c->left=new node(c1);
        q.push(c->left);
        }
       if (c2!=-1)
       {
        c->right=new node(c2);
        q.push(c->right);
       }
    }
}
int MaxSumUntil(node* root,int &result){
    if (root==NULL)
    {
        return 0;
    }
    int leftSum=MaxSumUntil(root->left,result);
    int rightSum=MaxSumUntil(root->right,result);
    int maxSingle=max(max(leftSum,rightSum)+root->data,root->data);
    int maxTillNow=max(leftSum+rightSum+root->data,maxSingle);
    result=max(maxTillNow,result);
    return maxSingle;
}
int findMaxSum(node* root){
    int result=INT_MIN;
    MaxSumUntil(root,result);
    return result;
}

int main(){
    node* root=NULL;
    BuildTreeFrmPreOrder(root);
    cout<< findMaxSum(root)<<endl;
}