//
//  DrawableInterface.h
//  orange
//
//  Created by Daniel Almeida on 02/12/2018.
//

#ifndef DrawableInterface_h
#define DrawableInterface_h


namespace Orange {
    namespace Base {
        
        class DrawableInterface {
        public:
            /*!
             Draws the drawable
             \param float x
             \param float y
             \param float w
             \param float h
             */
            virtual void draw(float x, float y, float w, float h) = 0;
            
            /*!
             renders current frame of the drawable
             */
            virtual void render() = 0;
            
        };
    }
}
#endif /* DrawableInterface_h */
