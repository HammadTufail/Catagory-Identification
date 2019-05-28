#include <bits/stdc++.h>
using namespace std;

// Represents a node of an n-ary tree
struct Node
{
    string key;
    vector<Node *>child;
    Node* prevNode;
};
Node *newNode(string key)
{
    Node *temp = new Node;
    temp->key = key;
    return temp;
}

// Prints the n-ary tree level wise
void LevelOrderTraversal(Node * root)
{
    if (root==NULL)
        return;

    // Standard level order traversal code
    // using queue
    queue<Node *> q;  // Create a queue
    q.push(root); // Enqueue root
    while (!q.empty())
    {
        int n = q.size();

        // If this node has children
        while (n > 0)
        {
            // Dequeue an item from queue and print it
            Node * p = q.front();
            q.pop();
            cout << p->key << " ";

            // Enqueue all children of the dequeued item
            for (int i=0; i<p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }
}
Node* getParent(Node* child)
{
    return child->prevNode;
}
void DirectSuperCatagory(Node* child)
{
    cout<<child->key<<" "<<child->prevNode->key<<" ";
}
void IsSuperCatagory(Node* parent,Node* child)
{
    if(parent->key.compare(child->prevNode->key)==0)
    {
        cout<<" yes"<<" ";
    } else
        cout<<"no"<<" ";
}
void AllSubCatagories(Node* node)
{
    LevelOrderTraversal(node);
}
void NumberOfAllSupercatagories(Node* root,Node* node)
{
    int count=0;
    Node* tmp=node;
    while(tmp->key.compare(root->key)!=0)
    {
        tmp=tmp->prevNode;
        count++;
    }
    cout<<" "<<count;
}
void NumberOfAllSubcatagories(Node* root)
{
    if (root==NULL)
        return;

    // Standard level order traversal code
    // using queue
    queue<Node *> q;  // Create a queue
    q.push(root); // Enqueue root
    int i=0;
    while (!q.empty())
    {
        int n = q.size();

        // If this node has children
        while (n > 0)
        {
            // Dequeue an item from queue and print it
            Node * p = q.front();
            q.pop();
            i++;

            // Enqueue all children of the dequeued item
            for (int i=0; i<p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }
    cout<<" "<<i;
}
void ClosestCommonSupercategory(Node* nodeA, Node* nodeB,Node* root)
{
    while(nodeA->key.compare(nodeB->key)!=0)
    {
        nodeA=nodeA->prevNode;
        nodeB=nodeB->prevNode;
        if(nodeA->key.compare(root->key)==0||nodeB->key.compare(root->key)==0)
        {
            cout<<"Not Found";
        }
    }
}
void IsSubcategory(Node* parent,Node* child)
{
    if(child->prevNode->key.compare(parent->key)==0)
    {
        cout<<" Yes";
    }
    else
    {
        cout<<" No";
    }
}
void DirectSubcategories(Node* node)
{
    cout<<node->key<<" ";
    for (int i = 0; i <node->child.size() ; ++i) {
        cout<<node->child[i]->key<<" ";
    }
}
void AllSupercategories(Node* parent,Node* child)
{
    Node* tmp=child;
    cout<<tmp->key<<" ";
    while(tmp->key.compare(parent->key)!=0)
    {
        tmp=tmp->prevNode;
        cout<<tmp->key<<" ";
    }
}
Node* getToAdd(Node * root,string s_key)
{

    // Standard level order traversal code
    // using queue
    queue<Node *> q;  // Create a queue
    q.push(root); // Enqueue root
    Node* parent;
    Node* child;
    while (!q.empty())
    {
        int n = q.size();

        // If this node has children
        while (n > 0)
        {
            // Dequeue an item from queue and print it
            Node * p = q.front();
            parent=p;
            q.pop();

            // Enqueue all children of the dequeued item
            for (int i=0; i<p->child.size(); i++)
            {
                if(p->child[i]->key.compare(s_key)==0)
                {
                    Node* tmp=p->child[i];
                    tmp->prevNode=parent;
                    return tmp;
                }
            }
            // Enqueue all children of the dequeued item
            for (int i=0; i<p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }
}
// Driver program
int main()
{
    ifstream file("in.txt");
    string line;
    string lines;
    getline(file,lines);
    stringstream ss(lines);
    getline(ss,line,' ');
    Node *root=newNode(line);
    getline(ss,line,' ');
    (root->child).push_back(newNode(line));
    getline(ss,line,' ');
    (root->child).push_back(newNode(line));
    getline(ss,line,' ');
    (root->child).push_back(newNode(line));
    while(getline(file,lines))
    {
        stringstream ss1(lines);
        getline(ss1,line,' ');
        Node* n=getToAdd(root,line);
        int i=2;
        while(i>0)
        {
            getline(ss1,line,' ');
            (n->child).push_back(newNode(line));
            i--;
        }
    }
    //LevelOrderTraversal(root);


    ifstream file1("ques.txt");
    string line1;
    string lines1;
    getline(file,lines1);
    stringstream ss3(lines1);
    getline(ss3,line1,' ');
    Node *root1=newNode(line1);
    getline(ss,line1,' ');
    (root1->child).push_back(newNode(line1));
    getline(ss3,line1,' ');
    (root1->child).push_back(newNode(line1));
    getline(ss3,line1,' ');
    (root1->child).push_back(newNode(line1));
    while(getline(file1,lines1))
    {
        stringstream ss2(lines1);
        getline(ss2,line1,' ');
        if(line1.compare("IsSupercategory")==0)
        {
            cout<<"IsSupercategory ";
            string  a,b;
            getline(ss2,a,' ');
            getline(ss2,b,' ');
            Node* aa = getToAdd(root,a);
            Node* ab = getToAdd(root,b);
            cout<<a<<" "<<b<<" ";
            IsSuperCatagory(aa,ab);
        }
        else if(line1.compare("DirectSupercategory")==0)
        {
            cout<<"DirectSupercategory ";
            string  a;
            getline(ss2,a,' ');
            Node* aa = getToAdd(root,a);
            DirectSuperCatagory(aa);
        }
        else if(line1.compare("ClosestCommonSupercategory")==0)
        {
            cout<<"ClosestCommonSupercategory ";
        }
        else if(line1.compare("IsSubcategory")==0)
        {
            cout<<"IsSubcategory";
            string  a,b;
            getline(ss2,a,' ');
            getline(ss2,b,' ');
            Node* aa = getToAdd(root,a);
            Node* ab = getToAdd(root,b);
            cout<<a<<" "<<b<<" ";
            IsSubcategory(aa,ab);
        }
        else if(line1.compare("DirectSubcategories")==0)
        {
            cout<<"DirectSubcategories ";
            string  a;
            getline(ss2,a,' ');
            Node* aa = getToAdd(root,a);
            DirectSubcategories(aa);
        }
        else if(line1.compare("AllSupercategories")==0)
        {
            cout<<"AllSupercategories ";
            string  a;
            getline(ss2,a,' ');
            Node* aa = getToAdd(root,a);
            AllSupercategories(root,aa);
        }
        else if(line1.compare("AllSubcategories")==0)
        {
            cout<<"AllSubcategories ";
            string  a;
            getline(ss2,a,' ');
            Node* aa = getToAdd(root,a);
            AllSubCatagories(aa);
        }
        else if(line1.compare("NumberOfAllSupercategories")==0)
        {
            string  a;
            getline(ss2,a,' ');
            Node* aa = getToAdd(root,a);
            cout<<"NumberOfAllSupercategories ";
            NumberOfAllSupercatagories(root,aa);
        }
        else if(line1.compare("NumberOfAllSubcategories")==0)
        {
            cout<<"NumberOfAllSubcategories ";
            string  a;
            getline(ss2,a,' ');
            Node* aa = getToAdd(root,a);
            NumberOfAllSubcatagories(aa);
        }
        cout<<"\n";
    }



    return 0;
}