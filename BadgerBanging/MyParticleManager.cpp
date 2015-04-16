#include "MyParticleManager.h"
#include "MyUtils.hpp"
#include <tyga/Actor.hpp>
#include <tyga/BasicWorldClock.hpp>
#include <tyga/Math.hpp>
#include <tyga/ActorWorld.hpp>
#include <tyga/GraphicsCentre.hpp>
#include <tyga/Log.hpp>
#include "MyParticleEmmitter.h"
#include "MyParticleSystem.h"
#include <iostream>


std::shared_ptr<MyParticleManager> MyParticleManager::default_centre_;

std::shared_ptr<MyParticleManager> MyParticleManager::defaultCentre() {
	if (default_centre_ == nullptr) {
		default_centre_ = std::make_shared<MyParticleManager>();
		default_centre_->initialiseManager();

	}
	return default_centre_;
}

void MyParticleManager::initialiseManager() {
	auto graphics = tyga::GraphicsCentre::defaultCentre();
	graphic_sprite_ = graphics->newSpriteWithDelegate(default_centre_);

	particles.resize(MAX_PARTICLES);
}

std::string MyParticleManager::graphicsSpriteTexture() const {
	return "tex1.png";
}


int MyParticleManager::graphicsSpriteVertexCount() const {
	return LIVE_PARTICLES;
}

void MyParticleManager::graphicsSpriteGenerate(tyga::GraphicsSpriteVertex vertex_array[]) const {
	// NB: you may need to adjust this if you want to control the sprite look
	for (int i = 0; i < LIVE_PARTICLES; ++i) {
		vertex_array[i].position = particles[i].getPosition();
		vertex_array[i].size = particles[i].getSize();
		vertex_array[i].colour = particles[i].getColour();
		vertex_array[i].alpha = particles[i].getAlpha();
		vertex_array[i].rotation = 0.f; // NB: has no effect in basic renderer
	}
}
void MyParticleManager::runloopWillBegin() {

}
void MyParticleManager::runloopExecuteTask() {
	updateParticles();

	reapDeadParticles();

	std::cout << "Particles: " + std::to_string(LIVE_PARTICLES) << std::endl;
}

void MyParticleManager::runloopDidEnd() {


}

void MyParticleManager::reapDeadParticles() {
	int particleIndex = 0;
	while (particleIndex < LIVE_PARTICLES) {
		if (particles[particleIndex].getLifeSpan() <= 0.0) {
			particles[particleIndex] = particles[LIVE_PARTICLES - 1];
			LIVE_PARTICLES--;
		} else {
			particleIndex++;
		}
	}
}
void MyParticleManager::initialiseParticle(ToyParticle newParticle) {
	int index = LIVE_PARTICLES;
	if (index < MAX_PARTICLES) {
		particles[index] = newParticle;
		LIVE_PARTICLES++;
	}
}

void MyParticleManager::updateParticles() {
	const float current_time = tyga::BasicWorldClock::CurrentTime();
	const float delta_time = tyga::BasicWorldClock::CurrentTickInterval();

	for (int i = 0; i < LIVE_PARTICLES; i++) {
		particles[i].updateLifeCycle(delta_time);
	}
}

MyParticleEmmitter *MyParticleManager::newEmmitter() {
	MyParticleEmmitter *newEmmitter = new MyParticleEmmitter();

	return newEmmitter;
}

MyParticleSystem *MyParticleManager::getSystem(std::string systemName) {
	std::unordered_map<std::string, MyParticleSystem*>::const_iterator system = particleSystems_.find(systemName);
	if (system != particleSystems_.end()) {
		return system->second;
	} else {
		return nullptr;
	}
	
}
void MyParticleManager::addSystem(std::string systemName) {
	std::unordered_map<std::string, MyParticleSystem*>::const_iterator system = particleSystems_.find(systemName);
	if (system == particleSystems_.end()) {
		//System is undeclared, create it now
		particleSystems_[systemName] = new MyParticleSystem();
	} else {
		tyga::debugLog("System Re-Initialization Ignored: " + systemName);
	}
}

void MyParticleManager::setLifespan(std::string systemName, float minLifespan, float maxLifespan) {
	std::unordered_map<std::string, MyParticleSystem*>::const_iterator system = particleSystems_.find(systemName);
	if (system != particleSystems_.end()) {
		particleSystems_[systemName]->setLifespan(minLifespan, maxLifespan);
	} else {
		tyga::debugLog("Null System Access Ignored: 'setLifespan' : " + systemName);
	}
}

void MyParticleManager::setSize(std::string systemName, float startSize, float targetEndSize, float sizeRandomiser) {
	std::unordered_map<std::string, MyParticleSystem*>::const_iterator system = particleSystems_.find(systemName);
	if (system != particleSystems_.end()) {
		particleSystems_[systemName]->setSize(startSize, targetEndSize, sizeRandomiser);
	} else {
		tyga::debugLog("Null System Access Ignored: 'setSize' : " + systemName);
	}
}

void MyParticleManager::setForces(std::string systemName, float gravityModifier, tyga::Vector3 constantForce, float minAcceleration, float maxAcceleration, float accelerationFallOff) {
	std::unordered_map<std::string, MyParticleSystem*>::const_iterator system = particleSystems_.find(systemName);
	if (system != particleSystems_.end()) {
		particleSystems_[systemName]->setForces(gravityModifier, constantForce, minAcceleration, maxAcceleration, accelerationFallOff);
	} else {
		tyga::debugLog("Null System Access Ignored: 'setForces' : " + systemName);
	}
}

void MyParticleManager::setColours(std::string systemName, tyga::Vector3 baseColour, tyga::Vector3 colourVariation, float startAlpha, float endAlpha, std::string textureName) {
	std::unordered_map<std::string, MyParticleSystem*>::const_iterator system = particleSystems_.find(systemName);
	if (system != particleSystems_.end()) {
		particleSystems_[systemName]->setColours(baseColour, colourVariation, startAlpha, endAlpha, textureName);
	} else {
		tyga::debugLog("Null System Access Ignored: 'setColours' : " + systemName);
	}
}