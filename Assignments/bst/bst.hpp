// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// BST class
// Creates a BST to store values
// Uses Node which holds the Data
// Uses templates to store any type of Data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately

#ifndef BST_HPP
#define BST_HPP

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

template<class T>
class BST {
  // display BST tree in a human-readable format
  friend ostream &operator<<(ostream &Out, const BST &Bst) {
    Bst.printSideways(Out, Bst.Root);
    Out << endl;
    Bst.printVertical(Out, Bst.Root);
    return Out;
  }

private:
  // Node for BST
  struct Node {
    T Data;
    struct Node *Left;
    struct Node *Right;
  };

  // refer to data type "struct Node" as Node
  using Node = struct Node;

  // root of the tree
  Node *Root{nullptr};

  /**
   * This function create a Node
   * in the BST
   * @param: Item is the desired Node added into BST
   * @return: Returns said created Node
   */
  Node *createNode(T const &Item) {
    auto createNode = new Node;
    createNode->Data = Item; 
    createNode->Left = nullptr;
    createNode->Right = nullptr;
    return createNode;
  }

  /**
   * Helper function to add. Checks where to put data accordingly 
   * to what is already in BST.
   * @param: T const Item and Node Parent
   * @return: Bool function returning if successful or not in adding 
   */
  bool addComparer(T const &Item, Node Parent) { 
    if (Item < Parent.Data) {
      if (Parent.Left == nullptr) {
        Parent.Left = createNode(Item);
        return true; 
      }
      else if (Parent.Left != nullptr){
        addComparer(Item, *Parent.Left);
      }
    }
    else if(Item > Parent.Data) {
      if (Parent.Right == nullptr) {
        Parent.Right = createNode(Item);
        return true;
      }
      else if (Parent.Right != nullptr) {
        addComparer(Item, *Parent.Right);
      }
    }
    return false;
  }

  // height of a Node, nullptr is 0, Root is 1, static, no access to 'this'
  static int getHeight(const Node *N) {
    if (N == nullptr) {
      return 0;
    }
    return 1;
  }

  /**
   * Helper function to NumberOfNodes function
   * Counts all left and right nodes
   * @param: Takes in the BST
   * @return: Returns an int
   */ 
  int nodeCounter(Node *Root) const {
    if (Root == nullptr){
      return 0;
    }
    return 1 + nodeCounter(Root->Left) + nodeCounter(Root->Right);
  }

  /**
   * Helper function to contains
   * Identifies if BST contains a specific item
   * @param: Takes in Item and Root Node of BST
   * @return: Returns true or false depending on if Item was found
   */ 
  bool containsChecker(const T &Item, Node *Root) {
    while (Root != nullptr) {
      if (Root->Data == Item)
        return true;
      if (Root->Data > Item)
        Root = Root->Left;
      else
        Root = Root->Right;
      }
    return false;
  }

  /**
   * Helper function to clear and deconstructor
   * Clears and deletes nodes on tree
   * @param: Takes in the BST
   * @return: none 
   */ 
  void clearer(Node *Root) {
    if (Root == nullptr) {
      Root = nullptr;
    }
    else if (Root != nullptr) {
      clearer(Root->Left);
      clearer(Root->Right);
      delete Root;
    }
  }

  /**
   * Inorder Traversal
   * Visit nodes on the left of Root, then root, lastly the nodes on right
   * @param: Item paramater of type T and Root node 
   * @return: No return
   */ 
  void inOrderTraversalHelper(void Visit(const T &Item), Node *Root) const{
    if (Root != nullptr) {
      inOrderTraversalHelper(Visit, Root->Left);
      Visit(Root->Data);
      inOrderTraversalHelper(Visit, Root->Right);
    }
    else {
      cout << "Nothing in Root can't do this \n";
    }
  }

  /**
   * Preorder Traversal
   * Visit Root node then data left of Root then right
   * @param: Item paramater of type T and Root node 
   * @return: No return
   */ 
  void preOrderTraversalHelper(void Visit(const T &Item), Node *Root) const {
    if (Root != nullptr) {
      Visit(Root->Data);
      preOrderTraversalHelper(Visit, Root->Left);
      preOrderTraversalHelper(Visit, Root->Right);
    }
    else {
      cout << "Nothing in Root can't do this \n";
    }
  }

