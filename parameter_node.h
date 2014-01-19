// Explain this class

# ifndef __PARAMETER_NODE_H__
# define __PARAMETER_NODE_H__

#include "node.h"

namespace flow_graphs {

class ParameterNode : public Node {
 public:
  ParameterNode(const string& name, Value value);
  virtual ~ParameterNode();
  // We can't do some things on parameter nodes:
  // Adding children, since this shouldn't 'depend' on other nodes.
  virtual void set_children(const Nodes& children);
  virtual void add_child(Node* child);
  virtual void Reset();
  // The value has already been computed, so this should be a no-op.
  virtual void ComputeValue();
};

}  // namespace flow_graphs

# endif // __PARAMETER_NODE_H__
