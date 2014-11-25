#include "shortest_path.h"

#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <mshtml.h>

const int MOVEMENT_COST = 10;

std::vector<node> shortest_path::compute_shortest_path(
        const point& startPt, const point& goalPt,
        const grid<tile*>& playground)
{
    node* startNode;
    node* goalNode;

    // Build and populate the possible nodes vector
    grid<node*> nodeGrid(playground.width(), playground.height());
    for (auto& tileItem : playground) {

        unsigned int posX = tileItem->x();
        unsigned int posY = tileItem->y();

        node* currentNode = new node(posX, posY, tileItem->isBuildable());

        // Identify start and goal nodes
        if (posX == startPt.x() && posY == startPt.y()) {
            startNode = currentNode;
        } else if (posX == goalPt.x() && posY == goalPt.y()) {
            goalNode = currentNode;
        }

        // If the node is eligible, compute the Manhattan heuristic
        if (currentNode->isEligible()) {
            int heuristic = compute_heuristic(*currentNode, *goalNode);
            currentNode->setHeuristic(heuristic);
        }
        nodeGrid.push_back(currentNode);
    }

    std::vector<node*> openList;
    std::vector<node*> closeList;

    // Add the start node to the open list
    openList.push_back(startNode);

    bool pathFound = false;
    while (!pathFound) {

        pathFound = true;
    }

    // TODO Start searching
    for (auto focus : openList) {
        closeList.push_back(focus);
        auto neighbours = get_neighbours(focus, nodeGrid, openList, closeList);

        // TODO check neighbours
            // TODO Add to close list
            // TODO Re-parent if necessary
    }

    return path;
}

int shortest_path::compute_heuristic(const node& current, const node& goal)
{
    const int diffX = std::abs(current.x() - goal.x());
    const int diffY = std::abs(current.y() - goal.y());
    return diffX + diffY;
}

std::vector<node*> shortest_path::get_neighbours(node* focus, const grid<node*>& nodeGrid, const std::vector<node*>& openList, const std::vector<node*>& closeList) const
{
    std::vector<node*> result;

    // Left
    node* left = nodeGrid.at(focus->x() - 1, focus->y());
    if (isEligible(left, openList, closeList)) {
        left->setParent(focus);
        left->setG(focus->g() + MOVEMENT_COST);
        result.push_back(left);
    }

    // Top
    node* top = nodeGrid.at(focus->x(), focus->y() + 1);
    if (isEligible(top, openList, closeList)) {
        top->setParent(focus);
        top->setG(focus->g() + MOVEMENT_COST);
        result.push_back(top);
    }

    // Right
    node* right = nodeGrid.at(focus->x() + 1, focus->y());
    if (isEligible(right, openList, closeList)) {
        right->setParent(focus);
        right->setG(focus->g() + MOVEMENT_COST);
        result.push_back(right);
    }

    // Bottom
    node* bottom = nodeGrid.at(focus->x(), focus->y() - 1);
    if (isEligible(bottom, openList, closeList)) {
        bottom->setParent(focus);
        bottom->setG(focus->g() + MOVEMENT_COST);
        result.push_back(bottom);
    }

    return result;
}

bool shortest_path::contains(const std::vector<node*>& items, const node* item) const
{
    return std::find(items.begin(), items.end(), item) != items.end();
}

bool shortest_path::isEligible(const node* testedNode, const std::vector<node*>& openList, const std::vector<node*>& closeList) const
{
    return testedNode->isEligible() && !contains(openList, testedNode) && !contains(closeList, testedNode);
}

//template<typename T>
//node* shortest_path::get_node(const std::vector<T*>& grid, int width,int x, int y) const
//{
//    auto tileId = (unsigned int) (y * width + x);
//    try {
//        return grid.at(tileId);
//    } catch (const std::out_of_range& oor) {
//        return nullptr;
//    }
//}
