#include "MyParticleCentre.h"
#include "MyUtils.hpp"
#include <tyga/Actor.hpp>
#include <tyga/BasicWorldClock.hpp>
#include <tyga/Math.hpp>
#include <tyga/ActorWorld.hpp>
#include <tyga/GraphicsCentre.hpp>
#include <tyga/Log.hpp>

void ToyParticle::actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) {
	auto world = tyga::ActorWorld::defaultWorld();
	auto graphics = tyga::GraphicsCentre::defaultCentre();

	particle_system_ = std::make_shared<MyParticleCentre>();
	graphic_sprite_ = graphics->newSpriteWithDelegate(particle_system_);
}

void ToyParticle::actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) {

}

void ToyParticle::actorClockTick(std::shared_ptr<tyga::Actor> actor) {
	const float current_time = tyga::BasicWorldClock::CurrentTime();
	const float delta_time = tyga::BasicWorldClock::CurrentTickInterval();
	//Loop through all live particles
	for (int i = 0; i < particle_system_->LIVE_PARTICLES; ++i) {

		//Apply gravity to particles
		particle_system_->particles[i].velocity += tyga::Vector3(0, -9.81, 0) * delta_time;

		//Apply transformation to particle
		particle_system_->particles[i].position += particle_system_->particles[i].velocity * delta_time;

		//Decrease particle lifespan
		particle_system_->particles[i].lifeSpan -= 0.01;
		particle_system_->particles[i].alpha -= 0.01;
		particle_system_->particles[i].size -= 0.01;

	}
	//Kill any particles for this frame
	particle_system_->reapDeadParticles();

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
		vertex_array[i].size = particles[i].size;
		vertex_array[i].colour = tyga::Vector3(1, 1, 1);
		vertex_array[i].alpha = particles[i].alpha;
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
void MyParticleCentre::initialiseParticles(int minParticles, int maxParticles, tyga::Vector3 origin) {
	int index = LIVE_PARTICLES;
	int particlesToCreate = (rand() % (maxParticles - minParticles)) + minParticles;
	for (int i = 0; i < particlesToCreate; i++) {
		particles[index].lifeSpan = (rand() % 100) / 100.0f;
		particles[index].size = particles[index].lifeSpan;
		particles[index].alpha = particles[index].lifeSpan;
		particles[index].position = origin;
		particles[index].velocity = tyga::Vector3((rand() % 6)-3, (rand() % 6) - 3, (rand() % 6)-3);
		LIVE_PARTICLES++;
		index++;
	}
}