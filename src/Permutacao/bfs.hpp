#ifndef bfs_hpp
#define bfs_hpp

/** COLORS
 *  WHITE: Not yet visited and neither is your neighborhood
 *  RED: Completely visited and its neighborhood
 *  YELLOW: It has already been visited, but its neighborhood is not
 */
enum COLORS {
    WHITE,
    YELLOW,
    RED,
};

#include "../Grafo.hpp"
#include <stdint.h>

    class BFS
    
    {
    private:
        /* data */
    public:
        uint16_t bfs_cycle_detection(Grafo g,int start);
    };
    

    
   

#endif