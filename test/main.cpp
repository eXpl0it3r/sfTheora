////////////////////////////////
// sfTheoraTest 1.0.3         //
// Copyright © Kerli Low 2011 //
////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// License:                                                                 //
// sfTheoraTest                                                             //
// Copyright (c) 2012 Kerli Low                                             //
// kerlilow@gmail.com                                                       //
//                                                                          //
// This software is provided 'as-is', without any express or implied        //
// warranty. In no event will the authors be held liable for any damages    //
// arising from the use of this software.                                   //
//                                                                          //
// Permission is granted to anyone to use this software for any purpose,    //
// including commercial applications, and to alter it and redistribute it   //
// freely, subject to the following restrictions:                           //
//                                                                          //
//    1. The origin of this software must not be misrepresented; you must   //
//    not claim that you wrote the original software. If you use this       //
//    software in a product, an acknowledgment in the product documentation //
//    would be appreciated but is not required.                             //
//                                                                          //
//    2. Altered source versions must be plainly marked as such, and must   //
//    not be misrepresented as being the original software.                 //
//                                                                          //
//    3. This notice may not be removed or altered from any source          //
//    distribution.                                                         //
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <SFML/Graphics.hpp>

#include "sfTheora.h"



int main()
{
  sf::RenderWindow sfApp(sf::VideoMode(800, 600, 32), "SFML Window");

  sf::Clock clock;

  sfApp.setFramerateLimit(60);

  sftheora::Video testVid("bunny.ogg");
  if (testVid.hasError()) {
    std::cout<<testVid.getError()<<"\n";
    return 1;
  }

  while (sfApp.isOpen()) {
    sf::Event sfEvent;
    while (sfApp.pollEvent(sfEvent)) {
      if (sfEvent.type == sf::Event::Closed)
        sfApp.close();

      if ((sfEvent.type == sf::Event::KeyPressed)) {
        switch (sfEvent.key.code) {
		      case sf::Keyboard::Escape:
            {
              sfApp.close();
              break;
            }

          case sf::Keyboard::F12:
            {
              sf::Image screen = sfApp.capture();
              screen.saveToFile("screenshot.png");

              break;
            }

          case sf::Keyboard::Space:
            {
              testVid.togglePause();
              break;
            }

          case sf::Keyboard::Left:
            {
              float time = testVid.getTime().asSeconds();
              testVid.seek(sf::seconds(time - 4.0f));
              break;
            }

          case sf::Keyboard::Right:
            {
              float time = testVid.getTime().asSeconds();
              testVid.seek(sf::seconds(time + 4.0f));
              break;
            }
        }
      }
    }

    testVid.update(clock.restart());

    sfApp.clear();

    sfApp.draw(testVid);

    sfApp.display();
  }

  return EXIT_SUCCESS;
}
