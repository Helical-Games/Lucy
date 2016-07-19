#pragma once

#include "Engine.h"
#include "UserWidget.h"
#include "LucyFunctions.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class ULucyFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	* Returns the root widget of User Widget.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Widget", Meta = (DisplayName = "Get Root Widget"))
	static UWidget* GetRootWidget(const class UUserWidget* UserWidget);

	/**
	* Sets the volume of a Sound Class.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Sound Class", Meta = (DisplayName = "Set Volume"))
		static void SoundClass_SetVolume(USoundClass* SoundClass, const float Volume);

	/**
	* Returns the volume of a Sound Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Lucy Library|Sound Class", Meta = (DisplayName = "Get Volume"))
		static float SoundClass_GetVolume(USoundClass* SoundClass);

	/**
	* Sets the pitch of a Sound Class.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Sound Class", Meta = (DisplayName = "Set Pitch"))
		static void SoundClass_SetPitch(USoundClass* SoundClass, const float Pitch);

	/**
	* Returns the pitch of a Sound Class.
	*/
	UFUNCTION(BlueprintPure, Category = "Lucy Library|Sound Class", Meta = (DisplayName = "Get Pitch"))
		static float SoundClass_GetPitch(USoundClass* SoundClass);

	/**
	* Sets the mouse position.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Mouse", Meta = (DisplayName = "Set Mouse Position"))
		static void SetMousePosition(const int32 X, const int32 Y);

	/**
	* Returns the mouse position.
	*
	* Returns Success=false, X=0 and Y=0 if the mouse position could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Viewport is null
	*  - the mouse is outside of the viewport
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Mouse", Meta = (DisplayName = "Get Mouse Position"))
		static void GetMousePosition(bool& Success, int32& X, int32& Y);

	/**
	* Sets the mouse position in percentages, from 0.0 to 1.0.
	*
	* X:  0.0 is left, 1.0 is right
	* Y:  0.0 is top,  1.0 is bottom
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Mouse", Meta = (DisplayName = "Set Mouse Position (Percentages)"))
		static void SetMousePositionInPercentages(const float X, const float Y);

	/**
	* Returns the mouse position in percentages, from 0.0 to 1.0.
	*
	* X:  0.0 is left, 1.0 is right
	* Y:  0.0 is top,  1.0 is bottom
	*
	* Returns Success=false, X=0.0 and Y=0.0 if the mouse position could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Viewport is null
	*  - the mouse is outside of the viewport
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Mouse", Meta = (DisplayName = "Get Mouse Position (Percentages)"))
		static void GetMousePositionInPercentages(bool& Success, float& X, float& Y);

	/**
	* Sets the mouse locked to the viewport (meaning the mouse cursor won't be able to get out of the viewport).
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Mouse", Meta = (DisplayName = "Set Mouse Locked To Viewport", Keywords = "cursor confined min max"))
		static void SetMouseLockedToViewport(const bool Locked);

	/**
	* Returns the primary monitor resolution.
	*/
	UFUNCTION(BlueprintPure, Category = "Lucy Library|Monitor", Meta = (DisplayName = "Get Primary Monitor Resolution", Keywords = "screen size desktop"))
		static void GetPrimaryMonitorResolution(int32& Width, int32& Height);

	/**
	* Returns the primary monitor work area, this is the area not covered by task bars or other docked widgets.
	*/
	UFUNCTION(BlueprintPure, Category = "Lucy Library|Monitor", Meta = (DisplayName = "Get Primary Monitor Work Area", Keywords = "screen size desktop"))
		static void GetPrimaryMonitorWorkArea(int32& X, int32& Y, int32& Width, int32& Height);

	/**
	* Returns the windows bounds in screen space.
	*
	* Returns Success=false, X=0, Y=0, Width=0 and Height=0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Get Window Bounds", Keywords = "size location position"))
		static void GetWindowBounds(bool& Success, int32& X, int32& Y, int32& Width, int32& Height);

	/**
	* Gets the window position in screen space.
	*
	* Returns Success=false, X=0 and Y=0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Get Window Position"))
		static void GetWindowPosition(bool& Success, int32& X, int32& Y);

	/**
	* Gets the window size in screen pixels.
	*
	* Returns Success=false, Width=0 and Height=0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Get Window Size"))
		static void GetWindowSize(bool& Success, int32& Width, int32& Height);

	/**
	* Gets the window position in screen space in percentages, relative to the primary monitor work area, from 0.0 to 1.0.
	*
	* This will take the window size in account, meaning that X=0.5 and Y=0.5 will cause the window to be centered in the primary screen work area.
	*
	* Returns Success=false, X=0.0 and Y=0.0 if the window bounds could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Get Window Position (Percentages)"))
		static void GetWindowPositiomInPercentagesCentered(bool& Success, float& X, float& Y);

	/**
	* Sets the window position in screen space.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Set Window Position"))
		static void SetWindowPosition(const int32 X, const int32 Y);

	/**
	* Sets the window size in screen pixels.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Set Window Size"))
		static void SetWindowSize(const int32 Width, const int32 Height);

	/**
	* Sets the window position in screen space in percentages, relative to the primary monitor work area, from 0.0 to 1.0.
	*
	* This will take the window size in account, meaning that X=0.5 and Y=0.5 will cause the window to be centered in the primary screen work area.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Set Window Position (Percentages)"))
		static void SetWindowPositiomInPercentagesCentered(const float X, const float Y);

	/**
	* Returns the window mode.
	*
	* If Fullscreen is false then IsFullscreenWindowed will also be false.
	*
	* Returns Success=false, Fullscreen=false and Windowed=false if the window mode could not be determined, which happends when:
	*  - GEngine is null
	*  - GEngine's GameViewportClient is null
	*  - GameViewportClient's Window is null
	*  - The mode is pseudo-fullscreen (used for devices like HMDs)
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Get Window Mode", Keywords = "screen fullscreen windowed"))
		static void GetWindowMode(bool& Success, bool& Fullscreen, bool& IsFullscreenWindowed);

	/**
	* Sets the window mode.
	*
	* If Fullscreen is false, it will be windowed.
	* If Fullscreen is true and IsFullscreenWindowed is false, it will be fullscreen.
	* If Fullscreen is true and IsFullscreenWindowed is true, it will be windowed fullscreen.
	*
	* IsFullscreenWindowed is only used when Fullscreen is true.
	*
	* Fullscreen and Windowed can both be true.
	*/
	UFUNCTION(BlueprintCallable, Category = "Lucy Library|Window", Meta = (DisplayName = "Set Window Mode", Keywords = "screen fullscreen windowed"))
		static void SetWindowMode(const bool Fullscreen, const bool IsFullscreenWindowed);
};
