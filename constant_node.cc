//============================================================================
// Name        : constant_node.cc
// Author      : Afroz Mohiuddin
// Description : A constant node.
//============================================================================

#include "constant_node.h"

#include "macros.h"

namespace flow_graphs {

ConstantNode::ConstantNode(const string& name, NodeValue value, Nodes* parents)
  : Node(name, true, NULL, parents, value) {}

NodeValue ConstantNode::ComputeValue() {
  return node_value_;
}

NodeValue ConstantNode::du_dvi(Node* child) {
  LOG_FATAL("Constant node has no children!");
}

void ConstantNode::set_node_value(NodeValue value) {
  node_value_ = value;
}

}  // namespace flow_graphs
