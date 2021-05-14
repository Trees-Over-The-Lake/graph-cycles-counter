#ifndef bfs_hpp
#define bfs_hpp

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

#include "../Grafo.hpp"
#include <stdint.h>

    class dfs
    
    {
    private:
        /* data */
    public:
        uint16_t DFS(Grafo g,int start);
    };
    

    
   

#endif