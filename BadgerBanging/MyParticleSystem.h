#pragma once

#include <tyga/Math.hpp>
#include <Vector>
#include "ToyParticle.h"

class MyParticleSystem {
	public:
		MyParticleSystem();
		~MyParticleSystem();

		void setLifespan(float minLifespan, float maxLifespan) {
																minLifespan_ = minLifespan; 
																maxLifespan_ = maxLifespan;
																lifeSpanDiff_ = maxLifespan - minLifespan;
															   }
		void setSize(float startSize, float targetEndSize, float sizeRandomiser) {
																startSize_ = startSize;
																targetEndSize_ = targetEndSize;
																sizeRandomiser_ = sizeRandomiser;
															   }
		void setForces(float gravityMod, tyga::Vector3 constForce, float minAcceleration, float maxAcceleration, float accelerationFallOff) {
																gravityModifier_ = gravityMod;
																constantForce_ = constForce;
																minAcceleration_ = minAcceleration;
																maxAcceleration_ = maxAcceleration;
																accelerationDiff_ = maxAcceleration - minAcceleration;
																accelerationFallOff_ = accelerationFallOff;
															   }
		void setColours(tyga::Vector3 baseColour, tyga::Vector3 colourChannelVariance, float startAlpha, float endAlpha) {
																colour_ = baseColour;
																colourVariation_ = colourChannelVariance;
																startAlpha_ = startAlpha;
																endAlpha_ = endAlpha;
															   }
		float getRandLifespan();
		float getStartSize() const { return startSize_; }
		float getTargetEndSize() const { return targetEndSize_; }
		float getRandSize();
		float getGravityModifier() const { return gravityModifier_; }
		tyga::Vector3 getConstantForce() const { return constantForce_; }
		float getRandAcceleration();
		float getAccelerationFallOff() const { return accelerationFallOff_; }
		tyga::Vector3 getBaseColour() const { return colour_; }
		tyga::Vector3 getRandColour();
		float getStartAlpha() const { return startAlpha_; }
		float getEndAlpha() const { return endAlpha_; }
		

	private:
		float minLifespan_ = 1.0;
		float maxLifespan_ = 1.0;
		float lifeSpanDiff_ = 0.0;

		float startSize_ = 5.0;
		float targetEndSize_ = 0.0;
		float sizeRandomiser_ = 1.0;

		float gravityModifier_ = 0.0;
		tyga::Vector3 constantForce_ = tyga::Vector3(0.0, 0.0, 0.0);
		float minAcceleration_ = 1.0;
		float maxAcceleration_ = 1.0;
		float accelerationDiff_ = 0.0;
		float accelerationFallOff_ = 1.0;

		tyga::Vector3 colour_ = tyga::Vector3(1.0, 1.0, 1.0);
		tyga::Vector3 colourVariation_ = tyga::Vector3(0.0, 0.0, 0.0);
		float startAlpha_ = 1.0;
		float endAlpha_ = 0.0;
};

