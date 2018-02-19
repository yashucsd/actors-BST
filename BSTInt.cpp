
#include "BSTInt.h"

/*  Function definitions for a int-based BST class
    Yash Nevatia
    9 April 2017
*/

/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt()
{
    deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item) {
    if (!root) {
        root = new BSTNodeInt(item);
        ++isize;
        return true;
    }

    BSTNodeInt * curr = root;

    while(true){

        if (item == curr->data)
            return false;

        else if(item < curr->data){
            if(!(curr->left)) {
                curr->left = new BSTNodeInt(item);
                ++isize;
                return true;
            } else {
                curr = curr->left;
                continue;
            }

        } else if (curr->data < item) {
            if(!(curr->right)) {
                curr->right = new BSTNodeInt(item);
                ++isize;
                return true;
            } else {
                curr = curr->right;
                continue;
            }
        }

        return false;
    }

    ++isize;
    return true;
}

/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
    BSTNodeInt* curr = root;
    while (curr)
    {
        if (curr->data < item)
        {
            curr = curr->right;
        }
        else if (item < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            return true;
        }
    }
    return false;
}

/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const
{
    return isize;
}

/** Return the height of the BST.
    Height of tree with just root node is 0
 */
int BSTInt::height() const
{
    if (!root)
        return 0;
    return heightHelp(root);
}

// helps the height function find the height of the tree recursively
int BSTInt::heightHelp(BSTNodeInt* n) const
{
    if (n->right || n->left)
    {
        int rightHeight = 0, leftHeight = 0;
        if (n->right)
            rightHeight = heightHelp(n->right);
        if (n->left)
            leftHeight = heightHelp(n->left);

        if (rightHeight > leftHeight)
            return rightHeight + 1;
        else
            return leftHeight + 1;
    }
    return 0;
}

/** Return true if the BST is empty, else false.
 */
bool BSTInt::empty() const
{
    return size() == 0;
}

/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n) {
    if (n->left)
        deleteAll(n->left);
    if (n->right)
        deleteAll(n->right);
    delete(n);
}
