#include "simu.h"




Simu::Simu(const Figure& F)
{
	if (F.getType() == 1)
		vect.push_back(new Ball(F.getPositionX(), F.getPositionY(), F.getSpeedX(), F.getSpeedY(), F.getRadius()));
	else if (F.getType() == 2)
		vect.push_back(new  Cube(F.getPositionX(), F.getPositionY(), F.getSpeedX(), F.getSpeedY(), F.getRadius()));
}


Simu::~Simu()
{
	for(std::vector<Figure*>::iterator it=vect.begin(); it!=vect.end(); ++it)
   		{
        	delete *it;
    		}	
}

void Simu::operator+=(const Figure& F)
{
	if (F.getType() == 1)
		vect.push_back(new Ball(F.getPositionX(), F.getPositionY(), F.getSpeedX(), F.getSpeedY(), F.getRadius()));
	else if (F.getType() == 2)
		vect.push_back(new  Cube(F.getPositionX(), F.getPositionY(), F.getSpeedX(), F.getSpeedY(), F.getRadius()));
	

}
