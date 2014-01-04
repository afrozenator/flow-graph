//============================================================================
// Name        : flow_graph.h
// Author      : Afroz Mohiuddin
// Description : The class to represent the flow graph.
//============================================================================

#ifndef __FLOW_GRAPH_H__
#define __FLOW_GRAPH_H__

#include "node.h"

namespace flow_graphs {

class FlowGraph {
 public:
  FlowGraph(Nodes* input, Nodes* output);
  virtual ~FlowGraph() {}
  void ResetFlowGraph();
  void SetInputs(const vector<NodeValue>& input_values);
  void RunFlowGraph();
  void InspectOutputs(vector<NodeValue>* output_values);

 private:
  void ResetFlowGraphForNode(Node* node);

  bool reset_;
  Nodes input_;
  Nodes output_;
};

}  // namespace flow_graphs

#endif  /* __FLOW_GRAPH_H__ */
