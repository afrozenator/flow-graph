//============================================================================
// Name        : add_node.h
// Author      : Afroz Mohiuddin
// Description : A simple node that adds all its children.
//============================================================================

#ifndef __ADD_NODE_H__
#define __ADD_NODE_H__

#include "node.h"

namespace flow_graphs {

class AddNode : public Node {
 public:
  AddNode(const string& name, Nodes* children, Nodes* parents);
  AddNode(const string& name, Nodes* children, Nodes* parents, NodeValue value);
  virtual ~AddNode() {}
  virtual NodeValue ComputeValue();
  virtual NodeValue du_dvi(Node* child);
  virtual void du_dv(vector<NodeValue>* derivatives_wrt_children);
  void SetWeights();
  void SetWeights(const vector<NodeValue>& weights);
  const vector<NodeValue>& Weights() const;

 protected:
  vector<NodeValue> weights_;
};

}  // namespace flow_graphs

#endif  /* __ADD_NODE_H__ */
