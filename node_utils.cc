#include "node_utils.h"

namespace flow_graphs {

void NodeUtils::AddEdge(Node* parent, Node* child) {
  parent->add_child(child);
  child->add_parent(parent);
}

int32_t NodeUtils::ChildIndex(Node* parent, Node* child) {
  const Nodes& children = parent->children();
  for (size_t idx = 0; idx < children.size(); ++idx) {
    if (children[idx] == child) {
      return idx;
    }
  }
  return -1;
}

void NodeUtils::ComputeValues(Nodes* nodes) {
  for (Node* node : *nodes) {
    node->ComputeValue();
  }
}

void NodeUtils::ResetTree(Node* node) {
  node->Reset();
  for (Node *child : node->children()) {
    ResetTree(child);
  }
}

}  // namespace flow_graphs
