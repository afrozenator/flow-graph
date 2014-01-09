//============================================================================
// Name        : dining_problem_main.cc
// Author      : Afroz Mohiuddin
// Description : A simple flow graph.
//============================================================================

#include <iostream>

#include "flow_graph.h"
#include "linear_neuron.h"
#include "input_node.h"
#include "squared_error_loss_node.h"
#include "node.h"

using flow_graphs::FlowGraph;
using flow_graphs::Node;
using flow_graphs::NodeValue;
using flow_graphs::Nodes;
using flow_graphs::LinearNeuron;
using flow_graphs::InputNode;
using flow_graphs::SquaredErrorLossNode;

void InputValues(NodeValue fish, NodeValue chips, NodeValue ketchup,
                 InputNode* f, InputNode* c, InputNode* k) {
  f->set_node_value(fish);
  c->set_node_value(chips);
  k->set_node_value(ketchup);
}


int main(int argc, char **argv) {

  InputNode fish_portions("fish portions", NULL);
  InputNode chips_portions("chips portions", NULL);
  InputNode ketchup_portions("ketchup portions", NULL);

  Nodes input_nodes{&fish_portions, &chips_portions, &ketchup_portions};
  LinearNeuron linear_neuron("linear neuron", &input_nodes, NULL);
  linear_neuron.set_weights({50.0, 50.0, 50.0});
  Nodes hidden_nodes{&linear_neuron};
  fish_portions.AddParent(&linear_neuron);
  chips_portions.AddParent(&linear_neuron);
  ketchup_portions.AddParent(&linear_neuron);

  SquaredErrorLossNode loss("loss node", &hidden_nodes);
  linear_neuron.AddParent(&loss);

  Nodes output_nodes{&loss};

  FlowGraph flow_graph(&input_nodes, &output_nodes);
  NodeValue loss_on_training_example;
  NodeValue output_node;
  vector<NodeValue> partial_derv_loss_wrt_weights;
  {
    flow_graph.SetInputs({2, 5, 3});
    loss.set_expected_value(850.0);
    loss_on_training_example = loss.ComputeValue();
    output_node = linear_neuron.node_value();
    linear_neuron.dL_dw(&partial_derv_loss_wrt_weights);
  }

  LOG << "Loss: " << loss_on_training_example << std::endl;
  LOG << "Price of Meal: " << output_node << std::endl;
  for (size_t idx = 0; idx < partial_derv_loss_wrt_weights.size(); ++idx) {
    LOG << "Derv of loss wrt weight: " << idx << " is "
        << (partial_derv_loss_wrt_weights[idx] / 35.0) << std::endl;
  }

  return 0;
}
