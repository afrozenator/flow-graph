// Explain this class

# ifndef __NODE_UTILS_H__
# define __NODE_UTILS_H__

#include <cstdint>

#include "node.h"

namespace flow_graphs {

class NodeUtils {
 public:
  static void AddEdge(Node* child, Node* parent);
  static int32_t ChildIndex(Node* parent, Node* child);
  // Call ComputeValue in the order specified.
  static void ComputeValues(Nodes* nodes);
  // Call Reset on this node and all its children.
  static void ResetTree(Node* node);
};

}  // namespace flow_graphs

# endif // __NODE_UTILS_H__
