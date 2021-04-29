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

    class dfs
    
    {
    private:
        /* data */
    public:
        uint16_t DFS(Graph g,id start);
    };
    

    
   

#endif