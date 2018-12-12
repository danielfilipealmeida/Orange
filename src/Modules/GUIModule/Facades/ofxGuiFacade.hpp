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
            
            string title;
        public:
            
            /*!
             Constructor. sets up all needed for the interface using ofxGUI
             */
            ofxGuiFacade();
            
            
            void setName(ofParameter<string> name);
            
            /*!
             Creates a Slider in the GUI
             \param string title
             \param float value
             \param float minValue
             \param float maxValue
             */
            void createSlider(ofParameter<float> parameter,
                              std::string title,
                              float minValue,
                              float maxValue);
            
            /*!
             Creates a label displaying information
             */
            void createLabel(ofParameter<string> parameter);
            
            void createPreview(ofFbo *fbo);
            
            /*!
             Draws the ofxGui
             */
            void draw();
            
            /*!
             Clears the current GUI
             */
            void clear();
            
        };
    }
}

#endif /* ofxGuiFacade_hpp */
