#include "node.h"

node::node(unsigned int x, unsigned int y)
        : point(x, y), h_(0), g_(0), eligible_(true), parent_(nullptr) { }

node::node(unsigned int x, unsigned int y, bool eligible)
        : point(x, y), h_(0), g_(0), eligible_(eligible), parent_(nullptr) { }

int node::g() const { return g_; }

int node::f() const { return h_ + g_; }

bool node::isEligible() const { return eligible_; }

void node::setHeuristic(int heuristic) { h_ = heuristic; }

void node::setParent(node* parent) { parent_ = parent; }

void node::setG(int movementCost) { g_ = movementCost; }
