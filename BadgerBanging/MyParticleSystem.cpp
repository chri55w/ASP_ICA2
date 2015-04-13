#include "MyParticleSystem.h"


MyParticleSystem::MyParticleSystem() {
}


MyParticleSystem::~MyParticleSystem() {
}

float MyParticleSystem::getRandLifespan() {
	if (lifeSpanDiff_ > 0) {
		return (rand() % (int)(lifeSpanDiff_*1000.0f) / 1000.0f) + minLifespan_;
	} else {
		return minLifespan_;
	}
}
float MyParticleSystem::getRandSize() {
	if (sizeRandomiser_ > 0) {
		return (rand() % (int)sizeRandomiser_ * 1000.0f) / 1000.0f;
	} else {
		return 0;
	}
}

tyga::Vector3 MyParticleSystem::getRandColour() {
	float randRed = 0.0;
	float randGreen = 0.0;
	float randBlue = 0.0;
	if (colourVariation_.r != 0.0) {
		randRed = (rand() % (int)(colourVariation_.r * 255.f)) / 255.f;
	}
	if (colourVariation_.g != 0.0) {
		randGreen = (rand() % (int)(colourVariation_.g * 255.f)) / 255.f;
	}
	if (colourVariation_.g != 0.0) {
		randBlue = (rand() % (int)(colourVariation_.b * 255.f)) / 255.f;
	}

	return tyga::Vector3(colour_.r + randRed, colour_.g + randGreen, colour_.b + randBlue);
}

float MyParticleSystem::getRandAcceleration() {
	return (rand() % (int)accelerationDiff_) + minAcceleration_;
}