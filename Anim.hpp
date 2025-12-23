#pragma once
#ifndef ANIM_HPP
#define ANIM_HPP

#define IMGUI_DEFINE_MATH_OPERATORS

#include <Includes/ImGui/imgui.h>
#include <Includes/ImGui/imgui_internal.h>

#include <functional> 

namespace Anim
{
	class FadeAnim
	{
	private:
		float alpha = 0.f;
		float speed = 0.f;
		float target = 1.f;

	public:

		float Update( bool show, float animSpeed )
		{
			speed = animSpeed;

			target = show ? 1.f : 0.f;

			alpha = ImLerp( alpha, target, ImGui::GetIO( ).DeltaTime * speed );

			return alpha;
		}

		void Reset( )
		{
			alpha = 0.f;
			target = 1.f;
		}

		bool Completed( )
		{
			return ( target == 1.f ) ? ( alpha >= 0.8f ) : ( alpha <= 0.1f );
		}
	};

	class Anim
	{
	private:
		float value = 0.f;
		float target = 0.f;

		float start = 0.f;
		float end = 0.f;

		float speed = 0.f;

		bool initialized = false;
	public:

		void Start( const float startValue, const float endValue )
		{
			if( !initialized )
			{
				start = startValue;
				end = endValue;
				value = start;
				target = end;
				initialized = true;
			}
		}

		float Update( float animSpeed )
		{
			speed = animSpeed;
			value = ImLerp( value, target, ImGui::GetIO( ).DeltaTime * speed );

			if( std::abs( value - target ) < 0.1f )
				value = target;

			return value;
		}

		void Reset( )
		{
			value = start;
		}

		void Reverse( )
		{
			target = ( target == end ) ? start : end;
		}

		bool Completed( )
		{
			return value == target;
		}
	};

	class Vec2Anim
	{
	private:
		ImVec2 value, target;

		ImVec2 start, end;

		float speed = 0.f;

		bool initialized = false;
	public:

		void Start( const ImVec2 startValue, const ImVec2 endValue )
		{
			if( !initialized )
			{
				value = startValue;
				target = endValue;

				start = startValue;
				end = endValue;
				initialized = true;
			}
		}

		ImVec2 Update( float animSpeed )
		{
			speed = animSpeed;
			value = ImLerp( value, target, ImGui::GetIO( ).DeltaTime * speed );

			if( std::abs( value.x - target.x ) <= 0.1f && std::abs( value.y - target.y ) <= 0.1f )
				value = target;

			return value;
		}

		void Reset( )
		{
			value = start;
		}

		void Reverse( )
		{
			target = ( ( target.x == end.x ) && ( target.y == end.y ) ) ? start : end;
		}

		bool Completed( )
		{
			return value.x == target.x && value.y == target.y;
		}
	};

	class Vec4Anim
	{
	private:
		ImVec4 value, target;

		ImVec4 start, end;

		float speed = 0.f;

		bool initialized = false;
	public:

		void Start( const ImVec4 startValue, const ImVec4 endValue )
		{
			if( !initialized )
			{
				value = startValue;
				target = endValue;

				start = startValue;
				end = endValue;
				initialized = true;
			}
		}

		ImVec4 Update( float animSpeed )
		{
			speed = animSpeed;
			value = ImLerp( value, target, ImGui::GetIO( ).DeltaTime * speed );

			if( std::abs( value.x - target.x ) <= 0.1f && std::abs( value.y - target.y ) <= 0.1f && std::abs( value.z - target.z ) <= 0.1f )
				value = target;

			return value;
		}

		void Reset( )
		{
			value = start;
		}

		void Reverse( )
		{
			bool igual = ( target.x == end.x ) && ( target.y == end.y ) && ( target.z == end.z );
			target = igual ? start : end;
		}

		bool Completed( )
		{
			return value.x == target.x && value.y == target.y && value.z == target.z;
		}
	};

}

#endif // ANIM_HPP
