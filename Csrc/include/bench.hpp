#ifndef BENCH_HPP
#define BENCH_HPP

#include "benchable.hpp"

double bench(Benchable* testObject, double testTime = 5.0, int maxTests = 5000);

#endif // BENCH_HPP
