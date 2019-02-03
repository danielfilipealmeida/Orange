//
//  Video.hpp
//  orange
//
//  Created by Daniel Almeida on 17/11/2018.
//

#ifndef Video_hpp
#define Video_hpp

#include <stdio.h>
#include "ofMain.h"
#include "BaseVisual.hpp"
#include "PlayableInterface.hpp"
#include "DrawableInterface.hpp"
#include "PreferencesController.hpp"


namespace Orange {
    namespace Visuals {
        
        
        class Video :
        public BaseVisual
        {
            ofVideoPlayer player;
            ofFbo thumbnail;
            Boolean hasThumbnail;
            shared_ptr<Orange::Preferences::PreferencesController> preferencesController;
            
            string ERROR_FILE_NOT_FOUND = "File '%1' not found.";
        public:
            

            Video();
            
            /*!
             Creates a video object and sets its attributes from a json variable
             \param ofJson json
             */
            Video(ofJson json);
            
            /*!
             Destructor. Also closes the video if it is opened
             */
            ~Video();
            
            /*!
             Draws the video
             \param float x
             \param float y
             \param float w
             \param float h
             */
            void draw(float x, float y, float w, float h);
            
            /*!
             Prepares the video
             */
            void render();
            
            /*!
             Opens a video file
             \param filePath the absolute path to the file
             */
            void open(string filePath);
            
            /*!
             Closes a video file if it is opened
             */
            void close();
            
            /*!
             Returns the absolute path to the file
             \return The absolute path to the file
             */
            string getPath();
            
            /*!
             Plays this video
             */
            void play();
            
            /*!
             Stops this video
             */
            void stop();
            
            /*!
             Search for and opens an image with the thumbnail on the app preferences folder
             */
            void loadThumbnail();
            
            /*!
             Generates the thumbnail from the middle frame of the video
             This only works when the video is fully loaded
             */
            void generateThumbnail();
            
            /*!
             Get this video data in json format
             */
            ofJson toJson();
            
            /*!
             Sets Video attributes from a json variable
             */
            void setFromJson(ofJson json);
            
            /*!
             Return the amount of frames in the loaded video
             \return int
             */
            int getNumberOfFrames();
            
            /*!
             Return a pointer to the player
             \return ofVideoPlayer*
             */
            ofVideoPlayer* getPlayer();
            
            /*!
             Returns if the video player has a loaded video
             \returns boolean
             */
            Boolean isLoaded();
            
            /*!
             Returns the current frame of the videoplayer
             \return int
             */
            int getCurrentFrame();
            
            /*!
             Sets the current playing frame in the videoplayer
             \param int frame
             */
            void setFrame(int frame);
            
            /*!
             Returns a thumbnail of the video
             \returns ofTexture
             */
            ofFbo& getThumbnail();

            /*!
             Gets a reference to the texture of the videoplayer
             \returns ofTexture&
             */
            ofTexture& getTexture();
            
            /*!
             
             */
            void setPreferencesController(shared_ptr<Orange::Preferences::PreferencesController> _preferencesController);
            
        };

        
    }
}

#endif /* Video_hpp */
