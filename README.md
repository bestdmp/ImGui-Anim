
# ImGui-Anim

🇺🇸 Simple file with header only to help animate imgui menus without junk code.
The examples are below. If you have any questions or find any bugs, please contact me on Discord: (bestdmp or best#0248).

🇧🇷 Arquivo simples com hearder-only para ajudar a animar menus imgui sem bagunçar tanto o codigo. Os exemplos estão abaixo, qualquer duvida ou bug me chame no discord: (bestdmp ou best#0248)




## Fade Anim Example

```cpp
#include "Anim.hpp"

	void ExampleFade( )
	{
		//Importante definir para static pois funciona como se realmente fosse a variavel
		//porem vai só organizar melhor o codigo :)
		static Anim::FadeAnim anim;
		static bool show = true;

		ImGui::PushStyleVar( ImGuiStyleVar_Alpha, anim.Update( show, 3.f ) ); //Seta o valor com a velocidade
		{


			if( ImGui::Button( "FadeOut" ) )
			{
				if( anim.Completed( ) ) //Verificar se já completou a animação
				{
					//Vai fazer o contrario, como a ultima deu o fadeIn agr vai ser fadeOut
					show = false;
				}
			}

			if( ImGui::Button( "FadeIn" ) )
			{
				if( anim.Completed( ) ) //Verificar se já completou a animação
				{
					//Vai resetar a animação, vai fazer o fade o dnv
					anim.Reset( );
				}
			}

		}
	}


```

## Normal Anim Example

```cpp
#include "Anim.hpp"

	void ExampleAnim( )
	{
		//Importante definir para static pois funciona como se realmente fosse a variavel
		//porem vai só organizar melhor o codigo :)
		static AnimAnim anim;

		anim.Start( 0.f, 150.f ); //Seta a posição que vai começar e terminar a animação

		ImGui::SetCursorPosY( anim.Update( 3.f ) ); //Seta o valor com a velocidade

		if( ImGui::Button( "Reversee" ) )
		{
			if( anim.Completed( ) ) //Verificar se já completou a animação
			{
				anim.Reverse( ); //Vai reverter a animação nesse caso vai de ( 150.f para 0.f )
			}
		}

		if( ImGui::Button( "Reset" ) )
		{
			if( anim.Completed( ) ) //Verificar se já completou a animação
			{
				anim.Reset( ); //Vai reverter a animação
			}
		}
	}
```


## Vec2 Anim Example

```cpp
#include "Anim.hpp"

	void ExampleVec2Anim( )
	{
		//Importante definir para static pois funciona como se realmente fosse a variavel
		//porem vai só organizar melhor o codigo :)
		static Vec2Anim anim;

		//Seta a posição que vai começar e terminar a animação
		anim.Start( ImVec2( 0.f, 150.f ), ImVec2( 150.f, 150.f ) );

		ImGui::SetCursorPos( anim.Update( 3.f ) ); //Seta o valor com a velocidade

		if( ImGui::Button( "Reversee" ) )
		{
			if( anim.Completed( ) ) //Verificar se já completou a animação
			{
				anim.Reverse( ); //Vai reverter a animação
			}
		}

		if( ImGui::Button( "Reset" ) )
		{
			if( anim.Completed( ) ) //Verificar se já completou a animação
			{
				anim.Reset( ); //Vai resetar a animação
			}
		}
	}
```


## Vec4/ImColor Anim Example

```cpp
#include "Anim.hpp"

	void ExampleVec4Anim( )
	{
		//Importante definir para static pois funciona como se realmente fosse a variavel
		//porem vai só organizar melhor o codigo :)
		static Vec4Anim anim;

		//Seta a cor que vai começar e terminar a animação
		anim.Start( ImColor( 20, 20, 20 ), ImColor( 60, 60, 60 ) );

		ImGui::TextColored( anim.Update( 3.f ), "Texto slaoq" ); //Seta o valor com a velocidade

		if( ImGui::Button( "Reversee" ) )
		{
			if( anim.Completed( ) ) //Verificar se já completou a animação
			{
				anim.Reverse( ); //Vai reverter a animação
			}
		}

		if( ImGui::Button( "Reset" ) )
		{
			if( anim.Completed( ) ) //Verificar se já completou a animação
			{
				anim.Reset( ); //Vai resetar a animação
			}
		}
	}

```
