#pragma once

#include <tyga/Math.hpp>

class ToyParticle  {

	public:
		ToyParticle();
		ToyParticle(tyga::Vector3 position, tyga::Vector3 velocity, tyga::Vector3 colour, float startSize, float startAlpha, float lifeSpan);
		~ToyParticle();

		tyga::Vector3 getPosition() const { return position_; }
		tyga::Vector3 getVelocity() const { return velocity_; }
		tyga::Vector3 getColour() const { return colour_; }

		float getSize() const { return size_; }
		float getAlpha() const { return alpha_; }
		float getLifeSpan() const { return lifeSpan_; }

		void updateLifeCycle(const float deltaTime);

	private:
		tyga::Vector3 position_;
		tyga::Vector3 velocity_;
		tyga::Vector3 colour_;

		float size_ = 0.0;
		float sizeDecrementRate = 0.0;
		float alpha_ = 0.0;
		float alphaDecrementRate = 0.0;
		float lifeSpan_ = 0.0;
};

