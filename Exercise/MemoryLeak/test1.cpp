#include <cassert>
#include <iostream>

using namespace std;

class NodeTest1 {
  friend ostream &operator<<(ostream &Out, const NodeTest1 &N) {
    Out << "N<" << N.Value << ", " << (N.Next != nullptr) << ">";
    return Out;
  }

public:
  static int NodeCount;
  //added
  int Value = 0;
  NodeTest1 *Next = nullptr;

  explicit NodeTest1(int Value = 0, NodeTest1 *Next = nullptr)
      : Value{Value}, Next{Next} {
    ++NodeCount;
    cout << "Creating " << this << ", total created: " << NodeCount << endl;
  }
  ~NodeTest1() {
    cout << "Deleting: " << this;
    --NodeCount;
    //added
    delete Next;
    cout << ", nodes remaining: " << NodeCount << endl;
  }
};

int NodeTest1::NodeCount = 0;

void test1() {

  NodeTest1 N1(1);
  
  NodeTest1 *N1Ptr = nullptr;
  N1Ptr = &N1;
  assert(N1Ptr != nullptr);
  
  auto *N2Ptr = new NodeTest1(3);
  auto *N3Arr = new NodeTest1[10];
  
  for (int I = 0; I < 5; ++I) {
    NodeTest1 Tmp(I * I);
    N3Arr[I] = Tmp;
  }
  auto N4Arr = new NodeTest1 *[10];
  for (int I = 6; I < 10; ++I) {
    auto *Tmp = new NodeTest1(I * I);
    N4Arr[I] = Tmp;
    delete Tmp;
  }

  //added
  delete N2Ptr;
  delete[] N3Arr;
  N2Ptr = nullptr;
  N3Arr = nullptr;
  delete[] N4Arr;
  
}