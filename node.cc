//============================================================================
// Name        : node.h
// Author      : Afroz Mohiuddin
// Description : Node in a Flow Graph
//============================================================================

#include <limits>

#include "node.h"

namespace flow_graphs {

Node::Node(const string& name, bool constant_node, Nodes* children,
           Nodes* parents)
  : name_(name),
    constant_node_(constant_node),
    initialized_(false),
    node_value_(-std::numeric_limits<NodeValue>::max()) {
  if (children != NULL) SetChildren(*children);
  if (parents != NULL) SetParents(*parents);
}

Node::Node(const string& name, bool constant_node, Nodes* children,
           Nodes* parents, NodeValue u)
  : name_(name),
    constant_node_(constant_node),
    initialized_(true),
    node_value_(u) {
  if (children != NULL) children_.assign(children->begin(), children->end());
  if (parents != NULL) parents_.assign(parents->begin(), parents->end());
  input_node_ = children_.empty();
  output_node_ = parents_.empty();
}

Node::~Node() {}

NodeValue Node::node_value() {
  LOG_INFO("initialized at %s: %d", name_.c_str(), initialized_);
  if (!initialized_) ComputeValue();
  LOG_INFO("node_value called at %s returning %f", name_.c_str(), node_value_);
  return node_value_;
}

void Node::SetChildren(const Nodes& children) {
  children_.assign(children.begin(), children.end());
  input_node_ = children_.empty();
}

void Node::AddChild(Node* child) {
  CHECK_NOTNULL(child);
  children_.push_back(child);
}

void Node::SetParents(const Nodes& parents) {
  parents_.assign(parents.begin(), parents.end());
  output_node_ = parents_.empty();
}

void Node::AddParent(Node* parent) {
  CHECK_NOTNULL(parent);
  parents_.push_back(parent);
}

NodeValue Node::dL_du() {
  // We assume that the output node in the flow graph is the loss function
  // itself. If that is the case then this is 1.0
  if (output_node_) return 1.0;
  // If this is a constant node, then there is no derivative at all!
  if (constant_node_) return 0.0;
  // If this is not an output node, then this value is as follows:
  // \frac{\partial{L}}{\partial{u}} =
  //                \sum_{v_i \in parents(u)}
  //                       \frac{\partial{L}}{\partial{v_i}} .
  //                       \frac{\partial{v_i}}{\partial{u}}
  // \frac{\partial{L}}{\partial{u}} = \sum_{v_i \in parents(u)} \frac{\partial{L}}{\partial{v_i}} . \frac{\partial{v_i}}{\partial{u}}
  // Where $v_i$s are the parents of this node.
  NodeValue accumulate = 0.0;
  for (Node* parent : parents_) {
    accumulate += parent->dL_du() * parent->du_dvi(this);
  }
}

void Node::du_dv(vector<NodeValue>* derivatives_wrt_children) {
  CHECK_NOTNULL(derivatives_wrt_children);
  derivatives_wrt_children->clear();
  if (input_node_) return;
  for (Node* child : children_) {
    derivatives_wrt_children->push_back(du_dvi(child));
  }
}

int Node::NodeIndex(const Nodes& nodes, Node* node) const {
  CHECK_NOTNULL(node);
  for (int i = 0; i < nodes.size(); ++i) {
    if (node == nodes[i]) return i;
  }
  // not found.
  return -1;
}

int Node::ChildIndex(Node* child) const {
  return NodeIndex(children_, child);
}

int Node::ParentIndex(Node* parent) const {
  return NodeIndex(parents_, parent);
}

}  // namespace flow_graphs
