// Explain this class

# ifndef __NODE_H__
# define __NODE_H__

#include <string>
#include <vector>

#include "macros.h"

namespace flow_graphs {

using std::string;
using std::vector;

class Node;

typedef double Value;
typedef vector<Node*> Nodes;
typedef vector<Value> Values;

enum NodeType {
 kConstant         = 0,
 kInput            = 1,
 kParameter        = 2,
 kComputational    = 3,
};

class Node {
 public:
  Node(const string& name, NodeType node_type);
  virtual ~Node() {}

  // Simple getters and virtual setters.
  string name() const { return name_; }
  virtual void set_name(const string& name);
  NodeType node_type() { return node_type_; }
  const Nodes& parents() const { return parents_; }
  virtual void set_parents(const Nodes& parents);
  virtual void add_parent(Node* parent);
  const Nodes& children() const { return children_; }
  virtual void set_children(const Nodes& children);
  virtual void add_child(Node* child);

  virtual void ComputeValue() ABSTRACT;
  Value value() const { return value_; }
  virtual void set_value(Value value);

  virtual void Reset();

 protected:
  string name_;
  NodeType node_type_;
  Nodes parents_;
  Nodes children_;

  Value value_;
};

}  // namespace flow_graphs

# endif // __NODE_H__
