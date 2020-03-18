#include "graph.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

/**
 * Constructor set values when an instance is made
 * Also sets value of edges and verticies to 0
 * @param: boolean DirectionalEdges
 * @return: No return
 **/  
Graph::Graph(bool DirectionalEdges) {
  this->DirectionalEdges = DirectionalEdges;
  NumEdges = 0;
  NumVertices = 0;
}

/**
 * Destructor
 * Clears graph
 * @param: No Param 
 * @return: No return
 **/  
Graph::~Graph() {
  for (auto Temp : Vertices) {
    for (auto &Neigh : Temp->Neighbors) {
      delete Neigh;
    }
    Temp->Neighbors.clear();
    delete Temp;
  }
  Vertices.clear();
  NumEdges = 0;
  NumVertices = 0;
}

/**
 * Reads file and creates Graph by reading edges from the file
 * @param: string refrence Filename for the filename
 * @return: Boolean return to tell if read successfully
 **/  
bool Graph::readFile(const string &Filename) {
  int Lines;
  ifstream FileOpener(Filename);
  FileOpener >> Lines;

  string From;
  string To;
  int Weight;

  if (!FileOpener.is_open()) {
    return false;
  }
  for (int I = 0; I < Lines; I++) {
    FileOpener >> From >> To >> Weight;
    connect(From, To, Weight);
  }
  FileOpener.close();
  return true;
}

/**
 * This function returns the number of verticies in graph 
 * @param: no param
 * @return: Return NumVertices  
 **/  
int Graph::verticesSize() const { return NumVertices; }

/**
 * This function returns the number of edges in graph 
 * @param: no param
 * @return: Return NumEdges
 **/  
int Graph::edgesSize() const { return NumEdges; }

/**
 * This function returns the amount of vertices adjacent to label 
 * and returns -1 if none
 * @param: string refrene Label
 * @return: Return the number of verticies
 **/  
int Graph::neighborsSize(const string &Label) const {
  Vertex *Vert = nullptr;
  if (this->find(Label, Vert)) {
    return Vert->Neighbors.size();
  }
  return -1;
}

/**
 * This function adds verticies to graph 
 * @param: string refrence label 
 * @return: Return boolean if vertex is added and false if not
 **/  
bool Graph::add(const string &Label) {
  if (!this->contains(Label)) {
    auto Vert = new Vertex(Label);
    Vertices.push_back(Vert); 
    NumVertices++;
    return true;
  }
  return false;
}

/**
 * This function check if a specific vertex is in graph 
 * @param: string refrence label 
 * @return: Return true if vertex is in graph and false if not
 **/  
bool Graph::contains(const string &Label) const {
  for (auto &Vert : Vertices) {
    if (Vert->Label == Label) {
      return true; 
    }
  }
  return false;
}

/**
 * getEdgesAsString creates string of edge and weights
 * @param: string refrence label 
 * @return: Return string type of details of what is in label and empty string if nothing is found
 **/  
string Graph::getEdgesAsString(const string &Label) const {
  string S;
  Vertex *Vert = nullptr;
  if (this->find(Label, Vert)) {
    if (Vert->Neighbors.empty()) {
      return S;
    } 
    S += Vert->Neighbors[0]->To->Label;
    S += "(" + to_string(Vert->Neighbors[0]->Weight) + ")";
    for (auto It = Vert->Neighbors.begin() + 1; It != Vert->Neighbors.end(); 
         ++It) {
      string L = (*It)->To->Label;
      int W = (*It)->Weight;
      S += "," + L;
      S += "(" + to_string(W) + ")";
    }
  }
  return S;
}

/**
 * This function connects two verticies together 
 * @param: string from to and weight
 * @return: Return boolean if vertex is connected and false if not
 **/  
