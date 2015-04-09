#include "MyParticleEmmitter.h"
#include "MyParticleManager.h"
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


void MyParticleEmmitter::randomEmmission(tyga::Vector3 origin, tyga::Vector3 baseColour, float forceModifier, int maxSize, float sizeVariation, int minParticles, int maxParticles, int maxLifeSpan, float lifeVariation) {
	auto particles = MyParticleManager::defaultCentre();

	//Calculate random number of particles to generate between the min and max values provided
	int particlesToCreate = (rand() % (maxParticles - minParticles)) + minParticles;

	for (int i = 0; i < particlesToCreate; i++) {
		/*
		int redColourMod = ((rand() % 10) - 5) / 255;
		int greenColourMod = ((rand() % 10) - 5) / 255;
		int blueColourMod = ((rand() % 10) - 5) / 255;
		tyga::Vector3 particleColour = tyga::Vector3(baseColour.r + redColourMod, baseColour.g + greenColourMod, baseColour.b + blueColourMod);
		*/
		float velocityVarient = ((rand() % 100) * forceModifier) / 100;
		tyga::Vector3 initialVelocity = tyga::Vector3((rand() % 3) - 1 * velocityVarient, (rand() % 3) - 1 * velocityVarient, (rand() % 3) - 1 * velocityVarient);

		float size = (rand() % maxSize) * sizeVariation;

		float lifespan = (rand() % maxLifeSpan) * lifeVariation;

		ToyParticle newParticle = ToyParticle(origin, initialVelocity, baseColour, size, 1.0, 2.0);

		particles->initialiseParticle(newParticle);
	}
}