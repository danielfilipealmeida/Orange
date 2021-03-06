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
#include "ofxNavigator.hpp"
#include "ofxList.hpp"
#include <functional>

namespace Orange {
    namespace GUI {
        
        class ofxGuiFacade : public GUIFacadeInterface {
            ofxPanel previewsPanel, layerPanel, visualPanel, effectsPanel, effectsListPanel;
            ofxPanel *currentPanel;
            std::map<PanelNames, ofxPanel*> panelsMap;
        public:
            
            
            /*!
             Constructor. sets up all needed data interface using ofxGUI
             */
            ofxGuiFacade();
            
            /*!
             Sets up the Panel used for all previews (output and layers)
             */
            void setupPreviewPanel();
            
            /*!
             Sets up the panel that gather all layers controls
             */
            void setupLayersPanel();
            
            /*!
             Sets up the panel of the currently selected visual
             */
            void setupVisualPanel();
            
            /*!
             Sets up the panel with all the effects for the output and layers
             */
            void setupEffectsPanel();
            
            /*!
             */
            void setupEffectsListPanel();
            
            /*!
             Sets all panels
             */
            void setupPanels();
            
            /*!
             Sets the name of the current panel
             \param ofParameter<string> name
             */
            void setName(ofParameter<string> name);
            
            /*!
             Creates a parameter group
             \param ofParameterGroup parameters
             */
            void createParameterGroup(ofParameterGroup parameters);
            
            /*!
             Creates a button
             */
            void createButton(std::string caption, std::function<void()> callback);
            
            /*!
             Creates a float Slider in the GUI
             \param string title
             \param string name
             */
            void createSlider(ofParameter<float> parameter, string name = "");
            
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
            void createLabel(ofParameter<string> parameter);
            
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
             Creates a matrix of textures
             \param ofParameter<vector<ofTexture *>>
             \return ofxMatrix<ofTexture *>*
             */
            ofxMatrix<ofImage *>* createImageMatrix(ofParameter<vector<ofImage *>> value,
                                                    string name = "",
                                                    unsigned int rows = 2,
                                                    unsigned int columns = 2);
            
            ofxList<std::string>* createStringList(ofParameter<vector<std::string>> value, string name = "");

            /*!
             */
            void createNavigator(ofParameter<ofxPaginatedInterface *> element, string name = "");
            
            /*!
             Draws the ofxGui
             */
            void draw();
            
            void drawPanel(PanelNames panel);
            
            /*!
             Clears the current GUI
             */
            void clear();
    
            /*!
             Sets the currently active panel to receive actions
             \param PanelNames panelName
             */
            void setCurrentPanel(PanelNames panelName);
            
            /*!
             
             */
            void mouseEventOnPanel(PanelNames panelName, ofMouseEventArgs & args);
            
            /*!
             Returns a ofxGui object by it's name
             \param std::string the name
             \returns ofxBaseGui*
             */
            ofxBaseGui* getControl(std::string name);
        };
    }
}

#endif /* ofxGuiFacade_hpp */
