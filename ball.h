#ifndef BALL_H_
#define BALL_H_

#include "Figure.h"

class Ball : public Figure
{
public:
//constructeur
 Ball():Figure(){};
 Ball(float x, float y,float vx, float vy, float radius) :Figure(x,y,vx,vy,radius,1){};
virtual ~Ball(){};
//geteur,seteur
 
  
  //int getType() const {return _type;}
//méthode
  virtual void draw(Screen& s) const;
  virtual int verif_Bord(Screen& s) const;
  virtual void update(float ax, float ay,float dt,Screen& s) ;
  virtual void update(bool move,Screen& s) ;

  

};

#endif
