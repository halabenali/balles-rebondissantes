#ifndef Figure_H_
#define Figure_H_

#include "screen.h"


class Figure
{
	public:
		Figure():_x(0), _y(250), _vx(0), _vy(0){};
		Figure(float x, float y, float vx, float vy,float radius,int type):_x(x), _y(y), _vx(vx), _vy(vy),_radius(radius),_type(type){};
		virtual ~Figure(){};

		void setSpeed(float vx, float vy){ _vx = vx; _vy = vy;}
		float getSpeedX() const {return _vx;}
		float getSpeedY() const {return _vy;}
		void setPosition(float x, float y){ _x = x; _y = y;}
		float getPositionX() const {return _x;}
		float getPositionY() const {return _y;}
		int getType() const {return _type;}
		float getRadius() const { return _radius;}
		virtual void draw(Screen& s) const=0;
		virtual int verif_Bord(Screen& s) const=0;
  		virtual void update(float ax, float ay,float dt,Screen& s)=0 ;
  		virtual void update(bool move,Screen& s) =0;
	protected:
		float _x, _y;
		float _vx, _vy;
		int _type;
		float _radius;
};

#endif

