#include "ToyParticle.h"

ToyParticle::ToyParticle() {
	position_ = tyga::Vector3(-400, 400, -400);
}

ToyParticle::ToyParticle(tyga::Vector3 position, tyga::Vector3 direction, tyga::Vector3 colour, tyga::Vector3 constForce, float acceleration, float accelerationFallOff, float startSize, float endSize, float startAlpha, float endAlpha, float lifeSpan) {
	position_ = position;
	direction_ = direction;
	velocity_ = constForce;
	acceleration_ = acceleration;
	accelerationDecrement = acceleration / accelerationFallOff;
	colour_ = colour;
	size_ = startSize;
	sizeDecrement = fabs(startSize - endSize) / lifeSpan;
	alpha_ = startAlpha;
	alphaDecrement = fabs(startAlpha - endAlpha) / lifeSpan;
	lifeSpan_ = lifeSpan;
}

ToyParticle::~ToyParticle() {

}

void ToyParticle::updateLifeCycle(const float deltaTime) {

	if (acceleration_ > 0) {
		velocity_ += (direction_ * acceleration_) * deltaTime;
		acceleration_ -= accelerationDecrement * deltaTime;
	}

	position_ += velocity_ * deltaTime;
	
	lifeSpan_ -= deltaTime;
	size_ -= sizeDecrement * deltaTime;
	alpha_ -= alphaDecrement * deltaTime;

	if (size_ < 0) {
		int i = 0;
	}
	if (alpha_ < 0.1) {
		int i = 0;
	}
}