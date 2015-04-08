#include "MyParticleManager.h"
#include "MyUtils.hpp"
#include <tyga/Actor.hpp>
#include <tyga/BasicWorldClock.hpp>
#include <tyga/Math.hpp>
#include <tyga/ActorWorld.hpp>
#include <tyga/GraphicsCentre.hpp>
#include <tyga/Log.hpp>
#include "MyParticleEmmitter.h"


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
	for (unsigned int i = 0; i < LIVE_PARTICLES; ++i) {
		vertex_array[i].position = particles[i].getPosition();
		vertex_array[i].size = particles[i].getSize();
		vertex_array[i].colour = particles[i].getColour();
		vertex_array[i].alpha = particles[i].getAlpha();
		vertex_array[i].rotation = 0.f; // NB: has no effect in basic renderer
	}
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
void MyParticleManager::initialiseParticles(int minParticles, int maxParticles, tyga::Vector3 origin) {
	int index = LIVE_PARTICLES;
	int particlesToCreate = (rand() % (maxParticles - minParticles)) + minParticles;
	for (int i = 0; i < particlesToCreate; i++) {
		tyga::Vector3 velocity = tyga::Vector3((rand() % 6) - 3, (rand() % 6) - 3, (rand() % 6) - 3);
		float lifeSpan = 3;
		particles[index] = ToyParticle(origin, velocity, tyga::Vector3(1, 1, 1), lifeSpan, lifeSpan, lifeSpan);
		LIVE_PARTICLES++;
		index++;
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

void MyParticleManager::runloopWillBegin() {

}
void MyParticleManager::runloopExecuteTask() {
	updateParticles();

	reapDeadParticles();
}

void MyParticleManager::runloopDidEnd() {


}