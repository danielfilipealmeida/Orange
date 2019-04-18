//
//  LayersHelpers.hpp
//  orange
//
//  Created by Daniel Almeida on 11/04/2019.
//

#ifndef LayersHelpers_hpp
#define LayersHelpers_hpp

#include <stdio.h>


namespace Orange {
    namespace Visuals {
        class VisualsHelpers {
        public:
            static vector<ofImage *> getVisualsThumbs(Base::Repository<shared_ptr<Visuals::BaseVisual> > visuals) {
                vector<ofImage *> visualsThumbs;
                
                visuals.forEach([&visualsThumbs](shared_ptr<Visuals::BaseVisual>  visual) {
                    visualsThumbs.push_back(&visual->getThumbnail());
                });
                
                return visualsThumbs;
            }
        };
    };
};

#endif /* LayersHelpers_hpp */
