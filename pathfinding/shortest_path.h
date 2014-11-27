#include <vector>
#include <set>
#include "node.h"
#include "../game_data_structures/tile.h"
#include "../data_structures/grid.h"

#pragma once

class shortest_path {
public:
    static std::vector<node*> compute_shortest_path(
            const unsigned int& startX, const unsigned int& startY,
            const unsigned int& goalX, const unsigned int& goalY,
            const grid<tile*>& playground);

    static int compute_heuristic(const node& current, const node& goal);

    /** @returns the eligible neighbours of the current node. */
    static std::vector<node*> get_neighbours(node* focus, grid<node*>& nodeGrid, const std::set<node*>& closeList);

    /** @returns true if the set contains the given node. */
    static bool contains(const std::set<node*>& items, const node* item);

    static bool isEligible(const node* testedNode, const std::set<node*>& closeList);

};