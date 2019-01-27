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
#include "ofxPreview.hpp"
#include "ofxMatrix.hpp"

namespace Orange {
    namespace GUI {
        
        typedef enum {
            PreviewsPanel = 0,
            LayerPanel,
            VisualPanel
        } PanelNames;
        
        class GUIFacadeInterface {
            
        public:
            
            /*!
             Sets the name of the GUI
             \param ofParameter<string> name
             */
            virtual void setName(ofParameter<string> name) = 0;
        
            /*!
             
             */
            virtual void setupPanel() = 0;
            
            /*!
             Creates a float Slider in the GUI
             \param string title
             */
            virtual void createSlider(ofParameter<float> parameter,
                                      string name = "") = 0;
            
            /*!
             Creates a Float Slider in the GUI
             \param ofParameter<float> parameter
             \param string title
             \param float minValue
             \param float maxValue
             */
            virtual void createSlider(ofParameter<float> parameter,
                                      std::string title,
                                      float minValue,
                                      float maxValue) = 0;
            
            /*!
             Creates an Int Slider in the GUI
             \param ofParameter<int> parameter
             \param string title
             \param int minValue
             \param int maxValue
             */
            virtual void createSlider(ofParameter<int> parameter,
                                      std::string title,
                                      int minValue,
                                      int maxValue) = 0;
            
            
            /*!
             Creates a label to show information
             */
            virtual void createLabel(ofParameter<string> parameter) = 0;
            
            /*!
             Creates and returns a preview of the passed fbo
             \param ofFbo *fbo
             \return ofxPreview*
             */
            virtual ofxPreview* createPreview(ofFbo *fbo, string name = "") = 0;
        
            /*!
             Creates a matrix of textures
             \param ofParameter<vector<ofTexture *>>
             \return ofxMatrix<ofTexture *>*
             */
            virtual ofxMatrix<ofTexture *>* createImageMatrix(ofParameter<vector<ofTexture *>> value, string name = "") = 0;
            
            /*!
             
             */
            virtual void createNavigator(ofParameter<ofxPaginatedInterface *> element, string name = "") = 0;
            /*!
             Draws the ofxGui
             */
            virtual void draw() = 0;
            
            /*!
             Clears the gui
             */
            virtual void clear() = 0;
            
            /*!
             Sets the currently active panel to receive actions
             \param PanelNames panelName
             */
            virtual void setCurrentPanel(PanelNames panelName) = 0;
            
            

        };
    }
}
#endif /* GUIFacadeInterface_h */