bool Graph::connect(const string &From, const string &To, int Weight) {
  if (From == To) {
    return false;
  }
  Vertex *Vert1 = nullptr;
  Vertex *Vert2 = nullptr;

  if (!find(From, Vert1)) {
    Vert1 = new Vertex(From);
    Vertices.push_back(Vert1);
    NumVertices++;
  }

  if (!find(To, Vert2)) {
    Vert2 = new Vertex(To);
    Vertices.push_back(Vert2);
    NumVertices++;
  }
  bool C1 = false;
  bool C2 = false;
  auto E1 = new Edge(Vert1, Vert2, Weight);

  for (int I = 0; I < Vert1->Neighbors.size(); I++) {
    Edge *Temp = Vert1->Neighbors.at(I);
    if (From == Temp->From->Label && To == Temp->To->Label) {
      delete E1;
      return false;
    }
    if (To < Temp->To->Label) {
      Vert1->Neighbors.insert(Vert1->Neighbors.begin() + I, E1);
      NumEdges++;
      C1 = true;
      break;
    }
  }

  if (!C1) {
    Vert1->Neighbors.push_back(E1);
    NumEdges++;
  }
  if (!DirectionalEdges) {
    auto E2 = new Edge(Vert2, Vert1, Weight);
    for (int I = 0; I < Vert2->Neighbors.size(); I++) {
      Edge *Temp = Vert2->Neighbors.at(I);
      if (From == Temp->From->Label && To == Temp->To->Label) {
        delete E2;
        return false;
      }
      if (To < Temp->To->Label) {
        Vert2->Neighbors.insert(Vert2->Neighbors.begin() + I, E2);
        C2 = true;
        break;
      }
    }

    if (!C2) {
      Vert2->Neighbors.push_back(E2);
    }
  }
  return true;
}

/**
 * This function disconnects two verticies
 * @param: string refrence from and to 
 * @return: return true or false if disconnection was successful and false if not 
 **/ 
bool Graph::disconnect(const string &From, const string &To) {
  Vertex *Vert = nullptr;
  if (!find(From, Vert)) {
    return false;
  }
  for (int I = 0; I < Vert->Neighbors.size(); I++) {
    Edge *E = Vert->Neighbors.at(I);
    if (From == E->From->Label && To == E->To->Label) {
      Vert->Neighbors.erase(Vert->Neighbors.begin() + I);
      delete E;
      NumEdges--;
      if (!DirectionalEdges) {
        Vertex *Vert2 = nullptr;
        find(To, Vert2);
        for (int J = 0; J < Vert2->Neighbors.size(); J++) {
          Edge *E2 = Vert2->Neighbors.at(J);
          if (To == E2->From->Label && From == E2->To->Label) {
            Vert2->Neighbors.erase(Vert2->Neighbors.begin() + J);
            delete E2;
            break;
          }
        }
      }
      return true;
    }
  }
  return false;
}

/**
 * This function is an implementation of depth first search
 * @param: stringStart Label and end Label and void visit
 * @return: No return
 **/ 
void Graph::dfs(const string &StartLabel, void Visit(const string &Label)) {
  for (auto &Vert : Vertices) {
    Vert->Visited = false;
  }
  Vertex *Vert = nullptr;
  if (!find(StartLabel, Vert)) {
    return;
  }
  dfsHelper(Vert, Visit);
}

/**
 * This function is an implenetation of breadth-fisrt search
 * @param: string refrence startlabel and end label
 * @return: No return
 **/ 
void Graph::bfs(const string &StartLabel, void Visit(const string &Label)) {
  for (auto &V : Vertices) {
    V->Visited = false;
  }
  Vertex *V = nullptr;
  if (!find(StartLabel, V)) {
    return;
  }
  V->Visited = true;
  queue<Vertex *> Q;
  Q.push(V);
  while (!Q.empty()) {
    Vertex *Temp = Q.front();
    Q.pop();
    Visit(Temp->Label);
    for (auto &Neighbor : Temp->Neighbors) {
      Vertex *N = Neighbor->To;
      if (!N->Visited) {
        N->Visited = true;
        Q.push(N);
      }
    }
  }
}

/**
 * Implementation of dijakstra's algorithm
 * @param: String startLabel 
 * @return: Return map
 **/ 
pair<map<string, int>, map<string, string>>
Graph::dijkstra(const string &StartLabel) const {
  map<string, int> Weights;
  map<string, string> Previous;
  for (auto &V : Vertices) {
    V->Visited = false;
  }
  Vertex *V = nullptr;
  if (!find(StartLabel, V)) {
    return make_pair(Weights, Previous);
  }
  vector<Vertex *> VisitedArr;
  V->Visited = true;
  VisitedArr.push_back(V);
  for (int I = 0; I < VisitedArr.size(); I++) {
    vector<Edge *> SmallestEdges = smallestNeighbors(VisitedArr);
    Edge *E = minDistance(SmallestEdges, Weights);
    if (E == nullptr) {
      break;
    }
    E->To->Visited = true;
    VisitedArr.push_back(E->To);

    auto It = Weights.find(E->From->Label);
    if (It == Weights.end()) {
      Weights.emplace(E->To->Label, E->Weight);
      Previous.emplace(E->To->Label, E->From->Label);
    } else {
      Weights.emplace(E->To->Label, (*It).second + E->Weight);
      Previous.emplace(E->To->Label, E->From->Label);
    }
  }
  return make_pair(Weights, Previous);
}

