// fig13_28.cpp

#include <iostream>
#include <string>

// Struct TreeNode
// Behavior like a pointer by using Use Count
class TreeNode {
  public:
  	// Constructor
  	TreeNode(const std::string &var, TreeNode *left_ = nullptr, TreeNode *right_ = nullptr)
  		: value(var), left(left_), right(right_), count(new int(1)) { }
  	// Copy-constructor
  	TreeNode(const TreeNode *other) 
  		: value(other.value), left(other.left), right(other.right) {
  		++*other.count;
  		count = other.count;
    }
    // Copy-assignment
    TreeNode& operator=(const TreeNode &rhs) {
    	++*rhs.count;
    	if (--*count == 0) {
    		delete left;
    		delete right;
    		delete count;
    	}
    	value = rhs.value;
    	count = rhs.count;
    	left  = rhs.left;
    	right = rhs.right;

    	return *this;
    }
    // Destructor
    virtual ~TreeNode() {
    	if (--*count == 0) {
    		delete left;
    		delete right;
    		delete count;
    	}
    }
    // Access
    std::string GetValue() const {
    	return value;
    }
    // Set left child and right child
    void SetLeftChild(TreeNode *child);
    void SetRightChild(TreeNode *child);
  private:
  	std::string value;
  	int		   *count;
  	TreeNode   *left;
  	TreeNode   *right;
};


// Struct Binary Tree
class BinaryStrTree {
  public:
  	BinaryStrTree(TreeNode *root_ = nullptr) 
  		: root(root_) { }
  	BinaryStrTree(const BinaryStrTree &other)
  		: root(other.root) { 
  		}
  private:
  	TreeNode *root;
};