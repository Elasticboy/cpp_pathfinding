#include <vector>
#include "node.h"
#include "../game_data_structures/tile.h"
#include "../data_structures/grid.h"

#pragma once

class shortest_path {
public:
    static std::vector<node> compute_shortest_path(
            const point& start, const point& goal,
            const grid<tile*>& playground);

    static int compute_heuristic(const node& current, const node& goal);

    static std::vector<node*> get_neighbours(node* focus, const grid<node*>& nodeGrid, const std::vector<node*>& openList, const std::vector<node*>& closeList) const;

    static bool contains(const std::vector<node*>& items, const node* item) const;

    static bool isEligible(const node* testedNode, const std::vector<node*>& openList, const std::vector<node*>& closeList) const;

};