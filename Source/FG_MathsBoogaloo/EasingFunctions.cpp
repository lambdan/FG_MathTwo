// Fill out your copyright notice in the Description page of Project Settings.


#include "EasingFunctions.h"

float UEasingFunctions::Ease(const float T, const EEasingFunction EasingFunction)
{
	switch(EasingFunction)
	{
	case EEasingFunction::EEF_EaseInCirc:
		return 1 - sqrt(1 - pow(T,2));
	case EEasingFunction::EEF_SineInOut:
		return -(FMath::Cos(PI * T) - 1) / 2;
	case EEasingFunction::EEF_EaseInSine:
		return 1 - cos((T*PI) / 2);
	case EEasingFunction::EEF_EaseOutSine:
		return sin((T*PI) / 2);
		
	default:
		return T;
	}
	
}