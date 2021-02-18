// Created by Tommy Bazar. No rights reserved :)
// Special credits go to : Temaran (compute shader tutorial), TheHugeManatee (original concept, supervision)
// and Ryan Brucks (original raymarching code).

#pragma once

#include "Actor/VR/VRMenu/TFMenuPanel.h"
#include "Widget/TransferFuncMenu.h"
#include "Actor/RaymarchVolume.h"

void ATFMenuPanel::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (TransferFuncMenuClass && WidgetComponent)
	{
		WidgetComponent->SetWidgetClass(TransferFuncMenuClass);
		TransferFuncMenu = Cast<UTransferFuncMenu>(WidgetComponent->GetUserWidgetObject());
		if (!TransferFuncMenu)
		{
			WidgetComponent->InitWidget();
			TransferFuncMenu = Cast<UTransferFuncMenu>(WidgetComponent->GetUserWidgetObject());
			if (!TransferFuncMenu)
			{
				return;
			}
		}

		TransferFuncMenu->ListenerVolumes.Empty();

		TransferFuncMenu->SetRangeProviderVolume(ProviderVolume);
		for (ARaymarchVolume* Volume : ListenerVolumes)
		{
			TransferFuncMenu->AddListenerVolume(Volume);
		}
	}
}