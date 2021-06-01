/**
 * Demo file for the exercise on binary tree
 *
 * @author Erel Segal-Halevi
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <queue>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

int main() {
  // BinaryTree<string> t_str;
  // string root = "|";
  // t_str.add_root(root);
  // string prev = root;
  // for (int i = 2; i <= 50; i++)
  // {
  //     string str;
  //     for (int j = 0; j < i; j++)
  //     {
  //         str += "|";
  //     }
  //     t_str.add_left(prev, str);
  //     prev = str;
  // }
  // int i = 50;
  // /* Comparing the increasing size to the size of the string in inOrder iteration*/
  // for (auto it = t_str.begin_inorder(); it != t_str.end_inorder(); it++)
  // {
  //     if (i-- == it->size())
  //     {
  //       cout << "success\n";
  //     }
  // }
  queue<int*> my;
  int x = 1;
  int* ptr = &x;
  my.push(ptr);
  cout << my.front()<< endl;
  my.pop();
  cout << my.front()<< endl;
  my.pop();
  cout << my.front()<< endl;
}
