#pragma once

#include <tyga/GraphicsCentre.hpp>
#include "ToyParticle.h"
#include <unordered_map>

class MyParticleSystem;
class MyParticleEmmitter;

class MyParticleManager : public tyga::GraphicsSpriteDelegate, public std::enable_shared_from_this<MyParticleManager>, public tyga::RunloopTaskProtocol {
	public:
		static std::shared_ptr<MyParticleManager> defaultCentre();
		
		MyParticleEmmitter *newEmmitter();

		void initialiseParticle(ToyParticle newParticle);

		void reapDeadParticles();

		void updateParticles();

		void addSystem(std::string systemName);
		void setLifespan(std::string systemName, float minLifespan, float maxLifespan);
		void setSize(std::string systemName, float startSize, float targetEndSize, float sizeRandomiser);
		void setForces(std::string systemName, float gravityModifier, tyga::Vector3 constantForce, float minAcceleration, float maxAcceleration, float accelerationFallOff);
		void setColours(std::string systemName, tyga::Vector3 baseColour, tyga::Vector3 colourVariation, float startAlpha, float endAlpha, std::string textureName);

		MyParticleSystem *getSystem(std::string systemName);

		std::string graphicsSpriteTexture() const override;

		int graphicsSpriteVertexCount() const override;

		void graphicsSpriteGenerate(tyga::GraphicsSpriteVertex vertex_array[]) const override;

		void runloopWillBegin() override;

		void runloopExecuteTask() override;

		void runloopDidEnd() override;

	private:
		/*OLD SYSTEM*/
		void initialiseManager();

		static std::shared_ptr<MyParticleManager> default_centre_;
		std::shared_ptr<tyga::GraphicsSprite> graphic_sprite_;

		std::vector<ToyParticle> particles;

		int MAX_PARTICLES = 10000;
		int LIVE_PARTICLES = 0;

		/*NEW SYSTEM*/

		std::unordered_map<std::string, MyParticleSystem*> particleSystems_;

};

