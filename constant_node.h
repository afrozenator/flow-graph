//============================================================================
// Name        : constant_node.h
// Author      : Afroz Mohiuddin
// Description : A constant node.
//============================================================================

#ifndef __CONSTANT_NODE_H__
#define __CONSTANT_NODE_H__

#include "node.h"

namespace flow_graphs {

class ConstantNode : public Node {
 public:
  ConstantNode(const string& name, NodeValue value, Nodes* parents);
  virtual ~ConstantNode() {}
  virtual NodeValue ComputeValue();
  virtual NodeValue du_dvi(Node* child);
  void set_node_value(NodeValue value);
};

}  // namespace flow_graphs

#endif  /* __CONSTANT_NODE_H__ */
