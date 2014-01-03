//============================================================================
// Name        : multiply_node.h
// Author      : Afroz Mohiuddin
// Description : A node that will multiply its children.
//============================================================================

#ifndef __MULTIPLY_NODE_H__
#define __MULTIPLY_NODE_H__

#include "node.h"

namespace flow_graphs {

class MultiplyNode : public Node {
 public:
  MultiplyNode(const string& name, Nodes* children, Nodes* parents);
  virtual ~MultiplyNode() {}
  virtual NodeValue ComputeValue();
  virtual NodeValue du_dvi(Node* child);
};

}  // namespace flow_graphs

#endif  /* __MULTIPLY_NODE_H__ */
