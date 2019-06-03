#include <iostream>
#include <fstream>
#include <ctime>
#include "ball.h"
#include "cube.h"
#include "simu.h"
void handleEvent (Screen& _screen, bool & move)
{
  sf::Event event;
  while (_screen.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
	  _screen.close();
	}
      if (event.type == sf::Event::KeyPressed)
	move = true;
       if (event.type == sf::Event::KeyReleased)
	move = false;
    }
      
}


std::vector<Figure*> Lire_fichier(std::string nom_fichier)
{	
	std::vector<Figure *> vect;
	std::ifstream Flux(nom_fichier);  //Ouverture d'un fichier en lecture
	std::string mot;
	float x,y,vx,vy,radius;
	if(Flux)
		{ 
		while(Flux>>mot)
			{ 
			  Flux>>x;
			  Flux>>y;
			  Flux>>vx;
		          Flux>>vy;
		          Flux>>radius;
			  if(mot=="CUBE"){vect.push_back(new  Cube(x,y,vx,vy,radius));}
			  else if (mot=="BALL"){vect.push_back(new  Ball(x,y,vx,vy,radius));}
			}


	
	        }
	else
		{
    		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
		}
	Flux.close();
	return(vect);
}


int main(int argc,  char * argv[])
{ bool move=true;
float _screen_size=400;
Screen _screen(400, 400);
srand ( time(NULL) );
std::vector<Figure*> vect;

Cube c(_screen_size/2,_screen_size/2,0,0,40); 
Ball B(_screen_size/2,_screen_size/2,0,0,10);

Simu S(B); //je rajoute une balle en premier
S+=c;    //je rajoute un cube en deuxième

vect=Lire_fichier(argv[1]);
for(std::vector<Figure*>::iterator it=vect.begin(); it!=vect.end(); ++it)
   		{
        	 (S.vect).push_back(*it);
    		}	

  while(_screen.isOpen()) 
     {
       _screen.render();
       handleEvent ( _screen,move);
	S.vect[1]->update(move,_screen);
	S.vect[1]->draw(_screen);
	//c.update(move,_screen);
	//c.draw(_screen);
	//B.update(move,_screen);
	//B.draw(_screen);
     }

  return 0;
}
