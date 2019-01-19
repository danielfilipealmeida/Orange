//
//  EffectsController.cpp
//  orange
//
//  Created by Daniel Almeida on 13/01/2019.
//

#include "EffectsController.hpp"


using namespace Orange::Effects;

EffectsController::EffectsController(shared_ptr<FreeFrameHostAdapter> _adapter)
{
    adapter = _adapter;
}

void EffectsController::newFreeFameEffect(string name)
{
    effects.add(adapter->newFreeFrameEffectByName(name, width, height));
}

void EffectsController::process(ofFbo &fbo)
{
    ofTexture &tex = fbo.getTexture();
    
    fbo.begin();
    effects.forEach([&tex](shared_ptr<EffectBase> effect) {
        effect->process(tex);
    });
    fbo.end();
}

void EffectsController::forEachEffect(std::function<void (shared_ptr<Orange::Effects::EffectBase>)> lambda)
{
    effects.forEach(lambda);
}
