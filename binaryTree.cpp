#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

TreeNode* buildTree(TreeNode* root){
    int data;
    cout<<"enter the value of data"<<endl;
    cin>>data;
    root=new TreeNode(data);
    if(data==-1) return NULL;
    cout<<"enter the data for inserting in left"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter the data for inserting in right"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

//TRAVERSALS IN BINARY TREE
//LEVEL ORDER TRAVERSAL
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
          if(!q.empty())  q.push(NULL);
        }
        else{
            cout<<temp->data;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}
//INORDER TRAVERSAL
void inorder(TreeNode* &root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//HEIGHT OF BINARY TREE
int heightOfTree(TreeNode* &root){
    if(root==NULL) return 0;
    int left=heightOfTree(root->left);
    int right=heightOfTree(root->right);
    int ans=max(left,right)+1;
    return ans;
}

//DIAMETER OF BINARY TREE
int height(TreeNode* &root,int &diameter){
    if(root==NULL) return 0;
    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinary(TreeNode* &root){
    int diameter=0;
    diameter=height(root,diameter);
    return diameter;
}

//CHECK WHETHER TWO TREES IS IDENTICAL OR NOT
bool isIdentical(TreeNode* r1,TreeNode* r2){
    if(r1==NULL && r2==NULL) return true;
    if(r1==NULL && r2!=NULL) return false;
    if(r1!=NULL && r2==NULL) return false;
    bool left=isIdentical(r1->left,r2->left);
    bool right=isIdentical(r1->right,r2->right);
    bool value=r1->data==r2->data;//backtracking condition
    if(left && right && value) return true;
    return false;
}

//CHECK SUM TREE OR NOT
pair<bool,int> isSumTree(TreeNode* &root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
   pair<bool,int> leftAns=isSumTree(root->left);
   pair<bool,int> rightAns=isSumTree(root->right);
   bool isleftsumtree=leftAns.first;
   bool isrightsumtree=rightAns.first;
   int leftsum=leftAns.second;
   int rightsum=rightAns.second;
   bool cond=root->data==leftsum+rightsum;
   pair<bool,int>ans;
   if(isleftsumtree && isrightsumtree && cond){
     ans.first=true;
     ans.second=root->data+leftsum+rightsum;
   }
   else{
    ans.first=false;
   }
   return ans;
}

bool checkSum(TreeNode* &root){
    return isSumTree(root).first;
}

//ZIG ZAG TRAVERSAL approach (level order traversal)
vector<int> zigZagTraversal(TreeNode* &root){
    vector<int>result;
    if(root==NULL) return result;
    queue<TreeNode*>q;
    q.push(root);
    bool leftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>ans;
        for(int i=0;i<size;i++){
            TreeNode* frontNode=q.front();
            q.pop();
        int index=leftToRight? i:size-i-1;
        ans[index]=frontNode->data;    
        if(frontNode->left) q.push(frontNode->left);
        if(frontNode->right) q.push(frontNode->right);
    }
    leftToRight=false;
    for(auto i:ans){
     result.push_back(i);
    }
}
 return result;
}

// Construct String from Binary Tree Input: root = [1,2,3,4] Output: "1(2(4))(3)"
 void preorder(TreeNode* root ,string &ans){
        if(root==NULL) return;
        ans+=to_string(root->data);
        if(root->left==NULL && root->right==NULL) return;
        ans.push_back('(');
        preorder(root->left,ans);
        ans.push_back(')');
        if(root->right) ans.push_back('(');
        preorder(root->right,ans);
        if(root->right) ans.push_back(')');
    }
    string tree2str(TreeNode* root) {
       string ans;
       preorder(root,ans);
       return ans;
    }

// Sum of Left Leaves Input: root = [3,9,20,null,null,15,7] Output: 24 Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.    
 int sum=0;
   void solve(TreeNode* root,int direction){
       if(root==NULL) return;
       if(root->left==NULL && root->right==NULL){
           if(direction==0) 
           sum+=root->data;
           return;
       }
       solve(root->left,0);// we define 0 direction for left node.
       solve(root->right,1);// we define 1 direction for right node.
   }
   
   int sumOfLeftLeaves(TreeNode* root){
       solve(root,-1);
       return sum;
 }

// Find Mode in Binary Search Tree Input: root = [1,null,2,2] Output: [2]
 unordered_map<int,int>mp;
    void solve(TreeNode* root){
        if(root==NULL) return;
        mp[root->data]++;
        if(root->left) solve(root->left);
        if(root->right) solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
       solve(root);
       int maxi=INT_MIN;
       int maxfreq=0;
       for(auto it:mp){
           if(it.second>=maxfreq){
               maxi=it.first;
               maxfreq=it.second;
           }
       }
       vector<int>ans;
       for(auto it:mp){
           if(it.second==maxfreq) ans.push_back(it.first);
       }
      return ans;
    }

// Search in a Binary Search Tree
 TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return root;
         if(root->data==val) return root;
        if(root->data>val) return searchBST(root->left,val);
        else   return searchBST(root->right,val);
    } 

