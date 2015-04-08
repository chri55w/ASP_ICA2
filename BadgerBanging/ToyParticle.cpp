#include "ToyParticle.h"

ToyParticle::ToyParticle() {
	position_ =tyga::Vector3(-400, 400, -400);
	velocity_ = tyga::Vector3(0,0,0);
	colour_ = tyga::Vector3(0,0,0);
	size_ = 0.0;
	sizeDecrementRate = 0.0;
	alpha_ = 0.0;
	alphaDecrementRate = 0.0;
	lifeSpan_ = 0.0;
}

ToyParticle::ToyParticle(tyga::Vector3 position, tyga::Vector3 velocity, tyga::Vector3 colour, float startSize, float startAlpha, float lifeSpan) {
	position_ = position;
	velocity_ = velocity;
	colour_ = colour;
	size_ = startSize;
	sizeDecrementRate = size_ / lifeSpan;
	alpha_ = startAlpha;
	alphaDecrementRate = alpha_ / lifeSpan;
	lifeSpan_ = lifeSpan;
}

ToyParticle::~ToyParticle() {

}

void ToyParticle::updateLifeCycle(const float deltaTime) {

	position_ += velocity_ * deltaTime;
	
	lifeSpan_ -= deltaTime;
	size_ -= sizeDecrementRate * deltaTime;
	alpha_ -= alphaDecrementRate * deltaTime;
}