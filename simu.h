#ifndef SIMU_H_
#define SIMU_H_

#include "Figure.h"
#include "ball.h"
#include "cube.h"
#include <vector>

class Simu
{
	public:
	
		Simu(const Figure& F); // type = 1: Ball, type = 2:Cube
		~Simu();
		void operator+=(const Figure& F);
	public:
		std::vector<Figure *> vect;

};

#endif


















