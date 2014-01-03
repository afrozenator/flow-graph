//============================================================================
// Name        : add_node.cc
// Author      : Afroz Mohiuddin
// Description : A simple node that adds all its children.
//============================================================================

#include "add_node.h"

namespace flow_graphs {

AddNode::AddNode(const string& name, Nodes* children, Nodes* parents)
  : Node(name, false, children, parents) {
  if (!children_.empty()) SetWeights();
}

void AddNode::SetWeights() {
  weights_.assign(children_.size(), 1.0);
}

void AddNode::SetWeights(const vector<NodeValue>& weights) {
  weights_.assign(weights.begin(), weights.end());
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

}  // namespace flow_graphs
