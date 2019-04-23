//
//  BaseVisual.hpp
//  orange
//
//  Created by Daniel Almeida on 02/12/2018.
//

#ifndef BaseVisual_hpp
#define BaseVisual_hpp

#include <stdio.h>
#include "EntityInterface.hpp"
#include "DrawableInterface.hpp"
#include "PlayableInterface.hpp"
#include "ofMain.h"

#define THUMB_WIDTH 160
#define THUMB_HEIGHT 120

namespace Orange {
    namespace Visuals {
        
        
        /*!
         Implements the interface for all Visuals
         */
        class BaseVisual :
        public Orange::Base::EntityInterface,
        public Orange::Base::DrawableInterface,
        public Orange::Base::PlayableInterface,
        public ofBaseUpdates
        {
            
        public:
            
            std::string hash;
            
            BaseVisual();
            
            /*!
             Draws the Visual in a given rect
             \param float x
             \param float y
             \param float w
             \param float h
             */
            void draw(float x, float y, float w, float h);
            
            /*!
             Renders the visual to be drawn later
             */
            void render();
            
            ofJson toJson();
            
            void setFromJson(ofJson json);
            
            /*!
             Returns a thumbnail of the video
             \returns ofImage
             */
            virtual ofImage& getThumbnail() = 0;
            
            /*!
             Returns the texture of the video
             \returns ofFbo*
             */
            virtual ofTexture& getTexture() = 0;
            
            virtual void generateThumbnail() = 0;
        };
    }
}


#endif /* BaseVisual_hpp */
