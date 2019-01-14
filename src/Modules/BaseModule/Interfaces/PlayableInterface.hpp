//
//  PlayableInterface.h
//  orange
//
//  Created by Daniel Almeida on 02/12/2018.
//

#ifndef PlayableInterface_h
#define PlayableInterface_h

namespace Orange {
    namespace Base {
        class PlayableInterface {
        public:
            
            /*!
             Starts playing a visual
             */
            virtual void play() = 0;
            
            /*!
             Stops playing a visual
             */
            virtual void stop() = 0;
        };
    }
}


#endif /* PlayableInterface_h */
