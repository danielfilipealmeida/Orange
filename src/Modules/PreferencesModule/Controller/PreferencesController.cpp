//
//  PreferencesController.cpp
//  orange
//
//  Created by Daniel Almeida on 02/02/2019.
//

#include "PreferencesController.hpp"

using namespace Orange::Preferences;


PreferencesController::PreferencesController(std::string _appName)
{
    appName = _appName;
}


std::string PreferencesController::getHash(std::string value)
{
    std::hash<std::string> hash_function;
    size_t str_hash = hash_function(value);
    
    return ofToString(str_hash);
}

/* Maybe move this to another place */
std::string PreferencesController::md5(std::string value) {
    std::string result;
    std::string shellCommand;
    
    try {
        shellCommand = "md5 -q -s " + value;
        result = ofSystem(shellCommand);
        result.erase(result.size() - 2);
    }
    catch(std::exception& e) {
        result = "";
    }
    return result;
}

std::string PreferencesController::getPreferencesPath()
{
    if (!preferencesFolder.empty()) return preferencesFolder;
    
    preferencesFolder = ofFilePath::getUserHomeDir();

#ifdef TARGET_OSX
    preferencesFolder = ofFilePath::join(preferencesFolder, "Library/Application Support");
    preferencesFolder = ofFilePath::join(preferencesFolder, appName);
#else if TARGET_LINUX
    
    std::string  tempString = appName;
    ofStringReplace(tempString, " ", "_");
    tempString = ofToLower(tempString);
    preferencesFolder = ofFilePath::join(preferencesFolder, "." + tempString);
#endif
    
    return preferencesFolder;
}

std::string PreferencesController::getThumbnailPath(std::string filename) {
    std:string result;
    
    std::string hashedFileName = getHash(filename) + ".jpg";
    
    result = getPreferencesPath();
    result = ofFilePath::join(result, "thumbnails");
    
    result = ofFilePath::join(result,  hashedFileName );
   
    return result;
}


void PreferencesController::saveThumbnail(ofImage input, std::string filename) {
    ofPixels pixels;
    
    //input.readToPixels(pixels);
    pixels = input.getPixels();
    
    std::string thumbnailFilePath = getThumbnailPath(filename);
    ofFilePath::createEnclosingDirectory(thumbnailFilePath);
    ofSaveImage(pixels, thumbnailFilePath);
}


ofPixels PreferencesController::loadThumbnail(std::string filename) {
    ofPixels pixels;
    
    std::string thumbnailFilePath = getThumbnailPath(filename);
    if (!ofFile::doesFileExist(thumbnailFilePath)) {
        throw new std::runtime_error("File "  + thumbnailFilePath + " doesn't exist.");
    }
    ofLoadImage(pixels, thumbnailFilePath);
    
    return pixels;
}
