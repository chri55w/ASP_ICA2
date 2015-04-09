#pragma once
#include <tyga/ActorDelegate.hpp>
#include <tyga/Math.hpp>

class MyParticleEmmitter : public tyga::ActorDelegate {
	public:
		MyParticleEmmitter();
		~MyParticleEmmitter();

		void randomEmmission(tyga::Vector3 origin, tyga::Vector3 baseColour, float forceModifier, int maxSize, float sizeVariation, int minParticles, int maxParticles, int maxLifeSpan, float lifeVariation);

	private:

		virtual void actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorClockTick(std::shared_ptr<tyga::Actor> actor) override;
};

