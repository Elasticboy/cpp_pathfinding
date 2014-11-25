#include "../data_structures/point.h"

#pragma once

class node : public point<unsigned int> {

public:

    node(unsigned int x, unsigned int y);
    node(unsigned int x, unsigned int y, bool eligible);

    /** @Returns the movement cost (g_) */
    int g() const;

    /** @Returns the sum of Heuristic and movement cost (h_ + g_) */
    int f() const;

    bool isEligible() const;

    void setHeuristic(int heuristic);

    void setParent(node* parent);

    void setG(int movementCost);

private:
    /** Heuristic */
    int h_;

    /** Movement cost */
    int g_;

    /** True if the node can be used to find the path. */
    bool eligible_;

    /** A node to reach this node */
    node* parent_;
};