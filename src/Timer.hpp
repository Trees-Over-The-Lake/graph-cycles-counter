#ifndef TIMER_HPP
#define TIMER_HPP

#include <time.h>

#include "Grafo.hpp"

// Benchmark a fuction
double benchmark(void (*input_function)(const Grafo& grafo)) {
  clock_t start = clock();
  input_function(grafo);
  clock_t end = clock() - start;  // Get the time needed to run the function

  // How much clocks per milisecond
  return end / CLOCKS_PER_SEC * 1000;
}

#endif