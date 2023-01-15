/* 
 * Copyright (C) 2006-2013  Music Technology Group - Universitat Pompeu Fabra
 *
 * This file is part of Gaia
 * 
 * Gaia is free software: you can redistribute it and/or modify it under 
 * the terms of the GNU Affero General Public License as published by the Free 
 * Software Foundation (FSF), either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more 
 * details.
 * 
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 */

#ifndef GAIA_RANDOMDISTANCE_H
#define GAIA_RANDOMDISTANCE_H

#include "distancefunction.h"
#ifdef CPP_11
#  include <random>
#  include <ctime>
#else
 // The implementation for non C++11 compilers uses the MersenneTwister.h file
 // downloaded from:
 // http://www-personal.engin.umich.edu/~wagnerr/MersenneTwister.html
#include "3rdparty/MersenneTwister.h"
#endif

namespace gaia2 {

/**
 * @ingroup metrics refmetrics
 *
 * This class computes a distance which returns a random number between
 * 0 and the specified range. It uses a uniform distribution.
 *
 * @param range the max value this distance can return (minimum being 0).
 */
class RandomDistance : public DistanceFunction {
 public:
  RandomDistance(const PointLayout&, const ParameterMap&);

  Real operator()(const Point& p1, const Point& p2, int seg1, int seg2) const;

 protected:
#ifdef CPP_11
	 mutable std::mt19937 _mtrand;
#else
	 mutable MTRand _mtrand;
#endif
  Real _range;
};

} // namespace gaia2

#endif // GAIA_RANDOMDISTANCE_H
