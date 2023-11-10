// Fill out your copyright notice in the Description page of Project Settings.


#include "EasingFunctions.h"

float UEasingFunctions::Ease(const float T, const EEasingFunction EasingFunction)
{
	switch (EasingFunction) // https://easings.net/
	{
	case EEasingFunction::EEF_EaseInCirc:
		return EaseInCirc(T);
	case EEasingFunction::EEF_SineInOut:
		return SineInOut(T);
	case EEasingFunction::EEF_EaseInSine:
		return EaseInSine(T);
	case EEasingFunction::EEF_EaseOutSine:
		return EaseOutSine(T);
	case EEasingFunction::EEF_EaseInElastic:
		return EaseInElastic(T);
	default:
		return T;
	}
	
}

float UEasingFunctions::SineInOut(const float T)
{
	return -(FMath::Cos(PI * T) - 1) / 2;
}

float UEasingFunctions::EaseInCirc(const float T)
{
	return 1 - sqrt(1 - pow(T, 2));
}

float UEasingFunctions::EaseInSine(const float T)
{
	return 1 - cos((T * PI) / 2);
}

float UEasingFunctions::EaseOutSine(const float T)
{
	return sin((T * PI) / 2);
}

float UEasingFunctions::EaseInElastic(const float T)
{
	double c4 = (2 * PI) / 3;
	return T == 0
		       ? 0
		       : T == 1
		       ? 1
		       : -pow(2, 10 * T - 10) * sin((T * 10 - 10.75) * c4);
}
