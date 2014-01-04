//============================================================================
// Name        : input_node.cc
// Author      : Afroz Mohiuddin
// Description : An input node.
//============================================================================

#include "input_node.h"

#include "macros.h"

namespace flow_graphs {

InputNode::InputNode(const string& name, NodeValue value, Nodes* parents)
  : Node(name, false, NULL, parents, value) {}

InputNode::InputNode(const string& name, Nodes* parents)
  : Node(name, false, NULL, parents) {}

InputNode::InputNode(const string& name, bool constant, NodeValue value,
                     Nodes* parents)
  : Node(name, true, NULL, parents, value) {}

NodeValue InputNode::ComputeValue() {
  return node_value_;
}

NodeValue InputNode::du_dvi(Node* child) {
  LOG_FATAL("Input node has no children!");
}

}  // namespace flow_graphs
