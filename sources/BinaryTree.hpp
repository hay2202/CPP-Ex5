#pragma once

#include <iostream>
using namespace std;

namespace ariel{
    template<typename T>
    class BinaryTree{
    private:
        typedef struct Node {
            T data;
            Node* left;
            Node* right;

            Node(T val)
            {
                data = val;
                left = nullptr;
                right = nullptr;
            }
        }Node;
        Node* root;

    public:
        BinaryTree() :root(nullptr) {}
        BinaryTree& add_root(T r){
            return *this;
        }
        BinaryTree& add_left(T parent, T child){
            return *this;
        }
        BinaryTree& add_right(T parent, T child){
            return *this;
        }
        friend ostream& operator<< (std::ostream& os, const BinaryTree& x){
            return os << "print\n";
        }

        //-------------------------------------------------------------------
        // inner class and methods that return instances of it
        //-------------------------------------------------------------------
        //TODO
        class iterator {

        private:
            Node* pointer_to_current_node;

        public:

            iterator(Node* ptr = nullptr) : pointer_to_current_node(ptr) {}

            T& operator*() const {
                //return *pointer_to_current_node;
                return pointer_to_current_node->data;
            }

            T* operator->() const {
                return &(pointer_to_current_node->data);
            }

            // ++i;
            iterator& operator++() {
                //++pointer_to_current_node;
                pointer_to_current_node = pointer_to_current_node->right;
                return *this;
            }

            // i++;
            const iterator operator++(int) {
                iterator tmp= *this;
                pointer_to_current_node= pointer_to_current_node->right;
                return tmp;
            }

            bool operator==(const iterator& rhs) const {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const iterator& rhs) const {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        };  // END OF CLASS ITERATOR

        iterator begin(){return iterator(root);}
        iterator end(){return iterator(nullptr);}
        iterator begin_preorder(){return iterator(root);}
        iterator end_preorder(){return iterator(nullptr);}
        iterator begin_inorder(){return iterator(root);}
        iterator end_inorder(){return iterator(nullptr);}
        iterator begin_postorder(){return iterator(root);}
        iterator end_postorder(){return iterator(nullptr);}
    };
}