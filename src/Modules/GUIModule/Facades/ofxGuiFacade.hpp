//
//  ofxGuiFacade.hpp
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#ifndef ofxGuiFacade_hpp
#define ofxGuiFacade_hpp

#include <stdio.h>

#include "ofxGui.h"
#include "GUIFacadeInterface.hpp"

namespace Orange {
    namespace GUI {
        
        class ofxGuiFacade : public GUIFacadeInterface {
            ofxPanel gui;
        public:
            
            /*!
             Constructor. sets up all needed for the interface using ofxGUI
             */
            ofxGuiFacade();
            
            /*!
             Creates a Slider in the GUI
             \param string title
             \param float value
             \param float minValue
             \param float maxValue
             */
            void createSlider(std::string title, float value, float minValue, float maxValue);
            
            /*!
             Draws the ofxGui
             */
            void draw();
            
        };
    }
}

#endif /* ofxGuiFacade_hpp */