  /**
   * Postorder Traversal; left-root-root
   * Visit nodes on the left of Root then right and lastly root
   * @param: Item paramater of type T and Root node 
   * @return: No return
   */ 
  void postOrderTraversalHelper(void Visit(const T &Item), Node *Root) const {
    if (Root != nullptr) {
      postOrderTraversalHelper(Visit, Root->Left);
      postOrderTraversalHelper(Visit, Root->Right);
      Visit(Root->Data);
    }
    else {
      cout << "Nothing in Root can't do this \n";
    }
  }

  /**
   * heightCounter counts depth
   * Finds maxdepth
   * @param: Root Node parameter
   * @return: Returns max depth in the form of int
   */ 
  int heightCounter(Node *Root){
    if (Root == nullptr) {
      return 0;
    }
    else {
      int LeftDepth = heightCounter(Root->Left);
      int RightDepth = heightCounter(Root->Right);
      if (LeftDepth > RightDepth) {
        return (LeftDepth + 1); 
      }
      else {
        return (RightDepth + 1);
      }
    }
    return 0;
  }

  /**
   * OperatorEqual is a helper function to both operator functions 
   * Determines if two BST's are equal or not
   * @param: Two Root Node parameters
   * @return: Returns true or false depending on if equal or not
   */ 
  bool operatorEquals(Node *Root, Node *Root2) const { 
    if (Root == nullptr && Root2 == nullptr) {
      return true;
    }
    if (Root->Data != Root2->Data) {
      return false;
    }
    if (Root != nullptr && Root2 != nullptr) {
      return (operatorEquals(Root->Left, Root2->Left) &&
             operatorEquals(Root->Right, Root2->Right));
    }
    return false;
  }

  /**
   * Helper to copy constructor 
   * Creates a copy of BST 
   * @param: Takes in root
   * @return: No return
   */ 
  void copy(Node *Root) {
    if (Root != nullptr) {
      add(Root->Data);
      copy(Root->Left);
      copy(Root->Right);
    }
  }

  /**
   * Helper function to constructor that takes in an array and length 
   * to create a balanced BST
   * @param: Takes in Array and N length of array
   * @return: No return
   */ 
  void arrayToBST(const T Arr[], int N) {
    Root = createNode(Arr[0]);
    for(int I = 0; I < N; I++) {
      add(Arr[I]);
    }
    rebalance();
  }

  /**
   * Determines proper sucessor to node being removed
   * @param: Takes in BST and Item to be removed 
   * @return: Returns BST post removal
   */ 
  Node *removeNode(Node* Root, const T &Item) {
    if (Root == nullptr) {
      return Root;
    }
    if (Item < Root->Data) {
      Root->Left = removeNode(Root->Left, Item);
    }
    else if (Item > Root->Data) {
      Root->Right = removeNode(Root->Right, Item);
    }
    else {
      if (Root->Left == nullptr) {
        Node *NewRoot = Root->Right;
        delete Root;
        return NewRoot;
      }
      if (Root->Right == nullptr) {
        Node *NewRoot = Root->Left;
        delete Root;
        return NewRoot;
      }
      else {
        Node *NewRoot = minimumNode(Root->right);
        Root->Data = NewRoot->Data;
        Root->Right = removeNode(Root->Right, NewRoot->Data);
      }
    }
    return Root;
  }
  
  /**
   * Gets Left Most Node
   * @param: Takes in Node
   * @return: Left Most Node
   */ 
  Node *minimumNode(Node *CurrentNode)
  {
    while (CurrentNode && CurrentNode->Left != nullptr) {
      CurrentNode = CurrentNode->Left;
    }
    return CurrentNode;
  }

  /**
   * Creates and determines min height for tree and clears the tree
   * to put in balanced nodes 
   * @param: Takes in Array and amount of nodes in tree
   * @return: No return
   */ 
  void *rebalancer(T Contents[], int NumberOfNodes) {
    int Start = 0;
    int Finish = NumberOfNodes-1;
    for (int I = 0; I < Finish; I++) {
      if (Contents[I] < Contents[I-1]) {
        continue;
      }
    }
    clear();
    finalBst(Start, Finish, Contents);
  }

