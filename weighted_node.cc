//============================================================================
// Name        : weighted_node.cc
// Author      : Afroz Mohiuddin
// Description : A simple node that doesn't do any computation, but has weights
//               associated with edges.
//============================================================================

#include "weighted_node.h"

namespace flow_graphs {

WeightedNode::WeightedNode(const string& name, Nodes* children, Nodes* parents)
  : Node(name, false, children, parents) {
  if (!children_.empty()) set_default_weights();
}

void WeightedNode::set_default_weights() {
  weights_.assign(children_.size(), 1.0);
}

void WeightedNode::set_weights(const vector<NodeValue>& weights) {
  CHECK(weights.size() == children_.size());
  weights_.assign(weights.begin(), weights.end());
}

void WeightedNode::dL_dw(vector<NodeValue>* derivatives_wrt_weight) {
  CHECK_NOTNULL(derivatives_wrt_weight);
  derivatives_wrt_weight->clear();
  for (size_t idx = 0; idx < weights_.size(); ++idx) {
    derivatives_wrt_weight->push_back(dL_dwi(idx));
  }
}

}  // namespace flow_graphs
