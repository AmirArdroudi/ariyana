#pragma once

#include "Node3D.hpp"
#include "gfx/Viewport.hpp"
#include "sx/math.h"

namespace ari::en
{
	enum class CameraType
	{
		Perspective,
		Orthographic
	};

	class Camera: public Node3D
	{
	public:

		ARI_COMPONENT_CHILD(Camera, Node3D)

		//! Constructor
		Camera()
		{
			Target = sx_vec3f(0.0f, 0.0f, 100.0f);
			Up = sx_vec3f(0.0f, 1.0f, 0.0f);
			Right = sx_vec3f(1.0f, 0.0f, 0.0f);
			zNear = 0.1f;
			zFar = 1000.f;
		}

		//! Destructor
		virtual ~Camera() = default;

		sx_vec3		Target,
					Up,
					Right;
		float		AspectRatio;
		float		Fov = 60.0f;
		float		xMag;
		float		yMag;
		float		zNear;
		float		zFar;
		CameraType	Type;
		sx_mat4		_view,
					_proj;
		bool		_isActive = false;
		
		//! Rotate the camera around an axis.
		void Rotate(float _angle, const sx_vec3& _axis);

		//! Rotate by mouse movement
		void RotateByMouse(int _x, int _y, float _speed);

		//! Move back & forward
		void MoveBF(const float& _speed);

		//! Move left & right
		void MoveLR(const float& _speed);

		//! Move up & down
		void MoveUD(const float& _speed);

		gfx::Viewport* GetViewport();

		void SetViewport(const gfx::Viewport& _viewport);

	protected:

		float			m_fCurRotX  = 0.0f, // Current Rotation X
						m_fLastRotX = 0.0f;	// Last Rotation X
		gfx::Viewport	m_viewport;
		bool			m_bHasViewPort = false;

	}; // Camera
	
} // ari::en
