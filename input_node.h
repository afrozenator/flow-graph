//============================================================================
// Name        : input_node.h
// Author      : Afroz Mohiuddin
// Description : An input node.
//============================================================================

#ifndef __INPUT_NODE_H__
#define __INPUT_NODE_H__

#include "node.h"

namespace flow_graphs {

class InputNode : public Node {
 public:
  InputNode(const string& name, NodeValue value, Nodes* parents);
  InputNode(const string& name, Nodes* parents);
  virtual ~InputNode() {}
  virtual NodeValue ComputeValue();
  virtual NodeValue du_dvi(Node* child);
 protected:
  InputNode(const string& name, bool constant, NodeValue value, Nodes* parents);
};

}  // namespace flow_graphs

#endif  /* __INPUT_NODE_H__ */
