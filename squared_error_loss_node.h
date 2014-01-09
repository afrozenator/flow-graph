//============================================================================
// Name        : 
// Author      : Afroz Mohiuddin
// Description : Error node, at the output of the network.
//============================================================================

#ifndef __SQUARED_ERROR_LOSS_NODE_H__
#define __SQUARED_ERROR_LOSS_NODE_H__

#include "node.h"

namespace flow_graphs {

class SquaredErrorLossNode : public Node {
 public:
  SquaredErrorLossNode(const string& name, Nodes* children);
  virtual ~SquaredErrorLossNode() {}
  void set_expected_value(NodeValue expected_value) {
    expected_value_ = expected_value;
  }
  NodeValue expected_value() const { return expected_value_; }
  virtual NodeValue ComputeValue();
  virtual NodeValue du_dvi(Node* child);

 private:
  NodeValue expected_value_;
  NodeValue actual_value_;
  Node* child_;
};

}  // namespace flow_graphs

#endif  /* __SQUARED_ERROR_LOSS_NODE_H__ */
