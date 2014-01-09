//============================================================================
// Name        : add_node.h
// Author      : Afroz Mohiuddin
// Description : A simple node that adds all its children.
//============================================================================

#ifndef __ADD_NODE_H__
#define __ADD_NODE_H__

#include "weighted_node.h"

namespace flow_graphs {

class AddNode : public WeightedNode {
 public:
  AddNode(const string& name, Nodes* children, Nodes* parents);
  virtual ~AddNode() {}
  virtual NodeValue ComputeValue();
  virtual NodeValue du_dvi(Node* child);
  virtual void du_dv(vector<NodeValue>* derivatives_wrt_children);
  virtual NodeValue dL_dwi(size_t weight_index);
};

}  // namespace flow_graphs

#endif  /* __ADD_NODE_H__ */
