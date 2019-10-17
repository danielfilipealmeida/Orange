//
//  GUIFactory.cpp
//  orange
//
//  Created by Daniel Almeida on 14/10/2019.
//

#include "GUIFactory.hpp"

using namespace Orange::GUI;

void GUIFactory::setElementRect(shared_ptr<Element> element, ofJson data)
{
    element->rect.setPosition(data["x"].get<float>(), data["y"].get<float>());
    element->rect.setSize(data["w"].get<float>(), data["h"].get<float>());
}

void GUIFactory::setElementDefaultBackgroundAndBorder(shared_ptr<Element> element)
{
    element->background = ofColor::darkGrey;
    element->border = ofColor::lightGrey;
    element->borderWidth = 2.0;
}

shared_ptr<Element> GUIFactory::newElement(ofJson data)
{
    shared_ptr<Element> element  = make_shared<Element>();
    
    element->type = TypeElement;
    
    GUIFactory::setElementRect(element, data);
    GUIFactory::setElementDefaultBackgroundAndBorder(element);
        
    return element;
}

void GUIFactory::drawElement(shared_ptr<Element> element) {
    
    if (element->type != TypeElement) return;
    
    drawElementBox(element);
}


shared_ptr<Element> GUIFactory::newButton(ofJson data)
{
    shared_ptr<Button> button = make_shared<Button>();
    
    button->type = TypeButton;
    
    GUIFactory::setElementRect(button, data);
    GUIFactory::setElementDefaultBackgroundAndBorder(button);
    
    return button;
}

void GUIFactory::drawButton(shared_ptr<Element> element)
{
    if (element->type != TypeButton) return;
 
    shared_ptr<Button> button = dynamic_cast<Button>(element.get());
    
    drawElementBox(element);
    
    ofSetColor(button->border);
    ofDrawBitmapString(button->caption, button->rect->x, button->rect->y);
}


void GUIFactory::draw(shared_ptr<Element> element)
{

    GUIFactory::drawElement(element);
    GUIFactory::drawButton(element);
}


void GUIFactory::drawElementBox(shared_ptr<Element> element)
{
    ofSetColor(element->background);
    ofFill();
    ofDrawRectangle(element->rect);
    ofNoFill();
    ofSetLineWidth(element->borderWidth);
    ofSetColor(element->border);
    ofDrawRectangle(element->rect);
}
