#include "LucyLibraryPrivatePCH.h"
#include "LucyFunctions.h"

ULucyFunctions::ULucyFunctions(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void ULucyFunctions::SoundClass_SetVolume(USoundClass* SoundClass, const float Volume)
{
	if (SoundClass == nullptr)
	{
		return;
	}
	SoundClass->Properties.Volume = Volume;
}

float ULucyFunctions::SoundClass_GetVolume(USoundClass* SoundClass)
{
	if (SoundClass == nullptr)
	{
		return 0;
	}
	return SoundClass->Properties.Volume;
}

void ULucyFunctions::SoundClass_SetPitch(USoundClass* SoundClass, const float Pitch)
{
	if (SoundClass == nullptr)
	{
		return;
	}
	SoundClass->Properties.Pitch = Pitch;
}

float ULucyFunctions::SoundClass_GetPitch(USoundClass* SoundClass)
{
	if (SoundClass == nullptr)
	{
		return 0;
	}
	return SoundClass->Properties.Pitch;
}

void ULucyFunctions::SetMousePosition(const int32 X, const int32 Y)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if (Viewport == nullptr)
	{
		return;
	}

	FIntPoint Size = Viewport->GetSizeXY();
	if ((Size.X <= 0) || (Size.Y <= 0))
	{
		return;
	}

	Viewport->SetMouse(FMath::Clamp(X, 0, Size.X), FMath::Clamp(Y, 0, Size.Y));
}

void ULucyFunctions::GetMousePosition(bool& Success, int32& X, int32& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if (Viewport == nullptr)
	{
		return;
	}

	int32 MouseX = Viewport->GetMouseX();
	int32 MouseY = Viewport->GetMouseY();
	if ((MouseX < 0) || (MouseY < 0))
	{
		return;
	}

	Success = true;
	X = MouseX;
	Y = MouseY;
}

void ULucyFunctions::SetMousePositionInPercentages(const float X, const float Y)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if (Viewport == nullptr)
	{
		return;
	}

	FIntPoint Size = Viewport->GetSizeXY();
	Viewport->SetMouse(FMath::RoundToInt(Size.X * FMath::Clamp(X, 0.0f, 1.0f)), FMath::RoundToInt(Size.Y * FMath::Clamp(Y, 0.0f, 1.0f)));
}

void ULucyFunctions::GetMousePositionInPercentages(bool& Success, float& X, float& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	FViewport* Viewport = ViewportClient->Viewport;
	if (Viewport == nullptr)
	{
		return;
	}

	int32 MouseX = Viewport->GetMouseX();
	int32 MouseY = Viewport->GetMouseY();
	if ((MouseX < 0) || (MouseY < 0))
	{
		return;
	}

	FIntPoint Size = Viewport->GetSizeXY();
	if ((Size.X <= 0) || (Size.Y <= 0))
	{
		return;
	}

	Success = true;
	X = MouseX / (float)Size.X;
	Y = MouseY / (float)Size.Y;
}

void ULucyFunctions::SetMouseLockedToViewport(const bool Locked)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SViewport> ViewportWidget = ViewportClient->GetGameViewportWidget();
	if (!ViewportWidget.IsValid())
	{
		return;
	}

	TArray<APlayerController*> LocalPlayerControllers;
	GEngine->GetAllLocalPlayerControllers(LocalPlayerControllers);

	for (APlayerController* LocalPlayerController : LocalPlayerControllers)
	{
		if (LocalPlayerController == nullptr)
		{
			continue;
		}

		ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(LocalPlayerController->Player);
		if (LocalPlayer == nullptr)
		{
			continue;
		}

		if (Locked)
		{
			LocalPlayer->GetSlateOperations().LockMouseToWidget(ViewportWidget.ToSharedRef());
		}
		else
		{
			LocalPlayer->GetSlateOperations().ReleaseMouseLock();
		}
	}
}

void ULucyFunctions::GetPrimaryMonitorResolution(int32& Width, int32& Height)
{
	FDisplayMetrics DisplayMetrics;
	FDisplayMetrics::GetDisplayMetrics(DisplayMetrics);

	Width = DisplayMetrics.PrimaryDisplayWidth;
	Height = DisplayMetrics.PrimaryDisplayHeight;
}

void ULucyFunctions::GetPrimaryMonitorWorkArea(int32& X, int32& Y, int32& Width, int32& Height)
{
	FDisplayMetrics DisplayMetrics;
	FDisplayMetrics::GetDisplayMetrics(DisplayMetrics);

	FPlatformRect Bounds = DisplayMetrics.PrimaryDisplayWorkAreaRect;
	X = Bounds.Left;
	Y = Bounds.Top;
	Width = Bounds.Right - Bounds.Left;
	Height = Bounds.Bottom - Bounds.Top;
}

