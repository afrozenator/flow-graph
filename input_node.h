// Explain this class

# ifndef __INPUT_NODE_H__
# define __INPUT_NODE_H__

#include "node.h"

namespace flow_graphs {

class InputNode : public Node {
 public:
  InputNode(const string& name);
  virtual ~InputNode();
  virtual void set_children(const Nodes& children);
  virtual void add_child(Node* child);
  virtual void ComputeValue();
};

}  // namespace flow_graphs

# endif // __INPUT_NODE_H__
