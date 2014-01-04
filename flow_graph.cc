//============================================================================
// Name        : flow_graph.cc
// Author      : Afroz Mohiuddin
// Description : The class to represent the flow graph.
//============================================================================

#include "flow_graph.h"

namespace flow_graphs {

FlowGraph::FlowGraph(Nodes* input, Nodes* output)
  : reset_(false) {
  CHECK_NOTNULL(input);
  CHECK_NOTNULL(output);
  input_.assign(input->begin(), input->end());
  output_.assign(output->begin(), output->end());
}

void FlowGraph::ResetFlowGraph() {
  for (Node* output_node : output_) {
    ResetFlowGraphForNode(output_node);
  }
  reset_ = true;
}

void FlowGraph::ResetFlowGraphForNode(Node* node) {
  node->set_initialized_false();
  for (Node* child : node->Children()) {
    ResetFlowGraphForNode(child);
  }
}

void FlowGraph::SetInputs(const vector<NodeValue>& input_values) {
  CHECK(input_values.size() == input_.size());
  for (size_t i = 0; i < input_values.size(); ++i) {
    input_[i]->set_node_value(input_values[i]);
  }
}

void FlowGraph::RunFlowGraph() {
  for (Node* output_node : output_) {
    output_node->ComputeValue();
  }
}

void FlowGraph::InspectOutputs(vector<NodeValue>* output_values) {
  CHECK_NOTNULL(output_values);
  output_values->clear();
  for (Node* output_node : output_) {
    output_values->push_back(output_node->node_value());
  }
}

}  // namespace flow_graphs
