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
Node* buildTree(){
    int d;
    cin>>d;
    if (d==-1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void print(Node* root){
    if (root==NULL)
        return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int HeightOfTree(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lt = HeightOfTree(root->left);
    int rt = HeightOfTree(root->right);
    return max(lt,rt) +1;
}
void KthLevelPrint(Node* root, int k){
    if (root==NULL)
    {
        return;
    }
    
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    KthLevelPrint(root->left,k-1);
    KthLevelPrint(root->right,k-1);
}
void PrintAllLevels(Node* root){
    int h = HeightOfTree(root);
    for (int i = 1; i <= h; i++)
    {
        KthLevelPrint(root,i);
        cout<<endl;
    }
}
void PreTraversal(Node* root){
    if(root==NULL){
        return; 
    }
    cout<<root->data<<endl;
    PreTraversal(root->left);
    PreTraversal(root->right);

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
int count(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    int Lsubtree=count(root->left);
    int Rsubtree = count(root->right);
    return Lsubtree+Rsubtree+1;
}
int diameter(Node* root){
    if (root==NULL)
    {
        return 0;   
    }
    int h1=HeightOfTree(root->left);
    int h2=HeightOfTree(root->right);
    int opt1=h1+h2;
    int opt2=diameter(root->left);
    int opt3=diameter(root->right);
    return max(opt1,max(opt2,opt3));
}
class Pairr
{
public:
    int Height;
    int Diameter;
};
Pairr FastDiameter(Node* root){
 Pairr p;
 if(root==NULL){
     p.Diameter=p.Height=0;
     return p;
 };
 Pairr left = FastDiameter(root->left);
 Pairr right= FastDiameter(root->right);
 p.Height=max(left.Height,right.Height)+1;
 p.Diameter=max(left.Height+right.Height,max(left.Diameter,right.Diameter));
return p;
}
int replaceSum(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    if (root->left==NULL&&root->right==NULL)
    {
        return root->data;
    }
    int leftSum=replaceSum(root->left);
    int rightSum=replaceSum(root->right);
    int temp=root->data;
    root->data=leftSum+rightSum;
    return temp+leftSum+rightSum;
}
class HBpair
{

public:
    int Height;
    bool Balance;
    
};
HBpair isHeightBalanced(Node* root){
    HBpair p;
    if (root==NULL)
    {
        p.Balance=true;
        p.Height=0;
        return p;
    }
    HBpair left = isHeightBalanced(root->left);
    HBpair right= isHeightBalanced(root->right);
    p.Height=max(left.Height,right.Height)+1;
    if (abs(left.Height-right.Height)<=1 && left.Balance&&right.Balance)
    {
        p.Balance=true;
    }
    else
    {
        p.Balance=false;
    }
    return p;
}
Node* CreatBST(int* a,int s,int e){
    if (s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    Node* p = new Node(a[mid]);
    p->left=CreatBST(a,s,mid-1);
    p->right=CreatBST(a,mid+1,e);
    return p;
}
Node* TreeFrmPreAndIn(int* in,int* pre,int s,int e){
     static int i=0;
    if(s>e){
        return NULL;
    }
    Node* root = new Node(pre[i]);
    i++;
    if (s==e)
    {
        return root;
    }
    int index=-1;
    for (int j = s; j <= e; j++)
    {
        if (root->data==in[j])
        {
            index=j;
            break;
        }       
    }
    root->left=TreeFrmPreAndIn(in,pre,s,index-1);
    root->right=TreeFrmPreAndIn(in,pre,index+1,e);
return root;
}
void RightView(Node* root,int level,int maxLevel){
if (root==NULL)
{
    return;
}
if (level>maxLevel)
{
    cout<<root->data<<" ";
    maxLevel=level;
}
RightView(root->right,level+1,maxLevel);
RightView(root->left,level+1,maxLevel);
}
int main(){
Node* root = buildTree();
// print(root);
// KthLevelPrint(root,2);
// PrintAllLevels(root); //level order traversal O(n^2)
// cout<<HeightOfTree(root)<<endl;
// PreTraversal(root);
//BFS(root);//level order traversal O(n)
// cout<<count(root)<<endl;
// cout<<diameter(root);// O(n^2)
// Pairr p=FastDiameter(root); //O(n)
// cout<<p.Diameter<<endl;
// cout<<p.Height<<endl;
// replaceSum(root);O(n)
// PrintAllLevels(root);
// HBpair p =isHeightBalanced(root);
// cout<<p.Balance<<endl;
// int a[]={2,4,6,8,9,12,45,67,89};
// int n=9;
// Node* root = CreatBST(a,0,8);
// BFS(root);
// int in[]={3,2,8,4,1,6,7,5};
// int pre[]={1,2,3,4,5,6,7,8};
// int n=sizeof(in)/sizeof(int);
// Node* root=TreeFrmPreAndIn(in,pre,0,n-1);
// PrintAllLevels(root);
RightView(root,0,-1);
} 