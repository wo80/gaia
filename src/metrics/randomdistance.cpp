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

#include "randomdistance.h"
#include "../utils.h"
using namespace gaia2;

RandomDistance::RandomDistance(const PointLayout& layout, const ParameterMap& params)
	: DistanceFunction(layout, params), _mtrand(time(nullptr) ^ clock()) {
  validParams << "range";

  _range = params.value("range", 1.0).toDouble();
#ifndef CPP_11
  _mtrand.seed();
#endif
}

Real RandomDistance::operator()(const Point& p1, const Point& p2, int seg1, int seg2) const {
  Q_UNUSED(p1); Q_UNUSED(p2);
  Q_UNUSED(seg1); Q_UNUSED(seg2);
#ifdef CPP_11
  return _range * Real(_mtrand())/std::mt19937::max();
#else
  return _range * _mtrand();
#endif
}
