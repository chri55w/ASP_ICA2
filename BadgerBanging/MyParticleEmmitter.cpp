#include "MyParticleEmmitter.h"
#include "MyParticleManager.h"
#include "MyParticleSystem.h"
#include <time.h>

MyParticleEmmitter::MyParticleEmmitter() {

}

MyParticleEmmitter::~MyParticleEmmitter() {

}

void MyParticleEmmitter::actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) {

	srand(time(NULL));
}

void MyParticleEmmitter::actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) {

}

void MyParticleEmmitter::actorClockTick(std::shared_ptr<tyga::Actor> actor) {

}

/*
void MyParticleEmmitter::randomEmmission(tyga::Vector3 origin, tyga::Vector3 baseColour, float forceModifier, int maxSize, float sizeVariation, int minParticles, int maxParticles, int maxLifeSpan, float lifeVariation) {
	auto particles = MyParticleManager::defaultCentre();

	//Calculate random number of particles to generate between the min and max values provided
	int particlesToCreate = (rand() % (maxParticles - minParticles)) + minParticles;

	for (int i = 0; i < particlesToCreate; i++) {
		float velocityVarient = ((rand() % 100) * forceModifier) / 100;

		float size = (rand() % maxSize) * sizeVariation;

		float lifespan = (rand() % maxLifeSpan) * lifeVariation;

		ToyParticle newParticle = ToyParticle(origin, initialVelocity, baseColour, size, 1.0, 2.0);

		particles->initialiseParticle(newParticle);
	}
}*/

void MyParticleEmmitter::randomEmmission(std::string systemName, tyga::Vector3 origin, int minParticles, int maxParticles) {
	auto particleManager = MyParticleManager::defaultCentre();

	MyParticleSystem *particleSystem = particleManager->getSystem(systemName);

	if (particleSystem != nullptr) {

		int particlesToCreate = (rand() % (maxParticles - minParticles)) + minParticles;
		
		float startSize = particleSystem->getStartSize();
		float endSize = particleSystem->getTargetEndSize();

		float gravityMod = particleSystem->getGravityModifier();
		float accelerationFallOff = particleSystem->getAccelerationFallOff();
		tyga::Vector3 constForce = particleSystem->getConstantForce();

		constForce += gravityMod * tyga::Vector3(0.0, -9.81, 0.0);

		float startAlpha = particleSystem->getStartAlpha();
		float endAlpha = particleSystem->getEndAlpha();
				
		for (int i = 0; i < particlesToCreate; i++) {
			float lifespan = particleSystem->getRandLifespan();
			float sizeRand = particleSystem->getRandSize();
			tyga::Vector3 colour = particleSystem->getRandColour();
			float acceleration = particleSystem->getRandAcceleration();

			tyga::Vector3 direction = tyga::Vector3((rand() % 3) - 1, (rand() % 3) - 1 , (rand() % 3) - 1);


			ToyParticle newParticle = ToyParticle(origin, direction, colour, constForce, acceleration, accelerationFallOff, (startSize + sizeRand), (endSize + sizeRand), startAlpha, endAlpha, lifespan);

			particleManager->initialiseParticle(newParticle);
		}
	}
}