  /**
   * Creates the actual balanced BST
   * @param: Takes in Array and start and finish of array 
   * @return: returns final min height BST
   */ 
  Node* finalBst(int Start, int Finish, T Contents[]) { 
    int MiddleIdx = (Finish + Start) / 2;
    Node* RootFinal = makeNode(Contents[MiddleIdx]);
    RootFinal->Left = ArrayToBST(MiddleIdx-1, Start, Contents);
    RootFinal->Right = ArrayToBST(MiddleIdx+1, Finish, Contents);
    return RootFinal;
  }

  /**
   * Creates array of data in BST
   * @param: Takes in Array and BST, and counter
   * @return: No return
   */ 
  void arrayBuilder(Node *Root, T Array[], int *Counter) const {
    arrayBuilder(Root->Left, Array, Counter);
    Array[Counter++] = Root->Data;
    arrayBuilder(Root->Left, Array, Counter);
  }
  
  /**
   * print tree sideways with root on left
                6
            2
                5
        0
                4
            1
                3
   */
  static ostream &printSideways(ostream &Out, const Node *Curr, int Level = 0) {
    const static char SP = ' ';
    const static int ReadabilitySpaces = 4;
    if (!Curr)
      return Out;
    printSideways(Out, Curr->Right, ++Level);
    Out << setfill(SP) << setw(Level * ReadabilitySpaces) << SP;
    Out << Curr->Data << endl;
    printSideways(Out, Curr->Left, Level);
    return Out;
  }

  static ostream &centeredPrint(ostream &Out, int Space,
                                const string &Str, char FillChar = ' ') {
    auto StrL = static_cast<int>(Str.length());
    int Extra = (Space - StrL) / 2;
    if (Extra > 0) {
      Out << setfill(FillChar) << setw(Extra + StrL) << Str;
      Out << setfill(FillChar) << setw(Space - Extra - StrL) << FillChar;
    } else {
      Out << setfill(FillChar) << setw(Space) << Str;
    }
    return Out;
  }

  /**
   * print tree with the root at top
   *
      _____0______
   __1___      __2___
  3     4     5     6
   *
  **/
  static ostream &printTreeLevel(ostream &Out, queue<const Node *> &Q,
                                 int Width, int Depth, int MaxDepth) {
    const static char SP = ' ';
    const static char UND = '_';
    int Nodes = 0;
    int MaxN = pow(2, Depth - 1);
    int SpaceForEachItem = Width * pow(2, MaxDepth - 1) / MaxN; // NOLINT
    string
        Bigspace = string(static_cast<uint64_t>(SpaceForEachItem / 4), SP);
    while (Nodes++ < MaxN) {
      const Node *Tp = Q.front();
      Node *TpL = nullptr;
      Node *TpR = nullptr;
      Q.pop();
      string Label = "N";
      if (Tp) {
        stringstream Ss;
        Ss << Tp->Data;
        Label = Ss.str();
        TpL = Tp->Left;
        TpR = Tp->Right;
      }
      char Filler = Depth == MaxDepth ? SP : UND;
      if (Depth == MaxDepth) {
        centeredPrint(Out, SpaceForEachItem, Label, Filler);
      } else {
        Out << Bigspace;
        centeredPrint(Out, SpaceForEachItem / 2, Label, Filler);
        Out << Bigspace;
        Q.push(TpL);
        Q.push(TpR);
      }
    }
    Out << endl;
    return Out;
  }

  // helper function for displaying tree sideways, works recursively
  static ostream &printVertical(ostream &Out, Node *Curr) {
    const static int WIDTH = 6;  // must be even
    if (!Curr)
      return Out << "[__]";
    // figure out the maximum depth which determines how wide the tree is
    int MaxDepth = getHeight(Curr);
    queue<const Node *> Q;
    Q.push(Curr);
    for (int Depth = 1; Depth <= MaxDepth; ++Depth) {
      printTreeLevel(Out, Q, WIDTH, Depth, MaxDepth);
    }
    return Out;
  }

public:

  /**
   * constructor, empty tree.
   * Sets Root as nullptr
   * @param: No parameter
   * @return: No return 
   */
  BST() {
    Root = nullptr;
  }

  /**
   * constructor, tree with root
   * Creates root node
   * @param: const RootItem which is desired root value
   * @return: No return 
   */
  explicit BST(const T &RootItem) {
    Root = createNode(RootItem);
  }

