#include "shortest_path.h"

#include <algorithm>
#include <iostream>

const int STEP_COST = 10;

std::vector<node*> shortest_path::compute_shortest_path(
        const unsigned int& startX, const unsigned int& startY,
        const unsigned int& goalX, const unsigned int& goalY,
        const grid<tile*>& playground)
{

    node* startNode = nullptr;
    node* goalNode = nullptr;

    // Build and populate the possible nodes vector
    grid<node*> nodeGrid(playground.width(), playground.height());
    for (auto& tileItem : playground) {

        unsigned int posX = tileItem->x();
        unsigned int posY = tileItem->y();

        node* currentNode = new node(posX, posY, tileItem->isBuildable());

        // Identify start and goal nodes
        if (posX == startX && posY == startY) {
            startNode = currentNode;
        } else if (posX == goalX && posY == goalY) {
            goalNode = currentNode;
        }

        nodeGrid.at(posX, posY) = currentNode;
    }

    if (!startNode) {
        throw std::logic_error("Start node is out of the grid bounds");

    } else if (!startNode->isEligible()) {
        throw std::logic_error("Start node is not iligible");

    } else if (!goalNode) {
        throw std::logic_error("Goal node is out of the grid bounds");

    } else if (!goalNode->isEligible()) {
        throw std::logic_error("Goal node is not iligible");
    }

    std::set<node*> openList;
    std::set<node*> closeList;

    // Add the start node to the open list
    openList.insert(startNode);

    bool found = false;
    node* currentNode;
    auto it = std::begin(openList);
    while (it != std::end(openList)) {
        currentNode = *it;
        std::cout << "Testing node " << currentNode->x() << "x" << currentNode->y() << std::endl;

        openList.erase(it);
        closeList.insert(currentNode);

        // If the node is eligible, compute the Manhattan heuristic
        if (currentNode->isEligible()) {
            int heuristic = compute_heuristic(*currentNode, *goalNode);
            currentNode->setHeuristic(heuristic);
        }

        // Check neighbours
        auto neighbours = get_neighbours(currentNode, nodeGrid, closeList);

        for (auto neighbour : neighbours) {

            std::cout << "Testing neighbour " << neighbour->x() << "x" << neighbour->y() << std::endl;

            if (neighbour == goalNode) {
                neighbour->setParent(currentNode);
                neighbour->setG(currentNode->g() + STEP_COST);
                found = true;

                std::cout << "Goal found!" << std::endl;
                break;
            }

            // If the neighbour node is on the openList,
            // check if the current node is a better parent
            if (contains(openList, neighbour)) {
                // Re-check g value
                int newGValue = currentNode->g() + STEP_COST;
                if (newGValue < neighbour->g()) {
                    // If better, re-parent
                    neighbour->setParent(currentNode);
                    neighbour->setG(newGValue);
                }
            } else {
                openList.insert(neighbour);
                neighbour->setParent(currentNode);
                neighbour->setG(currentNode->g() + STEP_COST);
            }
        }

        if (found) {
            break;
        }
        it = std::begin(openList);
    }

    std::vector<node*> path;
    if (found) {
        node* currentNode = goalNode;
        while (currentNode) {
            path.push_back(currentNode);
            std::cout << "node " << currentNode->x() << "x" << currentNode->y() << std::endl;
            currentNode = currentNode->parent();
        }
    } else {
        std::cout << "No path found" << std::endl;
    }

    return path;
}

int shortest_path::compute_heuristic(const node& current, const node& goal)
{
    const int diffX = std::abs(current.x() - goal.x());
    const int diffY = std::abs(current.y() - goal.y());
    return diffX + diffY;
}

std::vector<node*> shortest_path::get_neighbours(node* focus, grid<node*>& nodeGrid, const std::set<node*>& closeList)
{
    std::vector<node*> neighbours;

    // Left
    try {
        node* left = nodeGrid.at(focus->x() - 1, focus->y());
        if (isEligible(left, closeList)) {
            neighbours.push_back(left);
        }
    } catch (const std::out_of_range&) { }

    // Top
    try {
        node* top = nodeGrid.at(focus->x(), focus->y() + 1);
        if (isEligible(top, closeList)) {
            neighbours.push_back(top);
        }
    } catch (const std::out_of_range&) { }

    // Right
    try {
        node* right = nodeGrid.at(focus->x() + 1, focus->y());
        if (isEligible(right, closeList)) {
            neighbours.push_back(right);
        }
    } catch (const std::out_of_range&) { }

    // Bottom
    try {
        node* bottom = nodeGrid.at(focus->x(), focus->y() - 1);
        if (isEligible(bottom, closeList)) {
            neighbours.push_back(bottom);
        }
    } catch (const std::out_of_range&) { }

    return neighbours;
}

bool shortest_path::contains(const std::set<node*>& items, const node* item)
{
    return std::find(items.begin(), items.end(), item) != items.end();
}

bool shortest_path::isEligible(const node* testedNode, const std::set<node*>& closeList)
{
    return testedNode->isEligible() && !contains(closeList, testedNode);
}
