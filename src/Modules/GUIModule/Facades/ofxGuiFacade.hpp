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
            
            /*!
             Sets the name of the current panel
             \param ofParameter<string> name
             */
            void setName(ofParameter<string> name);
            
            /*!
             Creates a float Slider in the GUI
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
             Creates an integer Slider in the GUI
             \param string title
             \param int value
             \param int minValue
             \param int maxValue
             */
            void createSlider(ofParameter<int> parameter,
                              std::string title,
                              int minValue,
                              int maxValue);
            
            /*!
             Creates a label displaying information
             */
            void createLabel(ofParameter<string> parameter);
            
            /*!
             Creates a preview of the passed fbo
             \param ofFbo *fbo
             */
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
