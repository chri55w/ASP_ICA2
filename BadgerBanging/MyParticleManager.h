#pragma once

#include <tyga/GraphicsCentre.hpp>
#include "ToyParticle.h"

class MyParticleEmmitter;

class MyParticleManager : public tyga::GraphicsSpriteDelegate, public std::enable_shared_from_this<MyParticleManager>, public tyga::RunloopTaskProtocol {
	public:
		static std::shared_ptr<MyParticleManager> defaultCentre();
		
		MyParticleEmmitter *newEmmitter();

		void initialiseParticles(int minParticles, int maxParticles, tyga::Vector3 origin);

		void reapDeadParticles();

		void updateParticles();

		std::string graphicsSpriteTexture() const override;

		int graphicsSpriteVertexCount() const override;

		void graphicsSpriteGenerate(tyga::GraphicsSpriteVertex vertex_array[]) const override;

		void runloopWillBegin() override;

		void runloopExecuteTask() override;

		void runloopDidEnd() override;

	private:

		void initialiseManager();

		static std::shared_ptr<MyParticleManager> default_centre_;
		std::shared_ptr<tyga::GraphicsSprite> graphic_sprite_;

		std::vector<ToyParticle> particles;

		int MAX_PARTICLES = 10000;
		int LIVE_PARTICLES = 0;
};

