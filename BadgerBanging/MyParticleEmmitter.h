#pragma once
#include <tyga/ActorDelegate.hpp>
#include <tyga/Math.hpp>
#include <string>

class MyParticleEmmitter : public tyga::ActorDelegate {
	public:
		MyParticleEmmitter();
		~MyParticleEmmitter();

		void randomEmmission(std::string systemName, tyga::Vector3 origin, int minParticles, int maxParticles);

	private:

		virtual void actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorClockTick(std::shared_ptr<tyga::Actor> actor) override;
};

