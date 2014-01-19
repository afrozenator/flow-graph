// Author: afrozm@google.com (Afroz Mohiuddin)

#include <iostream>

#include "node.h"
#include "node_utils.h"
#include "add_node.h"
#include "multiply_node.h"
#include "constant_node.h"
#include "input_node.h"

using flow_graphs::AddNode;
using flow_graphs::ConstantNode;
using flow_graphs::MultiplyNode;
using flow_graphs::Node;
using flow_graphs::Nodes;
using flow_graphs::InputNode;
using flow_graphs::NodeUtils;
using flow_graphs::Value;

void SetInputs(InputNode* x, InputNode* y, Value x_val, Value y_val) {
  x->set_value(x_val);
  y->set_value(y_val);
}

int main(int argc, char **argv) {

  // In here we'll show the flow graph to calculate
  // 2x^2 + 3xy

  // TODO(afro): Draw this somehow.
  //     ---
  //     |*|
  //     ---
  //
  // ---     ---      ---         ---
  // |2|     |x|      |3|         |y|
  // ---     ---      ---         ---

  ConstantNode c2("2", 2.0);
  ConstantNode c3("3", 3.0);

  InputNode x("x");
  InputNode y("y");

  MultiplyNode m1("2x^2");
  MultiplyNode m2("3xy");

  AddNode a("2x^2 + 3xy");

  NodeUtils::AddEdge(&m1, &c2);
  NodeUtils::AddEdge(&m1, &x);
  NodeUtils::AddEdge(&m1, &x);

  NodeUtils::AddEdge(&m2, &c3);
  NodeUtils::AddEdge(&m2, &x);
  NodeUtils::AddEdge(&m2, &y);

  NodeUtils::AddEdge(&a, &m1);
  NodeUtils::AddEdge(&a, &m2);

  Nodes execution_order{&m1, &m2, &a};

  NodeUtils::ResetTree(&a);
  SetInputs(&x, &y, 5, 8);
  NodeUtils::ComputeValues(&execution_order);
  std::cout << "Final value of " << a.name() << " is: " << a.value() << std::endl;

  NodeUtils::ResetTree(&a);
  SetInputs(&x, &y, 1, 2);
  NodeUtils::ComputeValues(&execution_order);
  std::cout << "Final value of " << a.name() << " is: " << a.value() << std::endl;

  return 0;
}
