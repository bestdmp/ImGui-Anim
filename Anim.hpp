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
	public:

		void Start( const float startValue, const float endValue )
		{
			value = startValue;
			target = endValue;

			start = startValue;
			end = endValue;
		}

		float Update( float animSpeed )
		{
			speed = animSpeed;
			value = ImLerp( value, target, ImGui::GetIO( ).DeltaTime * speed );

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
			return std::abs( value - target ) <= 0.1f;
		}
	};

	class Vec2Anim
	{
	private:
		ImVec2 value, target;

		ImVec2 start, end;

		float speed = 0.f;
	public:

		void Start( const ImVec2 startValue, const ImVec2 endValue )
		{
			value = startValue;
			target = endValue;

			start = startValue;
			end = endValue;
		}

		ImVec2 Update( float animSpeed )
		{
			speed = animSpeed;
			value = ImLerp( value, target, ImGui::GetIO( ).DeltaTime * speed );

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
			return std::abs( value.x - target.x ) <= 0.2f && std::abs( value.y - target.y ) <= 0.2f;
		}
	};

	class Vec4Anim
	{
	private:
		ImVec4 value, target;

		ImVec4 start, end;

		float speed = 0.f;
	public:

		void Start( const ImVec4 startValue, const ImVec4 endValue )
		{
			value = startValue;
			target = endValue;

			start = startValue;
			end = endValue;
		}

		ImVec4 Update( float animSpeed )
		{
			speed = animSpeed;
			value = ImLerp( value, target, ImGui::GetIO( ).DeltaTime * speed );

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
			return std::abs( value.x - target.x ) <= 0.2f && std::abs( value.y - target.y ) <= 0.2f && std::abs( value.z - target.z ) <= 0.2f;
		}
	};

	//void ExampleFade( )
	//{
	//	//Importante definir para static pois funciona como se realmente fosse a variavel
	//	//porem vai só organizar melhor o codigo :)
	//	static FadeAnim anim;
	//	static bool show = true;

	//	ImGui::PushStyleVar( ImGuiStyleVar_Alpha, anim.Update( show, 3.f ) ); //Seta o valor com a velocidade
	//	{


	//		if( ImGui::Button( "FadeOut" ) )
	//		{
	//			if( anim.Completed( ) ) //Verificar se já completou a animação
	//			{
	//				//Vai fazer o contrario, como a ultima deu o fadeIn agr vai ser fadeOut
	//				show = false;
	//			}
	//		}

	//		if( ImGui::Button( "FadeIn" ) )
	//		{
	//			if( anim.Completed( ) ) //Verificar se já completou a animação
	//			{
	//				//Vai resetar a animação, vai fazer o fade o dnv
	//				anim.Reset( );
	//			}
	//		}

	//	}
	//}

	//void ExampleAnim( )
	//{
	//	//Importante definir para static pois funciona como se realmente fosse a variavel
	//	//porem vai só organizar melhor o codigo :)
	//	static Anim anim;

	//	anim.Start( 0.f, 150.f ); //Seta a posição que vai começar e terminar a animação

	//	ImGui::SetCursorPosY( anim.Update( 3.f ) ); //Seta o valor com a velocidade

	//	if( ImGui::Button( "Reversee" ) )
	//	{
	//		if( anim.Completed( ) ) //Verificar se já completou a animação
	//		{
	//			anim.Reverse( ); //Vai reverter a animação nesse caso vai de ( 150.f para 0.f )
	//		}
	//	}

	//	if( ImGui::Button( "Reset" ) )
	//	{
	//		if( anim.Completed( ) ) //Verificar se já completou a animação
	//		{
	//			anim.Reset( ); //Vai reverter a animação
	//		}
	//	}
	//}

	//void ExampleVec2Anim( )
	//{
	//	//Importante definir para static pois funciona como se realmente fosse a variavel
	//	//porem vai só organizar melhor o codigo :)
	//	static Vec2Anim anim;

	//	//Seta a posição que vai começar e terminar a animação
	//	anim.Start( ImVec2( 0.f, 150.f ), ImVec2( 150.f, 150.f ) );

	//	ImGui::SetCursorPos( anim.Update( 3.f ) ); //Seta o valor com a velocidade

	//	if( ImGui::Button( "Reversee" ) )
	//	{
	//		if( anim.Completed( ) ) //Verificar se já completou a animação
	//		{
	//			anim.Reverse( ); //Vai reverter a animação
	//		}
	//	}

	//	if( ImGui::Button( "Reset" ) )
	//	{
	//		if( anim.Completed( ) ) //Verificar se já completou a animação
	//		{
	//			anim.Reset( ); //Vai resetar a animação
	//		}
	//	}
	//}

	//void ExampleVec4Anim( )
	//{
	//	//Importante definir para static pois funciona como se realmente fosse a variavel
	//	//porem vai só organizar melhor o codigo :)
	//	static Vec4Anim anim;

	//	//Seta a cor que vai começar e terminar a animação
	//	anim.Start( ImColor( 20, 20, 20 ), ImColor( 60, 60, 60 ) );

	//	ImGui::TextColored( anim.Update( 3.f ), "Texto slaoq" ); //Seta o valor com a velocidade

	//	if( ImGui::Button( "Reversee" ) )
	//	{
	//		if( anim.Completed( ) ) //Verificar se já completou a animação
	//		{
	//			anim.Reverse( ); //Vai reverter a animação
	//		}
	//	}

	//	if( ImGui::Button( "Reset" ) )
	//	{
	//		if( anim.Completed( ) ) //Verificar se já completou a animação
	//		{
	//			anim.Reset( ); //Vai resetar a animação
	//		}
	//	}
	//}

}

#endif // ANIM_HPP