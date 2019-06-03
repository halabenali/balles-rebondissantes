#ifndef cube_H_
#define cube_H_

#include "Figure.h"

class Cube : public Figure
{
public:
//constructeur
 Cube():Figure(){};
  Cube(float x, float y,float vx, float vy, float radius) :Figure(x,y,vx,vy,radius,2){};
virtual ~Cube(){};


//méthode
  virtual void draw(Screen& s) const;
  virtual int verif_Bord(Screen& s) const;
  virtual void update(float ax, float ay,float dt,Screen& s) ;
  virtual void update(bool move,Screen& s) ;
 protected:


};

#endif
