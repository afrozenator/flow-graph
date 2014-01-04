//============================================================================
// Name        : dining_problem_main.cc
// Author      : Afroz Mohiuddin
// Description : A simple flow graph.
//============================================================================

#include <iostream>

#include "flow_graph.h"
#include "linear_neuron.h"
#include "input_node.h"
#include "node.h"

using flow_graphs::FlowGraph;
using flow_graphs::Node;
using flow_graphs::Nodes;
using flow_graphs::LinearNeuron;
using flow_graphs::InputNode;

int main(int argc, char **argv) {

  InputNode fish_portions("fish portions", NULL);
  InputNode chips_portions("chips portions", NULL);
  InputNode ketchup_portions("ketchup portions", NULL);

  Nodes input_nodes{&fish_portions, &chips_portions, &ketchup_portions};
  LinearNeuron linear_neuron("linear neuron", &input_nodes, NULL);
  linear_neuron.set_weights({50.0, 50.0, 50.0});
  Nodes output_nodes{&linear_neuron};
  fish_portions.AddParent(&linear_neuron);
  chips_portions.AddParent(&linear_neuron);
  ketchup_portions.AddParent(&linear_neuron);

  FlowGraph flow_graph(&input_nodes, &output_nodes);
  flow_graph.ResetFlowGraph();
  flow_graph.SetInputs({2, 5, 3});
  flow_graph.RunFlowGraph();
  LOG << "Price of Meal: " << linear_neuron.node_value() << std::endl;

  flow_graph.ResetFlowGraph();
  linear_neuron.set_weights({100.0, 100.0, 100.0});
  flow_graph.SetInputs({2, 5, 3});
  flow_graph.RunFlowGraph();
  LOG << "Price of Meal: " << linear_neuron.node_value() << std::endl;

  return 0;
}
