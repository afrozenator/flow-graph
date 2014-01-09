//============================================================================
// Name        : add_node.cc
// Author      : Afroz Mohiuddin
// Description : A simple node that adds all its children.
//============================================================================

#include "add_node.h"

namespace flow_graphs {

AddNode::AddNode(const string& name, Nodes* children, Nodes* parents)
  : WeightedNode(name, children, parents) {
}

NodeValue AddNode::ComputeValue() {
  node_value_ = 0.0;
  initialized_ = false;
  for (size_t i = 0; i < weights_.size(); ++i) {
    node_value_ += weights_[i] * children_[i]->node_value();
  }
  initialized_ = true;
  return node_value_;
}

NodeValue AddNode::du_dvi(Node* child) {
  // This is quite simply the weight, since this is a weighted sum.
  return weights_[ChildIndex(child)];
}

void AddNode::du_dv(vector<NodeValue>* derivatives_wrt_children) {
  CHECK_NOTNULL(derivatives_wrt_children);
  derivatives_wrt_children->clear();
  derivatives_wrt_children->assign(weights_.begin(), weights_.end());
}

// dL/dw = dL/du * du/dw ... where du/dw for weighted addition is just input.
NodeValue AddNode::dL_dwi(size_t weight_index) {
  return dL_du() * children_[weight_index]->node_value();
}

}  // namespace flow_graphs
