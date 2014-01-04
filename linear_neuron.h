//============================================================================
// Name        : linear_neuron.h
// Author      : Afroz Mohiuddin
// Description : A linear neuron is basically a weighted addition node.
//============================================================================

#ifndef __LINEAR_NEURON_H__
#define __LINEAR_NEURON_H__

#include "add_node.h"

namespace flow_graphs {

class LinearNeuron : public AddNode {
 public:
  LinearNeuron(const string& name, Nodes* children, Nodes* parents)
    : AddNode(name, children, parents) {}
  virtual ~LinearNeuron() {}
};

}  // namespace flow_graphs

#endif  /* __LINEAR_NEURON_H__ */
