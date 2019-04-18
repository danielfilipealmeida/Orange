//
//  Video.cpp
//  orange
//
//  Created by Daniel Almeida on 17/11/2018.
//

#include "Video.hpp"
#include <thread>
#include <future>
#include <functional>
#include "AppHelpers.hpp"


using namespace Orange::Visuals;

Video::Video(){
    ofLog(OF_LOG_VERBOSE, "Creating Video");
    hasThumbnail = false;
}

Video::Video(ofJson json)
{
    ofLog(OF_LOG_VERBOSE, "Creating Video");
    setFromJson(json);
}

Video::~Video()
{
    close();
    ofLog(OF_LOG_VERBOSE, "Destroying video");
}

void Video::draw(float x, float y, float w, float h)
{
    if (!player.isLoaded()) return;
    if (!player.isPlaying()) return;
    if (!hasThumbnail) return;
    
    player.draw(x, y, w, h);
}

void Video::render()
{
    player.update();
    
    if (!hasThumbnail) {
        generateThumbnail();
    }
}

void Video::open(string filePath)
{
    if (!ofFile::doesFileExist(filePath)) {
        string message = ERROR_FILE_NOT_FOUND;
        ofStringReplace(message, "%1", filePath);
        throw new std::runtime_error(message);
    }
    
    close();
    
    hash = Orange::Base::AppHelpers::hashString(filePath);
    
    player.load(filePath);
    ofLog(OF_LOG_VERBOSE, "Loaded video " + getPath());
    
    loadThumbnail();
}


void Video::loadThumbnail() {
    ofPixels pixels;
    
    if (!preferencesController) return;
    
    try {
        pixels = preferencesController->loadThumbnail(player.getMoviePath());
    }
    catch (std::runtime_error *exc) {
        ofLogNotice("VisualsModule::Video.cpp", "%s", exc->what());
        return;
    }
    
    thumbnail.setFromPixels(pixels);
}

void Video::generateThumbnail() {
    if (!player.isInitialized()) return;
    
    player.play();
    player.setPosition(0.5);
    player.update();
    
    ofPixels pixels = player.getPixels();
    pixels.resize(THUMB_WIDTH, THUMB_HEIGHT);
    ofImage image;
    thumbnail.setFromPixels(pixels);
    
    player.stop();
    player.setPosition(0);
    hasThumbnail = true;
    preferencesController->saveThumbnail(thumbnail, player.getMoviePath());
}

string Video::getPath() {
    return player.getMoviePath();
}

void Video::close()
{
    if (!player.isLoaded()) {
        return;
    }
    stop();
    ofLog(OF_LOG_VERBOSE, "Closing video " + getPath());
    player.close();
}

void Video::play()
{
    player.play();
}

void Video::stop()
{
    player.stop();
}

ofJson Video::toJson()
{
    return {
        {"filePath", player.getMoviePath()}
    };
}

void Video::setFromJson(ofJson json)
{
    string filePath = json["filePath"];

    open(filePath);
}



int Video::getNumberOfFrames()
{
    if (!player.isLoaded()) {
        return 0;
    }
    
    return player.getTotalNumFrames();
}

ofVideoPlayer* Video::getPlayer()
{
    return &player;
}

Boolean Video::isLoaded() {
    
    return player.isLoaded();
}


int Video::getCurrentFrame()
{
    if (!isLoaded()) {
        return 0;
    }
    return player.getCurrentFrame();
}

void Video::setFrame(int frame)
{
    if (!isLoaded()) {
        return;
    }
    
    player.setFrame(frame);
}

ofImage& Video::getThumbnail()
{
    return thumbnail;
}


ofTexture& Video::getTexture()
{
    return player.getTexture();
}

void Video::setPreferencesController(shared_ptr<Orange::Preferences::PreferencesController> _preferencesController)
{
    preferencesController = _preferencesController;
}
