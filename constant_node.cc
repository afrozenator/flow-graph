#include "constant_node.h"

#include <iostream>

namespace flow_graphs {

ConstantNode::ConstantNode(const string& name, Value value)
    : Node(name, kConstant) {
  value_ = value;
}

ConstantNode::~ConstantNode() {
}

void ConstantNode::set_children(const Nodes& children) {
}

void ConstantNode::add_child(Node* child) {
}

void ConstantNode::set_value(Value value) {
}

void ConstantNode::ComputeValue() {
}

void ConstantNode::Reset() {
}

}  // namespace flow_graphs