  /**
   * Creates balanced BST of array 
   * @param: Takes in an array and length N of array 
   * @return: No return
   */ 
  BST(const T Arr[], int N) {
    arrayToBST(Arr, N);
    rebalance();
  }

  /**
   * Copy constructor. 
   * @param: BST
   * @return: No return
   */ 
  BST(const BST<T> &Bst) {
    copy(Bst.Root);
  }

  /**
   * Deconstructor. Destorys the tree and all nodes
   * @param: None
   * @return: No return
   */ 
  virtual ~BST() {
    Root = nullptr;
    clear();
  }

  /**
   * Checks if BST is empty or not. 
   * To do this it checks if the root is nullptr 
   * @param: none
   * @return: Returns true or false if empty or not respectively. 
   */ 
  bool isEmpty() const {
    return Root == nullptr;
  }

  /**
   * Gets height/max depth of tree. 
   * Uses helper function heightCounter to get depth
   * @param: none
   * @return: Returns height of BST
   */ 
  int getHeight() const {
    return heightCounter(Root);
  }

  /**
   * Number of nodes counts the amount of nodes in BST
   * Uses helper function to count
   * @param: none
   * @return: Returns nodeCounter which is an int function 
   */ 
  int numberOfNodes() const {
    return nodeCounter(Root);
  }

  /**
   * Add function adds values into BST 
   * Calls addComparer function to help out in the placing of "Item"
   * @param: const T Item is the desired item to be added into BST 
   * @return: Returns true or false if added successfully or not 
   */ 
  bool add(const T &Item) {
    if(Root == nullptr){
      Root = createNode(Item);
      return true;
    }
    else {
      return addComparer(Item, *Root);
    }
    return false;
  }

  /**
   * Removes Item from BST and finds the proper Node to replace 
   * @param: Item to be removed
   * @return: Returns true or false if removal was successful or not 
   */ 
  bool remove(const T &Item) {
    removeNode(Root, Item);
  }

  /**
   * Contains checks if Item is in BST 
   * Has helper function called containsChecker
   * @param: Item looking for
   * @return: Returns true or false if added successfully or not 
   */ 
  bool contains(const T &Item) const {
    if (Root == nullptr){
      return false;
    }
    else { 
      return containsChecker(Item, Root);
    }
    return false;
  }

  /**
   * Inorder Traversal; left-root-root
   * Helper function called inOrderTraversalHelper
   * @param: single parameter of type T
   * @return: No return
   */ 
  void inOrderTraverse(void Visit(const T &Item)) const {
    inOrderTraversalHelper(Visit, Root);
  }

  /**
   * Preorder Traversal
   * Helper function called preOrderTraversalHelper
   * @param: single parameter of type T
   * @return: No return
   */ 
  void preOrderTraverse(void Visit(const T &Item)) const {
    preOrderTraversalHelper(Visit, Root);
  }

  /**
   * Postorder Traversal
   * Helper function called postOrderTraversalHelper
   * @param: single parameter of type T
   * @return: No return
   */ 
  void postOrderTraverse(void Visit(const T &Item)) const {
    postOrderTraversalHelper(Visit, Root);
  }

  /**
   * Rebalance Function balances BST
   * Two Helper functions
   * @param: None 
   * @return: No return
   */
  void rebalance() {
    int Counter = 0;
    auto* ArrayStorer = new T[numberOfNodes()];
    arrayBuilder(Root, ArrayStorer, Counter);
    rebalancer(numberOfNodes(), ArrayStorer);
    delete[] ArrayStorer;
  }

  // delete all nodes in tree
  void clear() {
    Root = nullptr;
    clearer(Root);
  }

  /**
   * Opertaor== determines if two BST's are equal 
   * @param: Two Root Node parameters
   * @return: Returns true or false depending on if equal or not
   */ 
  bool operator==(const BST<T> &Other) const {
    return operatorEquals(Root, Other.Root);
  }

  /**
   * Operator!= determines if two BST's are not identical
   * @param: Two Root Node parameters
   * @return: Returns true or false depending on if equal or not
   */ 
  bool operator!=(const BST<T> &Other) const {
    return !(operatorEquals(Root, Other.Root));
  }
};

#endif  // BST_HPP
