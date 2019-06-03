#include "ball.h"
void Ball::draw(Screen& s) const
{
  s.disc(_x,_y,_radius);
}

int Ball::verif_Bord(Screen& s) const //0:pas bord,1:vertical,2:horizontal
{ float w,h;
w=float(s._w);
h=float(s._h);
  int veri=0;
  if(_x + _radius>=w || _x - _radius<=0)
	{veri=1;}
  if(_y>=h || _y - _radius<=0)
	{veri=2;}
  return(veri);


}


void Ball::update(float ax , float ay ,float dt,Screen& s) 
{  
 int veri=this->verif_Bord(s); 
 
switch (veri)
	{
	case 1:
		_vx= -_vx * (-0.85);
		_vy= -_vy * 0.95;
		break;
	case 2:
		 _vx= -_vx * 0.95;
		 _vy= -_vy * (-0.85);
		 break;
	default:
		_vx+= ax * dt;
	  	_vy+= ay * dt;
		break;
	}

  _x += _vx *dt;
  _y += _vy *dt;

}
 void Ball::update(bool move,Screen& s) 
{
  if (move)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	update(-0.1,0,0.01,s);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	update(0.1,0,0.01,s);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	update(0,-0.1,0.01,s);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	update(0,0.1,0.01,s);
    }
  else
    update(0,0,0.01,s);


}



