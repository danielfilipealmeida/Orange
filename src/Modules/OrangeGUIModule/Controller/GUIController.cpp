//
//  GUIController.cpp
//  orange
//
//  Created by Daniel Almeida on 14/10/2019.
//

#include "GUIController.hpp"
#include "GUIElements.hpp"
#include "GUIFactory.hpp"

using namespace Orange::GUI;

GUIController::GUIController()
{
    elements.push_back( GUIFactory::newElement({
           {"x", 10.0},
           {"y", 10.0},
           {"w", 100.0},
           {"h", 16.0}
       }));
    elements.push_back(GUIFactory::newButton({
        {"x", 10.0},
        {"y", 40.0},
        {"w", 100.0},
        {"h", 16.0},
        {"caption", "button"},
        {"pressed", false}
    }));
    
}

void GUIController::update()
{
    
}

void GUIController::draw()
{
    
    for(auto element:elements) {
        GUIFactory::draw(element);
    }
     
    /*
    forEachElement(elements, [&](shared_ptr<Element> element) {
        GUIFactory::drawElement(element);
    });
    */
}
