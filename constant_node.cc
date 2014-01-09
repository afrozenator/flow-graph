//============================================================================
// Name        : constant_node.cc
// Author      : Afroz Mohiuddin
// Description : A constant node.
//============================================================================

#include "constant_node.h"

#include "macros.h"

namespace flow_graphs {

ConstantNode::ConstantNode(const string& name, NodeValue value, Nodes* parents)
  : InputNode(name, true, value, parents) {}

void ConstantNode::set_node_value(NodeValue value) {
  LOG << "Trying to set the node value of constant node: " << name_
      << ", ignoring" << std::endl;
}

void ConstantNode::Reset() {
  LOG << "Trying to set the initialized of constant node: " << name_
      << ", to false, ignoring" << std::endl;
}

}  // namespace flow_graphs
