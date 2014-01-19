#include "multiply_node.h"

#include <numeric>

namespace flow_graphs {

namespace {
Value MultiplyValueFromNode(Value in, Node* child) {
  return in * child->value();
}
}

MultiplyNode::MultiplyNode(const string& name) : Node(name, kComputational) {}

MultiplyNode::~MultiplyNode() {}

void MultiplyNode::ComputeValue() {
  value_ = std::accumulate(children_.begin(),
                           children_.end(),
                           1.0,
                           MultiplyValueFromNode);
}

}  // namespace flow_graphs
