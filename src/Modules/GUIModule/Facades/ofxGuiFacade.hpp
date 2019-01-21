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
#include "ofxPreview.hpp"
#include "ofxMatrix.hpp"

#define PANEL_WIDTH 200
#define PANEL_HEIGHT 16

namespace Orange {
    namespace GUI {
        
        class ofxGuiFacade : public GUIFacadeInterface {
            ofxPanel previewsPanel, layerPanel, visualPanel;
            ofxPanel *currentPanel;
            
        public:
            
            
            /*!
             Constructor. sets up all needed data interface using ofxGUI
             */
            ofxGuiFacade();
            
            /*!
             Sets the currently selected panel
             */
            void setupPanel();
            
            /*!
             Sets the name of the current panel
             \param ofParameter<string> name
             */
            void setName(ofParameter<string> name);
            
            /*!
             Creates a float Slider in the GUI
             \param string title
             */
            void createSlider(ofParameter<float> parameter);
            
            /*!
             Creates a float Slider in the GUI
             \param string title
             \param float value
             \param float minValue
             \param float maxValue
             \param string name
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
             \param string name
             */
            void createSlider(ofParameter<int> parameter,
                              std::string title,
                              int minValue,
                              int maxValue);
            
            /*!
             Creates a label displaying information
             \param ofParameter<string> parameter
             \param string name
             */
            void createLabel(ofParameter<string> parameter, string name = "");
            
            /*!
             Creates a label using a string
             \param string text
             \param string name
             */
            void createLabel(string text);
            
            /*!
             Creates and returns a preview of the passed fbo
             \param ofFbo *fbo
             \param string name
             \return ofxPreview*
             */
            ofxPreview* createPreview(ofFbo *fbo, string name = "");
            
            /*!
             */
            void createImageMatrix(ofParameter<vector<ofTexture *>> value);

            /*!
             Draws the ofxGui
             */
            void draw();
            
            /*!
             Clears the current GUI
             */
            void clear();
    
            /*!
             Sets the currently active panel to receive actions
             \param PanelNames panelName
             */
            void setCurrentPanel(PanelNames panelName);
        };
    }
}

#endif /* ofxGuiFacade_hpp */
