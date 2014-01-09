//============================================================================
// Name        : 
// Author      : Afroz Mohiuddin
// Description : Error node, at the output of the network.
//============================================================================

#include <limits>

#include "squared_error_loss_node.h"
#include "macros.h"

namespace flow_graphs {

SquaredErrorLossNode::SquaredErrorLossNode(const string& name, Nodes* children)
    : Node(name, false, children, NULL) {
      CHECK_NOTNULL(children);
      CHECK(children->size() == 1);
      child_ = children->at(0);
      expected_value_ = -std::numeric_limits<NodeValue>::max();
}

NodeValue SquaredErrorLossNode::ComputeValue() {
  initialized_ = false;
  actual_value_ = child_->node_value();
  NodeValue expected_minus_actual = expected_value_ - actual_value_;
  node_value_ = expected_minus_actual * expected_minus_actual * 0.5;
  initialized_ = true;
  return node_value_;
}

NodeValue SquaredErrorLossNode::du_dvi(Node* child) {
  CHECK(!(child_ != child));
  return actual_value_ - expected_value_;
}

}  // namespace flow_graphs
