//
//  GUIFacadeInterface.h
//  orange
//
//  Created by Daniel Almeida on 04/12/2018.
//

#ifndef GUIFacadeInterface_h
#define GUIFacadeInterface_h

#include <string>

namespace Orange {
    namespace GUI {
        
        class GUIFacadeInterface {
        public:
            
            /*!
             Creates a Slider in the GUI
             \param string title
             \param float value
             \param float minValue
             \param float maxValue
             */
            virtual void createSlider(std::string title, float value, float minValue, float maxValue) = 0;
            
            /*!
             Draws the ofxGui
             */
            virtual void draw() = 0;
        };
    }
}
#endif /* GUIFacadeInterface_h */
