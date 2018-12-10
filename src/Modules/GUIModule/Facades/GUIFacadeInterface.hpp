//
//  GUIFacadeInterface.h
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#ifndef GUIFacadeInterface_h
#define GUIFacadeInterface_h

#include <string>
#include "ofMain.h"

namespace Orange {
    namespace GUI {
        
        class GUIFacadeInterface {
            
        public:
            
            /*!
             Sets the name of the GUI
             \param ofParameter<string> name
             */
            virtual void setName(ofParameter<string> name) = 0;
        
            /*!
             Creates a Slider in the GUI
             \param string title
             \param float value
             \param float minValue
             \param float maxValue
             */
            virtual void createSlider(ofParameter<float> parameter,
                                      std::string title,
                                      float minValue,
                                      float maxValue) = 0;
            
            /*!
             Creates a label to show information
             */
            virtual void createLabel(ofParameter<string> parameter) = 0;
            
            /*!
             Draws the ofxGui
             */
            virtual void draw() = 0;
            
            /*!
             Clears the gui
             */
            virtual void clear() = 0;
            
        };
    }
}
#endif /* GUIFacadeInterface_h */
