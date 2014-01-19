// Explain this class

# ifndef __MULTIPLY_NODE_H__
# define __MULTIPLY_NODE_H__

#include "node.h"

namespace flow_graphs {

class MultiplyNode : public Node {
 public:
  MultiplyNode(const string& name);
  virtual ~MultiplyNode();
  virtual void ComputeValue();
};

}  // namespace flow_graphs

# endif // __MULTIPLY_NODE_H__
