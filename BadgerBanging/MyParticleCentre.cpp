#include "MyParticleCentre.h"
#include "MyUtils.hpp"
#include <tyga/Actor.hpp>
#include <tyga/BasicWorldClock.hpp>
#include <tyga/Math.hpp>
#include <tyga/ActorWorld.hpp>
#include <tyga/GraphicsCentre.hpp>

void ToyParticle::actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) {
	auto world = tyga::ActorWorld::defaultWorld();
	auto graphics = tyga::GraphicsCentre::defaultCentre();

	particle_system_ = std::make_shared<MyParticleCentre>();
	graphic_sprite_ = graphics->newSpriteWithDelegate(particle_system_);

	particle_system_->particles.resize(particle_system_->MAX_PARTICLES);
	particle_system_->initialiseParticles(10);
}

void ToyParticle::actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) {

}

void ToyParticle::actorClockTick(std::shared_ptr<tyga::Actor> actor) {
	const float current_time = tyga::BasicWorldClock::CurrentTime();
	const float delta_time = tyga::BasicWorldClock::CurrentTickInterval();

	for (int i = 0; i < particle_system_->LIVE_PARTICLES; ++i) {
		float angle = current_time + i * 6.28f / 10;
		particle_system_->particles[i].position = tyga::Vector3(5 * cosf(angle), 2, 5 * sinf(angle));
		particle_system_->particles[i].lifeSpan -= 0.01;
	}
	// TODO: birth and/or kill any particles for this frame

	//Kill any particles for this frame
	particle_system_->reapDeadParticles();

	// TODO: loop and update position and velocity of living particles

}

std::string MyParticleCentre::graphicsSpriteTexture() const {
	return "tex1.png";
}

int MyParticleCentre::graphicsSpriteVertexCount() const {
	// NB: you may need to adjust this count if you keep dead particles
	return particles.size();
}

void MyParticleCentre::graphicsSpriteGenerate(tyga::GraphicsSpriteVertex vertex_array[]) const {
	// NB: you may need to adjust this if you want to control the sprite look
	for (unsigned int i = 0; i < particles.size(); ++i) {
		vertex_array[i].position = particles[i].position;
		vertex_array[i].size = 0.5f;
		vertex_array[i].colour = tyga::Vector3(1, 1, 1);
		vertex_array[i].alpha = 1.f;
		vertex_array[i].rotation = 0.f; // NB: has no effect in basic renderer
	}
}
void MyParticleCentre::reapDeadParticles() {
	int particleIndex = 0;
	while (particleIndex < LIVE_PARTICLES) {
		if (particles[particleIndex].lifeSpan <= 0.0) {
			particles[particleIndex] = particles[LIVE_PARTICLES - 1];
			LIVE_PARTICLES--;
		} else {
			particleIndex++;
		}
	}
}
void MyParticleCentre::initialiseParticles(int numberOfParticles) {
	int index = LIVE_PARTICLES;
	for (int i = 0; i < numberOfParticles; i++) {
		particles[index].lifeSpan = 1.0;
		LIVE_PARTICLES++;
		index++;
	}
}