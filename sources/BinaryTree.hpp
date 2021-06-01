#pragma once

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

namespace ariel{
    template<typename T>
    class BinaryTree{
    private:
        typedef struct Node {
            T data;
            Node* left = nullptr;
            Node* right = nullptr;

            Node(const T& val ) : data(val) {}

            bool operator==(const Node& other) const{
                return (other.data == data) && (other.left == left) && (other.right == right);
            }

            bool operator!=(const Node& other) const{
                return !(other == this);
            }
        }Node;
        Node* root = nullptr;

        void copyTree(Node& thisRoot,const Node& sourceRoot)
        {
            if (sourceRoot.left != nullptr)
            {
                thisRoot.left = new Node(sourceRoot.left->data);
                copyTree(*thisRoot.left, *sourceRoot.left);
            }
              if (sourceRoot.right != nullptr)
            {
                thisRoot.right = new Node(sourceRoot.right->data);
                copyTree(*thisRoot.right, *sourceRoot.right);
            }
            
        }
    public:
        BinaryTree() {}
        BinaryTree(BinaryTree& other){
            root = new Node(other.root->data); 
            copyTree(*this->root, *other.root);
        }
        ~BinaryTree() { 
            if (root != nullptr) { 
                delete root; 
            } 
        }

    BinaryTree &operator=(BinaryTree other) {
        if (this != &other) {
            delete root;
            root = new Node(other.root->data);
            copyTree(*root, *other.root);
        }
        return *this;
    }

        // Move constructor and operator=:
        BinaryTree(BinaryTree&& other) noexcept{
            root  = other.root;
            other.root = nullptr;
        }
        BinaryTree& operator=(BinaryTree&& other) noexcept{
            if (root){
               delete root; 
            } 
            root  = other.root;
            other.root = nullptr;
            return *this;
        }

        BinaryTree& add_root(T r){
            if(root == nullptr){
                root = new Node(r);
            }
            else{
                root->data = r;
            }
            return *this;
        }

        Node* find_node(const T& key,Node* curr){
            Node* temp = curr;
            if (curr == nullptr){
                return curr;
            }

            if (curr->data == key){
                return curr;
            }
            /* then recur on left sutree */
            temp = find_node(key,curr->left);
            if (temp != nullptr){
                return temp;
            }
            /* node is not found in left,
            so recur on right subtree */
            temp = find_node(key, curr->right);
            return temp;
        }

        BinaryTree& add_left(T parent, T child){
            Node* temp = find_node(parent,root);
            if (temp)
            {
                if (temp->left == nullptr){
                    temp->left = new Node(child);
                }
                else{
                    temp->left->data = child;
                }
                return *this;
            }
            throw out_of_range("parent doesn't exist!\n");
        }

        BinaryTree& add_right(const T& parent, const T& child){
            Node* temp = find_node(parent,root);
            if (temp)
            {
                if (temp->right == nullptr){
                    temp->right = new Node(child);
                }
                else{
                    temp->right->data = child;
                }
                return *this;
            }
            throw out_of_range("parent doesn't exist!\n");
        }

        friend ostream& operator<< (std::ostream& os, const BinaryTree& tree){
            if (tree.root == NULL){
                return os;
            }    
            stack<Node*> s;
            s.push(tree.root);

            while (!s.empty()) {
                Node* node = s.top();
                os<<node->data<<"   ";
                s.pop();
                if (node->right){
                   s.push(node->right); 
                }   
                if (node->left){
                    s.push(node->left);
                }   
            }
            os<<"\n__________________\n";
            return os;
        }

        //-------------------------------------------------------------------
        // inner class and methods that return instances of it
        //-------------------------------------------------------------------
        class iterator {

        private:
            Node* pointer_to_current_node = nullptr;
            int type;       // preorder = 0, inorder = 1, postorder = 2
            queue<Node*> itr_queue;

            void preorder(Node* curr)
            {
                // if the current node is empty
                if (curr == nullptr) {
                    return;
                }
                itr_queue.push(curr);
                // Traverse the left subtree
                preorder(curr->left);
                // Traverse the right subtree
                preorder(curr->right);
            }

            void inorder(Node* curr)
            {
                // if the current node is empty
                if (curr == nullptr) {
                    return;
                }
                // Traverse the left subtree
                inorder(curr->left);
                itr_queue.push(curr);
                // Traverse the right subtree
                inorder(curr->right);
            }

            void postorder(Node* curr)
            {
                // if the current node is empty
                if (curr == nullptr) {
                    return;
                }
                // Traverse the left subtree
                postorder(curr->left);
                // Traverse the right subtree
                postorder(curr->right);
                itr_queue.push(curr);
            }

        public:
            iterator(int n,Node* root) : type(n){
                switch (n)
                {
                    case 0:
                        preorder(root);
                        break;
                    case 1:
                        inorder(root);
                        break;
                    case 2:
                        postorder(root);
                        break;
                    default:
                        break;
                }
                if (!itr_queue.empty())
                {
                    pointer_to_current_node = itr_queue.front();
                    itr_queue.pop();
                }
            }

            T& operator*() const {
                return pointer_to_current_node->data;
            }

            T* operator->() const {
                return &(pointer_to_current_node->data);
            }

            // ++i;
            iterator& operator++() {
                if (itr_queue.empty()){
                    pointer_to_current_node = nullptr;
                }
                else{
                    pointer_to_current_node = itr_queue.front();
                    itr_queue.pop();
                }
                return *this;
            }

            // i++;
            iterator operator++(int) {
                iterator tmp= *this;
                if (itr_queue.empty()){
                    pointer_to_current_node = nullptr;
                }
                else{
                    pointer_to_current_node = itr_queue.front();
                    itr_queue.pop();
                }
                return tmp;
            }

            bool operator==(const iterator& rhs) const {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const iterator& rhs) const {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        };  // END OF CLASS ITERATOR

        iterator begin(){return begin_inorder();}
        iterator end(){return end_inorder();}
        iterator begin_preorder(){return iterator(0,root);}
        iterator end_preorder(){return iterator(0,nullptr);}
        iterator begin_inorder(){return iterator(1,root);}
        iterator end_inorder(){return iterator(1,nullptr);}
        iterator begin_postorder(){return iterator(2,root);}
        iterator end_postorder(){return iterator(2,nullptr);}
    };
}