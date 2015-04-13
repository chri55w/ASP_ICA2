#pragma once

#include <tyga/Math.hpp>

class ToyParticle  {

	public:
		ToyParticle();
		ToyParticle(tyga::Vector3 position, tyga::Vector3 direction, tyga::Vector3 colour, tyga::Vector3 constForce, float acceleration, float accelerationFallOff, float startSize, float endSize, float startAlpha, float endAlpha, float lifeSpan);
		~ToyParticle();

		tyga::Vector3 getPosition() const { return position_; }
		tyga::Vector3 getVelocity() const { return velocity_; }
		tyga::Vector3 getColour() const { return colour_; }

		float getSize() const { return size_; }
		float getAlpha() const { return alpha_; }
		float getLifeSpan() const { return lifeSpan_; }

		void updateLifeCycle(const float deltaTime);

	private:
		tyga::Vector3 position_ = tyga::Vector3(0, 0, 0);
		tyga::Vector3 velocity_ = tyga::Vector3(0, 0, 0);
		tyga::Vector3 direction_ = tyga::Vector3(0, 1, 0);
		tyga::Vector3 colour_ = tyga::Vector3(0, 0, 0);

		float size_ = 0.0;
		float sizeDecrement = 0.0;
		float alpha_ = 0.0;
		float alphaDecrement = 0.0;
		float lifeSpan_ = 0.0;
		float acceleration_ = 0.0;
		float accelerationDecrement = 0.0;
};

