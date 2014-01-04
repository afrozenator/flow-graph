//============================================================================
// Name        : constant_node.h
// Author      : Afroz Mohiuddin
// Description : A constant node.
//============================================================================

#ifndef __CONSTANT_NODE_H__
#define __CONSTANT_NODE_H__

#include "input_node.h"

namespace flow_graphs {

class ConstantNode : public InputNode {
 public:
  ConstantNode(const string& name, NodeValue value, Nodes* parents);
  virtual ~ConstantNode() {}
  // Can't set/reset a constant node.
  virtual void set_node_value(NodeValue value);
  virtual void set_initialized_false();
};

}  // namespace flow_graphs

#endif  /* __CONSTANT_NODE_H__ */
