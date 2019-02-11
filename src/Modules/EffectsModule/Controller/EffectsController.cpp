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
    
    // only process GLSL effects
    /*
    effects.forEach([&tex](shared_ptr<EffectBase> effect) {
        if (!dynamic_pointer_cast<GLSLEffect>(effect)) return;
        effect->process(tex);
    });
     */
}


void EffectsController::forEachEffect(std::function<void (shared_ptr<Orange::Effects::EffectBase>)> lambda)
{
    effects.forEach(lambda);
}
