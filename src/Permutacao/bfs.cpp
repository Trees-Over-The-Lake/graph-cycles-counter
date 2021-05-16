#include "bfs.hpp"

uint16_t BFS::bfs_cycle_detection(Grafo g, int start)
{
    std::vector<COLORS> colour(g.num_vertex(),WHITE);
    std::vector<int> parent(g.num_vertex(),-1);

    uint16_t n_of_cycles = 0;

    //Start the queue with the first vertice of the graph
    std::vector<int> queue;
    queue.push_back(start);

    //While the queue is not empty
    while (queue.size() > 0)
    {

        //Remove the first element of the queue
        //and store it in a variable
        int curr_vert = *queue.begin();
        queue.erase(queue.begin());


        if(colour.at(curr_vert) == WHITE) { 

         //   std::cout << "curr_index = " << curr_vert << std::endl;

            colour.at(curr_vert) = YELLOW;

            //Start adj std::vector
            std::vector<int> curr_vertex_adj = g.get_vertex_adj(curr_vert);

            //Loop through adj std::vector of the curr_vertex
            for (int i = 0; i < curr_vertex_adj.size(); i++)
            {
                //std::cout << "\t vizinho atual : " << curr_vertex_adj.at(i) << std::endl;
                //std::cout << "\t cor do vizinho  " << colour.at(curr_vertex_adj.at(i)) << std::endl;
                //std::cout << "\n" << std::endl;
                //if adj vertex hasn't been visited
                if (colour.at(curr_vertex_adj.at(i)) == WHITE)
                {
                    //std::cout << "\t \t push_back " << std::endl;
                    //mark to be visited in the next iterations of the loop
                    parent.at(curr_vertex_adj.at(i)) = curr_vert;
                    queue.push_back(curr_vertex_adj.at(i));
                }
                else if (parent.at(curr_vert) != curr_vertex_adj.at(i) )
                {

                    //std::cout << "\t \t +1 ciclo " << std::endl;
                    //mark to be visited in the next iterations of the loop
                    n_of_cycles++;
                }
            }

            //mark the curr_vertex as completed
            colour.at(curr_vert) = RED;
        }
    }

    return n_of_cycles;
}
