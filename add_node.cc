#include "add_node.h"

#include <numeric>

namespace flow_graphs {

namespace {
Value AddValueFromNode(Value in, Node* child) {
  return in + child->value();
}
}

AddNode::AddNode(const string& name) : Node(name, kComputational) {}

void AddNode::ComputeValue() {
  value_ = std::accumulate(children_.begin(),
                           children_.end(),
                           0.0,
                           AddValueFromNode);
}

}  // namespace flow_graphs
