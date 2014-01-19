#include "constant_node.h"

#include <iostream>

namespace flow_graphs {

ConstantNode::ConstantNode(const string& name, Value value)
    : Node(name, kConstant) {
  value_ = value;
  value_initialized_ = true;
}

ConstantNode::~ConstantNode() {
}

void ConstantNode::set_children(const Nodes& children) {
  std::cout << "[" << name_ << "] is a ConstantNode, can't set children." << std::endl;
}

void ConstantNode::add_child(Node* child) {
  std::cout << "[" << name_ << "] is a ConstantNode, can't add child." << std::endl;
}

void ConstantNode::set_value(Value value) {
  std::cout << "[" << name_ << "] is a ConstantNode, can't set value." << std::endl;
}

void ConstantNode::ComputeValue() {
  std::cout << "[" << name_ << "] is a ConstantNode, value already computed." << std::endl;
}

void ConstantNode::Reset() {
  std::cout << "[" << name_ << "] is a ConstantNode, can't Reset." << std::endl;
}

}  // namespace flow_graphs
