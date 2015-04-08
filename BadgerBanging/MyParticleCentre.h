#pragma once

#include <tyga/GraphicsCentre.hpp>
#include <tyga/ActorDelegate.hpp>



class MyParticleCentre : public tyga::GraphicsSpriteDelegate, public std::enable_shared_from_this<MyParticleCentre> {
	public:
		struct Particle : public tyga::ActorComponent {
			tyga::Vector3 position;
			tyga::Vector3 velocity;

			float size = 0.0;
			float alpha = 0.0;
			float lifeSpan = 0.0;
		};

		std::vector<Particle> particles;

		int MAX_PARTICLES = 1000;
		int LIVE_PARTICLES = 0;

		void initialiseParticles(int numberOfParticles);

		void reapDeadParticles();

		std::string graphicsSpriteTexture() const override;

		int graphicsSpriteVertexCount() const override;

		void graphicsSpriteGenerate(tyga::GraphicsSpriteVertex vertex_array[]) const override;
};

class ToyParticle : public tyga::ActorDelegate {
	private:

		virtual void actorDidEnterWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorWillLeaveWorld(std::shared_ptr<tyga::Actor> actor) override;

		virtual void actorClockTick(std::shared_ptr<tyga::Actor> actor) override;

		std::shared_ptr<tyga::GraphicsSprite> graphic_sprite_;

		std::shared_ptr<MyParticleCentre> particle_system_;

};

