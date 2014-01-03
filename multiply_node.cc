//============================================================================
// Name        : multiply_node.cc
// Author      : Afroz Mohiuddin
// Description : A node that will multiply its children.
//============================================================================

#include "multiply_node.h"

namespace flow_graphs {

MultiplyNode::MultiplyNode(const string& name, Nodes* children, Nodes* parents)
  : Node(name, false, children, parents) {
}

NodeValue MultiplyNode::ComputeValue() {
  initialized_ = false;
  node_value_ = 1.0;
  for (Node* child : children_) {
    node_value_ *= child->node_value();
  }
  initialized_ = true;
  return node_value_;
}

NodeValue MultiplyNode::du_dvi(Node* child) {
  CHECK_NOTNULL(child);
  if (!initialized_) ComputeValue();
  return node_value_ / child->node_value();
}

}  // namespace flow_graphs
