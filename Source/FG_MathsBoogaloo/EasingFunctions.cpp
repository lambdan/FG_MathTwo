// Fill out your copyright notice in the Description page of Project Settings.


#include "EasingFunctions.h"

float UEasingFunctions::Ease(const float T, const EEasingFunction EasingFunction)
{
	switch(EasingFunction)
	{
	case EEasingFunction::EEF_None:
		return T;
	case EEasingFunction::EEF_EaseInCirc:
		return 1 - sqrt(1 - pow(T,2));
	case EEasingFunction::EEF_SineInOut:
		return -(FMath::Cos(PI * T) - 1) / 2;
	case EEasingFunction::EEF_EaseInSine:
		return 1 - cos((T*PI) / 2);
	case EEasingFunction::EEF_EaseOutSine:
		return sin((T*PI) / 2);
	case EEasingFunction::EEF_EaseInElastic:
		// double c4 = (2 * PI) / 3;
		return T == 0
		? 0
		: T == 1
		? 1
		: -pow(2,10*T-10) * sin((T*10-10.75)* ((2 * PI) / 3) );
		
	default:
		return T;
	}
	
}