//Leaf-Similar Trees Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
//Output: true
 void countleaves(TreeNode* root1,vector<int>&a1){
        if(root1==NULL) return;
        if(root1->left==NULL && root1->right==NULL){
            a1.push_back(root1->data);
            return;
        }
        countleaves(root1->left,a1);
        countleaves(root1->right,a1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       vector<int>ans1,ans2;
       countleaves(root1,ans1);
       countleaves(root2,ans2);
       return(ans1==ans2);
    } 

//. Sum of Root To Leaf Binary Numbers Input: root = [1,0,1,0,1,0,1] Output: 22 Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 int solve(string a)
    {
        int ans=0;
        int t=a.length()-1;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]=='1')
            {
                ans+=pow(2,t);
            }
            t--;
        }
        return ans;
    }
    void helper(TreeNode* root,string x,vector<string>&s)
    {
        if(root==NULL)return;
        if(root->left==NULL &&root->right==NULL)
        {
            x+=to_string(root->data);
            s.push_back(x);
        }
        x+=to_string(root->data);
        helper(root->left,x,s);
        helper(root->right,x,s);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string>s;
        string x="";
        helper(root,x,s);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans+=solve(s[i]);
        }
        return ans;
    }         

// Same Tree
 bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==NULL &&q==NULL) return true;
       if(p==NULL || q==NULL) return false;
       if(p->data==q->data)
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
       return false;
    }
//Count Good Nodes in Binary Tree Input: root = [3,1,4,3,null,1,5] Output: 4 Root Node (3) is always a good node.
//Node 4 -> (3,4) is the maximum value in the path starting from the root. Node 5 -> (3,4,5) is the maximum value in the path Node 3 -> (3,1,3) is the maximum value in the path.
    void ans(TreeNode* temp,int mx){
        int count=0;
        if(temp==NULL)
        return;

        if(temp->data>=mx)
        count++;

        ans(temp->left,max(temp->data,mx));
        ans(temp->right,max(temp->data,mx));
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        ans(root,root->data);
        return count;
    }   
//Range Sum of BST Input: root = [10,5,15,3,7,null,18], low = 7, high = 15 Output: 32 Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
 int sum=0;
    void traversal(TreeNode* root,int low,int high){
        if(root==NULL) return;
        traversal(root->left,low,high);
        if(root->data<=high && root->data>=low) sum+=root->data;
        traversal(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
      if(root==NULL) return 0;  
      traversal(root,low,high);
      return sum;
    }   
//Symmetric Tree Input: root = [1,2,2,3,4,4,3] Output: true
  bool rec(TreeNode*root1,TreeNode*root2){
        if(root1==NULL&&root2==NULL)return true;
        if(root1==NULL||root2==NULL)return false;
        if(root1->data!=root2->data)return false;
        return rec(root1->left,root2->right)&&rec(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return 1;
        return rec(root->left,root->right);
    }    

// Path Sum Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22 Output: true Explanation: The root-to-leaf path with the target sum is shown.
 bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL&& root->data-targetSum==0) return true;
        bool left= hasPathSum(root->left,targetSum-root->data);
        bool right= hasPathSum(root->right,targetSum-root->data);
        return left||right;
    } 

//Sum Root to Leaf Numbers Input: root = [4,9,0,5,1] Output: 1026 Explanation:
//The root-to-leaf path 4->9->5 represents the number 495.The root-to-leaf path 4->9->1 represents the number 491.
//The root-to-leaf path 4->0 represents the number 40. Therefore, sum = 495 + 491 + 40 = 1026.
 int sum=0;
    void traverseTree(TreeNode* root,int val){
       if(root->left==NULL && root->right==NULL){
          val=val*10+(root->data);
          sum+=val;
          return;
       }
       val=(val*10)+(root->data);
       if(root->left!=NULL) traverseTree(root->left,val);
       if(root->right!=NULL) traverseTree(root->right,val);
    }
    int sumNumbers(TreeNode* root) {
        traverseTree(root,0);
        return sum;
    }

int main(){
    TreeNode* root=NULL;
    root=buildTree(root);
    return 0;
}