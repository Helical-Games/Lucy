#include "LucyLibraryPrivatePCH.h"
#include "CompositeWidget.h"

UCompositeWidget::UCompositeWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UCompositeWidget::SynchronizeProperties() {
	Super::SynchronizeProperties();
	OnSynchronizeProperties();
}

void UCompositeWidget::OnSynchronizeProperties_Implementation()
{
	// Override this event in Blueprint
}