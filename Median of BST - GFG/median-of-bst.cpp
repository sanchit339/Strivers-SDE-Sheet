//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void count(Node * root , int &cnt){
    if(!root) return;
    count(root -> left , cnt);
    cnt++;
    count(root -> right , cnt);
}

void check(Node * root , Node * &curr , Node * &prev , int &cnt , int x , int &found){

    if(!root) return;
    check(root -> left , curr , prev , cnt , x , found);

    // 3 condition can happen 
    // NULL ,  found  , not found
    if(prev == NULL){ // first assign right
        prev = root;
        cnt++;
    }
    else if(cnt == x){
        cnt++;
        curr = root;
        found = 1;
        return;
    }
    else if(found == 0){
        prev = root;
        cnt++;
    }

    check(root -> right , curr , prev , cnt , x , found);
}

float findMedian(struct Node *root)
{
    int cnt = 0;
    count(root , cnt);

    // for even cnt
    Node * curr = NULL;
    Node * prev = NULL;

    int c = 1;
    int x = (cnt / 2) + 1;

    int found = 0;
    check(root , curr , prev , c , x , found);

    if(cnt % 2 == 0){
        float ans = ((curr -> data + prev -> data) * 1.0) / (2 * 1.0);
        return ans;
    }
    else{
        float ans = (curr -> data) * 1.0;
        return ans;
    }
}