void ULucyFunctions::GetWindowBounds(bool& Success, int32& X, int32& Y, int32& Width, int32& Height)
{
	Success = false;
	X = 0;
	Y = 0;
	Width = 0;
	Height = 0;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	FVector2D Position = Window->GetPositionInScreen();
	FVector2D Size = Window->GetSizeInScreen();

	Success = true;
	X = Position.X;
	Y = Position.Y;
	Width = Size.X;
	Height = Size.Y;
}

void ULucyFunctions::GetWindowPosition(bool& Success, int32& X, int32& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	FVector2D Position = Window->GetPositionInScreen();

	Success = true;
	X = Position.X;
	Y = Position.Y;
}

void ULucyFunctions::GetWindowSize(bool& Success, int32& Width, int32& Height)
{
	Success = false;
	Width = 0;
	Height = 0;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	FVector2D Size = Window->GetSizeInScreen();

	Success = true;
	Width = Size.X;
	Height = Size.Y;
}

void ULucyFunctions::GetWindowPositiomInPercentagesCentered(bool& Success, float& X, float& Y)
{
	Success = false;
	X = 0;
	Y = 0;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	int32 ScreenX = 0;
	int32 ScreenY = 0;
	int32 ScreenWidth = 0;
	int32 ScreenHeight = 0;
	GetPrimaryMonitorWorkArea(ScreenX, ScreenY, ScreenWidth, ScreenHeight);

	FVector2D Position = Window->GetPositionInScreen();
	FVector2D WindowSize = Window->GetSizeInScreen();

	float NewScreenX = ((Position.X + (WindowSize.X / 2.0f)) - ScreenX) / ScreenWidth;
	float NewScreenY = ((Position.Y + (WindowSize.Y / 2.0f)) - ScreenY) / ScreenHeight;

	Success = true;
	X = NewScreenX;
	Y = NewScreenY;
}


void ULucyFunctions::SetWindowPosition(const int32 X, const int32 Y)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	FMargin BorderSize = Window->GetWindowBorderSize(true);

	Window->MoveWindowTo(FVector2D(FMath::Max(BorderSize.Left, ((float)X)), FMath::Max(BorderSize.Top, ((float)Y))));
}

void ULucyFunctions::SetWindowSize(const int32 Width, const int32 Height)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	Window->Resize(FVector2D(Width, Height));
}

void ULucyFunctions::SetWindowPositiomInPercentagesCentered(const float X, const float Y)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	int32 ScreenX = 0;
	int32 ScreenY = 0;
	int32 ScreenWidth = 0;
	int32 ScreenHeight = 0;
	GetPrimaryMonitorWorkArea(ScreenX, ScreenY, ScreenWidth, ScreenHeight);

	FVector2D WindowSize = Window->GetSizeInScreen();

	float NewScreenX = ScreenX + (ScreenWidth * X) - (WindowSize.X / 2.0f);
	float NewScreenY = ScreenY + (ScreenHeight * Y) - (WindowSize.Y / 2.0f);

	FMargin BorderSize = Window->GetWindowBorderSize(true);

	Window->MoveWindowTo(FVector2D(FMath::Max(BorderSize.Left, NewScreenX), FMath::Max(BorderSize.Top, NewScreenY)));
}

void ULucyFunctions::GetWindowMode(bool& Success, bool& Fullscreen, bool& IsFullscreenWindowed)
{
	Success = false;
	Fullscreen = false;
	IsFullscreenWindowed = false;

	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	EWindowMode::Type Mode = Window->GetWindowMode();

	if (Mode == EWindowMode::Type::Fullscreen)
	{
		Success = true;
		Fullscreen = true;
	}
	else if (Mode == EWindowMode::Type::WindowedFullscreen)
	{
		Success = true;
		Fullscreen = true;
		IsFullscreenWindowed = true;
	}
	else if (Mode == EWindowMode::Type::Windowed)
	{
		Success = true;
	}
}

void ULucyFunctions::SetWindowMode(const bool Fullscreen, const bool IsFullscreenWindowed)
{
	if (GEngine == nullptr)
	{
		return;
	}

	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient == nullptr)
	{
		return;
	}

	TSharedPtr<SWindow> Window = ViewportClient->GetWindow();
	if (!Window.IsValid())
	{
		return;
	}

	if (Fullscreen)
	{
		if (IsFullscreenWindowed)
		{
			Window->SetWindowMode(EWindowMode::Type::WindowedFullscreen);
		}
		else
		{
			Window->SetWindowMode(EWindowMode::Type::Fullscreen);
		}
	}
	else
	{
		Window->SetWindowMode(EWindowMode::Type::Windowed);
	}
}

UWidget* ULucyFunctions::GetPanelRoot(const class UUserWidget* Panel)
{
	return Panel->GetRootWidget();
}

