// Explain this class

# ifndef __CONSTANT_NODE_H__
# define __CONSTANT_NODE_H__

#include "node.h"

namespace flow_graphs {

class ConstantNode : public Node {
 public:
  ConstantNode(const string& name, Value value);
  virtual ~ConstantNode();
  // We can't do somethings on constant nodes:
  // (Re)Setting the value.
  // Adding children, since this shouldn't 'depend' on other nodes.
  virtual void set_children(const Nodes& children);
  virtual void add_child(Node* child);
  virtual void set_value(Value value);
  virtual void Reset();
  // The value has already been computed, so this should be a no-op.
  virtual void ComputeValue();
};

}  // namespace flow_graphs

# endif // __CONSTANT_NODE_H__
