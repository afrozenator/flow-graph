#include "parameter_node.h"

#include <iostream>

namespace flow_graphs {

ParameterNode::ParameterNode(const string& name, Value value)
    : Node(name, kConstant) {
  value_ = value;
  value_initialized_ = true;
}

ParameterNode::~ParameterNode() {
}

void ParameterNode::set_children(const Nodes& children) {
  std::cout << "[" << name_ << "] is a ParameterNode, can't set children." << std::endl;
}

void ParameterNode::add_child(Node* child) {
  std::cout << "[" << name_ << "] is a ParameterNode, can't add child." << std::endl;
}

void ParameterNode::ComputeValue() {
  std::cout << "[" << name_ << "] is a ParameterNode, value already computed." << std::endl;
}

void ParameterNode::Reset() {
  std::cout << "[" << name_ << "] is a ParameterNode, can't Reset." << std::endl;
}

}  // namespace flow_graphs