/**
 * minimum spanning tree implementation
 * @param: string refrence Start Label and visit funsction of From To and Weight
 * @return length of the minimum spanning tree and -1 if not found
 */
int Graph::mst(const string &StartLabel,
               void Visit(const string &From, const string &To,
                          int Weight)) const {
  assert(!DirectionalEdges);

  for (auto &V : Vertices) {
    V->Visited = false;
  }
  Vertex *V = nullptr;
  if (!find(StartLabel, V)) {
    return -1;
  }
  vector<Vertex *> MstFinal;
  V->Visited = true;
  MstFinal.push_back(V);
  int Sum = 0;

  for (int I = 0; I < MstFinal.size(); I++) {
    vector<Edge *> SmallestEdges = smallestNeighbors(MstFinal);
    Edge *Edge = minWeight(SmallestEdges);

    if (Edge == nullptr) {
      break;
    }

    Edge->To->Visited = true;
    MstFinal.push_back(Edge->To);
    Visit(Edge->From->Label, Edge->To->Label, Edge->Weight);
    Sum += Edge->Weight;
  }
  return Sum;
}

/**
 * This function finds the desired edge
 * @param: String refrence Label and Vertex V value
 * @return return true or false if found or not respecrtively
 */
bool Graph::find(const string &Label, Vertex *&Vert) const {
  for (auto &Vertex : Vertices) {
    if (Vertex->Label == Label) {
      Vert = Vertex;
      return true;
    }
  }
  return false;
}

void Graph::dfsHelper(Vertex *V, void Visit(const string &Label)) {
  if (V == nullptr) {
    return;
  }
  V->Visited = true;
  Visit(V->Label);
  for (auto &Neighbor : V->Neighbors) {
    Vertex *Temp = Neighbor->To;
    if (!Temp->Visited)
      dfsHelper(Temp, Visit);
  }
}

/**
 * This function gets the edge with the smallest weight
 * @param: Vertex Edge pointer
 * @return Returns type Edge
 */
Edge *Graph::minWeight(vector<Edge *> SmallestEdges) {
  if (SmallestEdges.empty()) {
    return nullptr;
  }
  Edge *Min = SmallestEdges[0];
  for (int I = 1; I < SmallestEdges.size(); I++) {
    Edge *Temp = SmallestEdges[I];
    if (Temp->Weight < Min->Weight) {
      Min = Temp;
    }
  }
  return Min;
}

/**
 * Helpter function to dijakstra's gets smallest distance
 * @param: Vector Edge and Map
 * @return length of the minimum spanning tree and -1 if not found
 */
Edge *Graph::minDistance(vector<Edge *> SmallestEdges,
                         map<string, int> Weights) {
  if (SmallestEdges.empty()) {
    return nullptr;
  }
  Edge *Min = SmallestEdges[0];
  for (int I = 1; I < SmallestEdges.size(); I++) {
    Edge *Temp = SmallestEdges[I];

    auto ItMin = Weights.find(Min->From->Label);
    auto ItTemp = Weights.find(Temp->From->Label);

    int MinDistance = (ItMin == Weights.end()) ? 0 : (*ItMin).second;
    int TempDistance = (ItTemp == Weights.end()) ? 0 : (*ItTemp).second;

    if (Temp->Weight + TempDistance < Min->Weight + MinDistance) {
      Min = Temp;
    }
  }
  return Min;
}

/**
 * This function finds the smallest neightbor and is a helper function to
 * dijakstra's and minimum spanning tree
 * @param: Visited Array Vector of type pointer vertex
 * @return Returns the smallest Neighbor Vector
 */
vector<Edge *> Graph::smallestNeighbors(vector<Vertex *> VisitedArr) {
  vector<Edge *> SmallestEdges;
  for (int I = 0; I < VisitedArr.size(); I++) {
    vector<Edge *> N = VisitedArr.at(I)->Neighbors;
    Edge *Min;
    if (N.empty()) {
      VisitedArr.erase(VisitedArr.begin() + I);
      I--;
      continue;
    }
    int E = 0;
    Min = N[E];
    while (E + 1 < N.size() && Min->To->Visited) {
      Min = N[++E];
    }
    for (int J = E + 1; J < N.size(); J++) {
      Edge *Temp = N.at(J);
      if (Temp->To->Visited) {
        continue;
      }
      if (Temp->Weight < Min->Weight) {
        Min = Temp;
      }
    }
    if (Min == nullptr || Min->To->Visited) {
      VisitedArr.erase(VisitedArr.begin() + I);
      I--;
      continue;
    }
    SmallestEdges.push_back(Min);
  }
  return SmallestEdges;
}