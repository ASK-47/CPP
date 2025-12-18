//PIML
// NoiseReductionFilter.hpp
#include "NoiseReductionFilterImpl.hpp"
struct NoiseReductionFilter {
    Filter();

   private:
    NoiseReductionFilterImpl impl;
};
// NoiseReductionFilter.cpp
NoiseReductionFilter::Filter() { impl.FilterImpl(); }
