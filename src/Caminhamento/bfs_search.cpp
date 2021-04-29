#ifndef dfs_hpp
#define dfs_hpp

/** COLORS
 *  WHITE: Not yet visited and neither is your neighborhood
 *  RED: Completely visited and its neighborhood
 *  YELLOW: It has already been visited, but its neighborhood is not
 */
enum COLORS {
    WHITE,
    RED,
    YELLOW,
};

#include "../../Simple-Graph/graph.cpp"
#include <stdint.h>

    
static uint16_t bfs(Graph g,id start) {
    std::vector<COLORS> colour;

    //Mark all vertices as : "NOT VISITED"
    for(int i = 0; i < g.get_num_vertex(); i++)
        colour.push_back(WHITE);

    
    //Start the queue with the first vertice of the graph
    std::vector<id> queue;
    queue.push_back(start);

    //While the queue is not empty
    while(queue.size() > 0) {

        //Remove the first element of the queue 
        //and store it in a variable
        id curr_vert = *queue.begin();
        queue.erase(queue.begin());

        //If the element is not visited
        if(colour.at(curr_vert) == WHITE) {

            //Mark as visited
            colour.at(curr_vert) = YELLOW;

            std::cout << "curr_index = " << curr_vert << std::endl;

            //Start adj std::vector
            std::vector<id> curr_vertex_adj = g.get_vertex_adj(curr_vert); 

            //Loop through adj std::vector of the curr_vertex
            for(int i = 0 ; i < curr_vertex_adj.size() ; i++) 

                //if adj vertex hasn't been visited
                if(colour.at(curr_vertex_adj.at(i)) == WHITE) 
                    //mark to be visited in the next iterations of the loop

                    queue.push_back(curr_vertex_adj.at(i));
                

            //mark the curr_vertex as completed
            colour.at(curr_vert) = RED;
        }
    }

    return 0;
}

#endif