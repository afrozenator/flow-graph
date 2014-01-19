#include "input_node.h"

#include <cstdlib>
#include <iostream>

namespace flow_graphs {

InputNode::InputNode(const string& name) : Node(name, kInput) {}

InputNode::~InputNode() {}

void InputNode::set_children(const Nodes& children) {
}

void InputNode::add_child(Node* child) {
}

void InputNode::ComputeValue() {
    std::cout << "ComputeValue called on " << name_ << ", aborting" << std::endl;
    std::abort();
}

}  // namespace flow_graphs
