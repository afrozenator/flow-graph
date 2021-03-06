#include "node.h"

#include <limits>

namespace flow_graphs {

Node::Node(const string& name, NodeType node_type)
    : name_(name),
      node_type_(node_type),
      value_(-std::numeric_limits<Value>::max()) {
}

void Node::set_name(const string& name) {
  name_ = name;
}

void Node::set_parents(const Nodes& parents) {
  parents_.assign(parents.begin(), parents.end());
}

void Node::set_children(const Nodes& children) {
  children_.assign(children.begin(), children.end());
}

void Node::add_parent(Node* parent) {
  if (parent != NULL) {
    parents_.push_back(parent);
  }
}

void Node::add_child(Node* child) {
  if (child != NULL) {
    children_.push_back(child);
  }
}

void Node::set_value(Value value) {
  value_ = value;
}

void Node::Reset() {
  value_ = -std::numeric_limits<Value>::max();
}

}  // namespace flow_graphs
