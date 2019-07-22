#pragma once

#include "core/defines.hpp"
#include "en/Node.hpp"
#include "sx/macros.h"
#include "sx/math.h"

namespace ari::en
{
	class Node3D: public Node
	{
	public:

		ARI_COMPONENT

		//! Constructor
		Node3D() : _isRenderable(false)
		{
			Position = sx_vec3f(0.0f, 0.0f, 0.0f);
			Scale = sx_vec3f(1.0f, 1.0f, 1.0f);
			Rotation = sx_quat_ident();
		}

		//! Destructor
		virtual ~Node3D() = default;

		//! Render
		virtual void Render(const int& _frameTurnIndex) { sx_unused(_frameTurnIndex); }

		sx_vec3 Position;
		sx_quat Rotation;
		sx_vec3 Scale;

		sx_mat4 _finalMat[3];
		bool _isRenderable;

	}; // Node3D

} // ari
