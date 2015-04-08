#pragma once
#include <tyga/ActorDelegate.hpp>
#include <tyga/Math.hpp>

class MyParticleEmmitter : public tyga::ActorDelegate {
	public:
		MyParticleEmmitter();
		~MyParticleEmmitter();

		void randTestEmit(tyga::Vector3 originPosition);

	private:

		virtual void actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorClockTick(std::shared_ptr<tyga::Actor> actor) override;
};

