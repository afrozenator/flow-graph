//============================================================================
// Name        : main.cc
// Author      : Afroz Mohiuddin
// Description : A simple flow graph.
//============================================================================

#include <iostream>

#include "add_node.h"
#include "constant_node.h"
#include "multiply_node.h"
#include "node.h"

using flow_graphs::Node;
using flow_graphs::NodeValue;
using flow_graphs::Nodes;
using flow_graphs::AddNode;
using flow_graphs::ConstantNode;
using flow_graphs::MultiplyNode;

int main(int argc, char** argv) {
  // Construct the graph.
  ConstantNode c1("c1", 1, NULL);
  ConstantNode c2("c2", 2, NULL);
  ConstantNode c3("c3", 3, NULL);
  ConstantNode c4("c4", 4, NULL);
  Nodes adds_children{&c1, &c2, &c3};
  AddNode a("a", &adds_children, NULL);
  c1.AddParent(&a); c2.AddParent(&a); c3.AddParent(&a);
  a.SetWeights({1.0, 2.0, 3.0});
  Nodes mults_children{&a, &c4};
  MultiplyNode m("m", &mults_children, NULL);
  a.AddParent(&m); c4.AddParent(&m);
  // Graph constructed.

  NodeValue nv = m.node_value();
  std::cout << "Multiply Node's output: " << nv << std::endl;
}
