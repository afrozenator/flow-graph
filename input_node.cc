#include "input_node.h"

#include <cstdlib>
#include <iostream>

namespace flow_graphs {

InputNode::InputNode(const string& name) : Node(name, kInput) {}

InputNode::~InputNode() {}

void InputNode::set_children(const Nodes& children) {
  std::cout << "[" << name_ << "] is a InputNode, can't set children." << std::endl;
}

void InputNode::add_child(Node* child) {
  std::cout << "[" << name_ << "] is a InputNode, can't add child." << std::endl;
}

void InputNode::ComputeValue() {
  if (!value_initialized_) {
    std::cout << "ComputeValue called on " << name_ << " but wasn't initialized, aborting" << std::endl;
    std::abort();
  }
}

}  // namespace flow_graphs
