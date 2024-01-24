#include <iostream>
#include <list>
using namespace std;

class BinarySearchTree{
private:
    int data;
    BinarySearchTree *left, *right;
public:
    BinarySearchTree();
    BinarySearchTree(int);
    BinarySearchTree *insert(BinarySearchTree*, int);
    void Inorder(BinarySearchTree* root);
};


BinarySearchTree::BinarySearchTree() : data(0), left(NULL), right(NULL){

}


BinarySearchTree::BinarySearchTree(int value){
    data = value;
    left = right = NULL;
}


BinarySearchTree* BinarySearchTree::insert (BinarySearchTree* root, int value){
    if(!root){
        return new BinarySearchTree(value);
    }
    if(value > root->data){
        root->right = insert(root->right, value);
    }
    else{
        root->left = insert(root->left, value);
    }
    return root;
}


void BinarySearchTree ::Inorder(BinarySearchTree* root){

    if (!root) {
        return;

    }

    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}


class HashTable{

private:

    int bucket;
    list<int> *table;

public:

    HashTable(int buckets);
    void insertItem(int value);
    void deleteItem(int value);
    int hashFunction(int value){

        return (value % bucket);

    }
    void displayHash();
};


HashTable::HashTable(int buckets){
    this->bucket = buckets;
    table = new list<int>[bucket];
}


void HashTable::insertItem(int value){
    int index = hashFunction(value);
    table[index].push_back(value);
}


void HashTable::deleteItem(int value){
    int index = hashFunction(value);
    list<int>::iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++){
        if(*i == value){
            break;
        }
    }
    if(i != table[index].end()){

        table[index].erase(i);
    }
}


void HashTable::displayHash(){
    for (int i = 0; i < bucket; i++){
        cout << i;
        for (auto x : table[i]){
            cout << " --> " << x;
        }

        cout << endl;
    }
}


struct Node{
    int data;
    Node *next;
};
class ADT{
public:
    Node* head;
    ADT();
    void add(int value);
    int getSize();
    void remove(Node* head,int value);
    void replace(Node* head,int value, int newValue);
    void display();
};


ADT::ADT(){
}


void ADT::add (int value)
{
    Node *newNode = new Node();
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else
    {
        Node* lastNode = head;
        while(lastNode -> next != NULL){
            lastNode = lastNode -> next;

        }
        lastNode -> next = newNode;
    }

}


int ADT::getSize()
{
    Node* temp = head;
    int size = 0;
    while(temp != NULL){
        ++size;
        temp = temp -> next;
    }
    return size;
}


void ADT::remove(Node* head,int value)
{
    if(head == NULL){
        cout <<"Elemente not present in the list" <<endl;
        return;
    }
    if(head -> data == value){
        Node *temp = head;
        head = head -> next;
        delete(temp);
        return;
    }
    remove(head -> next, value);

}


void ADT::replace(Node* head,int value, int newValue){
    if(head == NULL){
        cout <<"Elemente not present in the list" <<endl;
        return;
    }
    while(head != NULL){
        if(head -> data == value){
            head -> data = newValue;
        }
        head = head ->next;
    }
}


void ADT::display()
{
    Node* temp = head;
    if(temp != NULL){
        while(temp != NULL){
           cout << temp->data << " ";
           temp = temp -> next;
        }
        cout << endl;
    }
    else{
        cout << "There is no data in the list" << endl;
        return;
    }

}


class Container{
    ADT myList;
    BinarySearchTree tree;
    HashTable table;
public:
    Container() : table(1000), tree(), myList(){
    }
    void add(int value){
        myList.add(value);
        tree.insert(&tree, value);
        table.insertItem(value);
    }
    void replace(int value, int newValue){
        myList.replace(myList.head, value, newValue);
        table.deleteItem(value);
        table.insertItem(newValue);
    }
    void display(){
        myList.display();
        cout << endl;
        table.displayHash();
        cout << endl;
        tree.Inorder(&tree);
    }
};


int main()
{
     Container test;
     test.add(564);
     test.add(456);
     test.add(456);
     test.add(46);
     test.add(46);
     test.add(23);
     test.add(25);
     test.display();

}
