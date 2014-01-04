//============================================================================
// Name        : node.h
// Author      : Afroz Mohiuddin
// Description : Abstract class for a node in a Flow Graph
//============================================================================

#ifndef __NODE_H__
#define __NODE_H__

#include "macros.h"
#include "using_declarations.h"

namespace flow_graphs {

class Node;

typedef double NodeValue;
typedef vector<Node*> Nodes;

class Node {
 public:
  Node(const string& name, bool constant_node, Nodes* children, Nodes* parents);
  Node(const string& name, bool constant_node, Nodes* children, Nodes* parents,
       NodeValue u);
  virtual ~Node();
  // Compute the value of this node from the value of its children.
  // Classes deriving from this have control over how to implement this
  // function (and will need to have other parameters as well).
  virtual NodeValue ComputeValue() ABSTRACT;
  // This calls |ComputeValue| if it isn't initialized.
  NodeValue node_value();
  // Set children.
  void SetChildren(const Nodes& children);
  void AddChild(Node* child);
  const Nodes& Children() const { return children_; }
  // Set parents
  void SetParents(const Nodes& parents);
  void AddParent(Node* parent);
  const Nodes& Parents() const { return parents_; }

  virtual void set_node_value(NodeValue value) { node_value_ = value; }
  virtual void set_initialized_false() { initialized_ = false; }

  // These are useful for backpropagation

  // The partial derivative of the loss function (L) wrt this node's value (u).
  NodeValue dL_du();
  // The partial derivative of this node's value wrt its children's value (v_i).
  // This basically depends on how we compute this node's value and is therefore
  // purely virtual.
  virtual NodeValue du_dvi(Node* child) ABSTRACT;
  // The partial derivate of this node's value wrt all its children.
  // A default implementation is provided.
  virtual void du_dv(vector<NodeValue>* derivatives_wrt_children);

  const string& name() const { return name_; }
  bool constant_node() const { return constant_node_; }
  bool input_node() const { return input_node_; }
  bool output_node() const { return output_node_; }

 private:
  int NodeIndex(const Nodes& nodes, Node* node) const;

 protected:
  // Due to the lack of hash_map in the standard :)
  int ChildIndex(Node* child) const;
  int ParentIndex(Node* parent) const;

  const string name_;
  bool constant_node_;
  Nodes children_;
  Nodes parents_;
  bool input_node_;
  bool output_node_;
  bool initialized_;
  NodeValue node_value_;
};

}  // namespace flow_graphs

#endif  /* __NODE_H__ */
