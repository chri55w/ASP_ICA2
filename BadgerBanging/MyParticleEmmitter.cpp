#include "MyParticleEmmitter.h"
#include "MyParticleManager.h"

MyParticleEmmitter::MyParticleEmmitter() {

}

MyParticleEmmitter::~MyParticleEmmitter() {

}

void MyParticleEmmitter::actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) {



	/*
	auto world = tyga::ActorWorld::defaultWorld();
	auto graphics = tyga::GraphicsCentre::defaultCentre();

	particle_system_ = std::make_shared<MyParticleCentre>();
	graphic_sprite_ = graphics->newSpriteWithDelegate(particle_system_);

	particle_system_->particles.resize(particle_system_->MAX_PARTICLES);
	particle_system_->initialiseParticles(8, 12, tyga::Vector3(0, 8, 0));
	*/
}

void MyParticleEmmitter::actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) {

}

void MyParticleEmmitter::actorClockTick(std::shared_ptr<tyga::Actor> actor) {


	/*
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
	*/
}

void MyParticleEmmitter::randTestEmit(tyga::Vector3 originPosition) {
	auto particles = MyParticleManager::defaultCentre();

	particles->initialiseParticles(10, 50, originPosition);
}