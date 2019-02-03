//
//  PreferencesController.hpp
//  orange
//
//  Created by Daniel Almeida on 02/02/2019.
//

#ifndef PreferencesController_hpp
#define PreferencesController_hpp

#include <stdio.h>

#include "ofMain.h"

namespace Orange {
    namespace Preferences {
        class PreferencesController {
            std::string appName;
            std::string preferencesFolder;
        public:
            
            PreferencesController(std::string _appName);
            
            void saveThumbnail(ofImage input, std::string filename);
        
            ofPixels loadThumbnail(std::string filename);
            
        private:
            std::string getHash(std::string value);
            std::string md5(std::string value);
            std::string getPreferencesPath();
            std::string getThumbnailPath(std::string filename);
            
            
        };
    };
};


#endif /* PreferencesController_hpp */
