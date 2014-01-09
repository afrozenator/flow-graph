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

  // Derivative of the loss with respect to a particular weight.
  virtual NodeValue dL_dwi(size_t weight_index) ABSTRACT;
  virtual void dL_dw(vector<NodeValue>* derivatives_wrt_weight);

 protected:
  vector<NodeValue> weights_;
  vector<NodeValue> derivative_loss_wrt_weights_;
};

}  // namespace flow_graphs

#endif  /* __WEIGHTED_NODE_H__ */
