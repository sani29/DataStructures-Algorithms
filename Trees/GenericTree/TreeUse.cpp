// Implementation of Generic Tree
#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Take input Level-Wise
TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		
		cout<<"Enter number of children "<<front->data<<endl;
		int numChild;
		cin>>numChild;
		for(int i=0;i<numChild;i++){
			int childData;
			cout<<"Enter "<<i<<"th child data"<<endl;
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

// Take input
TreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout<<"Enter number of children"<< rootData<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}
// Print Level-Wise
void printTreeLevelWise(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0){
		TreeNode<int>* front = pendingNodes.front();
		cout<<front->data<<":";	
		pendingNodes.pop();
		for(int i=0;i<front->children.size();i++)
		{
			TreeNode<int>* child = front->children[i];
			if(i == front->children.size()-1){
				cout<<child->data;
			}
			else{
				cout<<child->data<<",";
			}
			pendingNodes.push(child);
		}
		cout<<endl;
	}
}

// Print Generic Tree
void printTree(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++){
		if(i == root->children.size()-1){
			cout<<root->children[i]->data;
		}
		else{
			cout<<root->children[i]->data<<",";
		}
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printTree(root->children[i]);
	}
}

// Print Nodes at Level k in a tree
void printAtLevelK(TreeNode<int>* root, int k){
	if(root == NULL){
		return;
	}
	if(k == 0){
		cout<<root->data<<endl;
		return;
	}
	for(int i=0;i<root->children.size();i++){
		printAtLevelK(root->children[i], k-1);
	}
}

// Number of Nodes in a Geenric Tree
int numNodes(TreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	int ans = 1;
	for(int i=0;i<root->children.size();i++){
		ans += numNodes(root->children[i]);
	}
	return ans;
}

// Number of Leaf Nodes
int numLeafNodes(TreeNode<int>* root) {
    if(root == NULL){
      return 0;
    }
  if(root->children.size() == 0){
    return 1;
  }
  int numLeaf = 0;
  for(int i=0;i<root->children.size();i++){
    numLeaf += numLeafNodes(root->children[i]);
  }
	return numLeaf;
}

// Print Preorder of a Tree
void preorder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++){
		preorder(root->children[i]);
	}
}

// Print Postorder of a Tree
void postorder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}
	
	for(int i=0;i<root->children.size();i++){
		postorder(root->children[i]);
		
	}
	cout<<root->data<<" ";
}

// Delete a Tree
void deleteTree(TreeNode<int>* root){
	for(int i=0;i<root->children.size();i++){
		deleteTree(root->children[i]);
	}
	delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	/*TreeNode<int>* root = takeInput();
	printTree(root);
	*/
	TreeNode<int>* root = takeInputLevelWise();
	printTreeLevelWise(root);
	
	cout << "Level 2:" << endl;
	printAtLevelK(root,2);
	cout<<"num of leaf nodes: "<<numLeafNodes(root)<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	
	delete root;
	//deleteTree(root);
	
}
