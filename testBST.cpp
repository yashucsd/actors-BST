#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * Date: 9 April 2017
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    vector<char> c;
    c.push_back('a');
    c.push_back('s');
    c.push_back('z');
    c.push_back('q');
    c.push_back('b');

    int properheight = 2;

    /*

    // Create an instance of BST holding int 
    BSTInt b;

    // tests insert
    if(!b.empty()){
        cout << "Empty function is broken" << endl;
        return -1;
    }

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting "
            << item << endl;
            return -1;
        }
    }

    // Test size. 
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    // Test find return value. 
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    // tests inserting of duplicates
    for(int item : v) {
        if(b.find(item) && !(b.insert(item))) {
            cout << "Trouble w duplicates, specifically " << item << endl;
            return -1;
        }
    }

    // tests find function
    if(b.find(6)){
        cout << "Found nonexistant element" << endl;
        return -1;
    }

    // tests height
    int height = b.height();
    if(height != properheight){
        cout << "Incorrect implementation; height is " << height
        << ", and should be " << properheight << endl;
        return -1;
    }

    */

    // UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR 

    // Test the template version of the BST with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }

    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    int height = btemp.height();
    if(height != properheight){
        cout << "Incorrect implementation; height is " << height
        << ", and should be " << properheight << endl;
        return -1;
    }

    BST<char> ctemp;
    for (char item : c) {
        // The auto type here is the pair of BSTIterator<char>, bool
        cout << "Inserting " << item << " into the char template-based BST...";
        auto p = ctemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    cout << "All tests passed!" << endl;
    return 0;
}
