//
//  EffectsController.cpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

#include "EffectsController.hpp"
#include <typeinfo>

using namespace Orange::Effects;

EffectsController::EffectsController()
{
    addSearchPath("effects/glsl");
}

void EffectsController::newGLSLEffect(std::string shaderName)
{
    shared_ptr<Orange::Effects::GLSLEffect> effect;
    
    effect = make_shared<Orange::Effects::GLSLEffect>();
    effect->load(shaderName);
    
    effects.add(effect);
}

void EffectsController::process(ofFbo &fbo)
{
    ofTexture &tex = fbo.getTexture();

    // only process free frame effects
    fbo.begin();
    effects.forEach([&tex, &fbo](shared_ptr<EffectBase> effect) {
        if (dynamic_pointer_cast<GLSLEffect>(effect)) {
            effect->process(fbo);
        }
    });
    fbo.end();
}


void EffectsController::forEachEffect(std::function<void (shared_ptr<Orange::Effects::EffectBase>)> lambda)
{
    effects.forEach(lambda);
}


void EffectsController::addSearchPath(string path)
{
    ofFilePath filePath;
    
    std::string searchPath = ofToDataPath(path);
    searchPaths.push_back(searchPath);
}

void EffectsController::scanEffects()
{
    foundFilters.empty();
    
    for(auto path:searchPaths) {
        ofDirectory directory;
        directory.open(path);
        std::vector<ofFile> files = directory.getFiles();
        std::vector<ofFile> jsonFiles = filterJsonFiles(files);
        
        for(auto jsonFile:jsonFiles) {
            foundFilters[jsonFile.getBaseName()] = jsonFile.getEnclosingDirectory();
        }
    }
}

std::vector<ofFile> EffectsController::filterJsonFiles(std::vector<ofFile> inputFiles)
{
    std::vector<ofFile> jsonFiles;
    
    for(auto file:inputFiles)
    {
        if (file.getExtension() == "json") {
            jsonFiles.push_back(file);
        }
    }
    
    return jsonFiles;
}

std::vector<string> EffectsController::getEffectsNames()
{
    std::vector<string> effectsNames;
    
    for(auto foundFilter:foundFilters) {
        effectsNames.push_back(foundFilter.first);
    }
    
    return effectsNames;
}
