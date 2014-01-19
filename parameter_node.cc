#include "parameter_node.h"

#include <iostream>

namespace flow_graphs {

ParameterNode::ParameterNode(const string& name, Value value)
    : Node(name, kConstant) {
  value_ = value;
}

ParameterNode::~ParameterNode() {
}

void ParameterNode::set_children(const Nodes& children) {
}

void ParameterNode::add_child(Node* child) {
}

void ParameterNode::ComputeValue() {
}

void ParameterNode::Reset() {
}

}  // namespace flow_graphs
