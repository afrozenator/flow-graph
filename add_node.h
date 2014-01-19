// Explain this class

# ifndef __ADD_NODE_H__
# define __ADD_NODE_H__

#include "node.h"

namespace flow_graphs {

class AddNode : public Node {
 public:
  AddNode(const string& name);
  virtual ~AddNode() {}
  virtual void ComputeValue();
};

}  // namespace flow_graphs

# endif // __ADD_NODE_H__
