//============================================================================
// Name        : weighted_node.h
// Author      : Afroz Mohiuddin
// Description : A simple node that doesn't do any computation, but has weights
//               associated with edges.
//============================================================================

#ifndef __WEIGHTED_NODE_H__
#define __WEIGHTED_NODE_H__

#include "node.h"

namespace flow_graphs {

class WeightedNode : public Node {
 public:
  WeightedNode(const string& name, Nodes* children, Nodes* parents);
  virtual ~WeightedNode() {}
  void set_default_weights();
  void set_weights(const vector<NodeValue>& weights);
  const vector<NodeValue>& weights() const { return weights_; }

 protected:
  vector<NodeValue> weights_;
};

}  // namespace flow_graphs

#endif  /* __WEIGHTED_NODE_H__ */
