// all of these copied straight from https://easings.net/

#include "EasingFunctions.h"

float UEasingFunctions::Ease(const float T, const EEasingFunction EasingFunction)
{
	switch (EasingFunction)
	{
	case EEasingFunction::EEF_easeInSine: return easeInSine(T);
	case EEasingFunction::EEF_easeOutSine: return easeOutSine(T);
	case EEasingFunction::EEF_easeInOutSine: return easeInOutSine(T);
	case EEasingFunction::EEF_easeInQuad: return easeInQuad(T);
	case EEasingFunction::EEF_easeOutQuad: return easeOutQuad(T);
	case EEasingFunction::EEF_easeInOutQuad: return easeInOutQuad(T);
	case EEasingFunction::EEF_easeInCubic: return easeInCubic(T);
	case EEasingFunction::EEF_easeOutCubic: return easeOutCubic(T);
	case EEasingFunction::EEF_easeInOutCubic: return easeInOutCubic(T);
	case EEasingFunction::EEF_easeInQuart: return easeInQuart(T);
	case EEasingFunction::EEF_easeOutQuart: return easeOutQuart(T);
	case EEasingFunction::EEF_easeInOutQuart: return easeInOutQuart(T);
	case EEasingFunction::EEF_easeInQuint: return easeInQuint(T);
	case EEasingFunction::EEF_easeOutQuint: return easeOutQuint(T);
	case EEasingFunction::EEF_easeInOutQuint: return easeInOutQuint(T);
	case EEasingFunction::EEF_easeInExpo: return easeInExpo(T);
	case EEasingFunction::EEF_easeOutExpo: return easeOutExpo(T);
	case EEasingFunction::EEF_easeInOutExpo: return easeInOutExpo(T);
	case EEasingFunction::EEF_easeInCirc: return easeInCirc(T);
	case EEasingFunction::EEF_easeOutCirc: return easeOutCirc(T);
	case EEasingFunction::EEF_easeInOutCirc: return easeInOutCirc(T);
	case EEasingFunction::EEF_easeInBack: return easeInBack(T);
	case EEasingFunction::EEF_easeOutBack: return easeOutBack(T);
	case EEasingFunction::EEF_easeInOutBack: return easeInOutBack(T);
	case EEasingFunction::EEF_easeInElastic: return easeInElastic(T);
	case EEasingFunction::EEF_easeOutElastic: return easeOutElastic(T);
	case EEasingFunction::EEF_easeInOutElastic: return easeInOutElastic(T);
	case EEasingFunction::EEF_easeInBounce: return easeInBounce(T);
	case EEasingFunction::EEF_easeOutBounce: return easeOutBounce(T);
	case EEasingFunction::EEF_easeInOutBounce: return easeInOutBounce(T);
	default:
		return T;
	}
}

float UEasingFunctions::easeInSine(const float x)
{
	 return 1 - cos((x * PI) / 2);
}

float UEasingFunctions::easeOutSine(const float x)
{
	return sin((x * PI) / 2);
}

float UEasingFunctions::easeInOutSine(const float x)
{
	return -(cos(PI * x) - 1) / 2;
}

float UEasingFunctions::easeInQuad(const float x)
{
	return x * x;
}

float UEasingFunctions::easeOutQuad(const float x)
{
	return 1 - (1 - x) * (1 - x);
}

float UEasingFunctions::easeInOutQuad(const float x)
{
	return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
}

float UEasingFunctions::easeInCubic(const float x)
{
	return x * x * x;
}

float UEasingFunctions::easeOutCubic(const float x)
{
	return 1 - pow(1 - x, 3);
}

float UEasingFunctions::easeInOutCubic(const float x)
{
	return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

float UEasingFunctions::easeInQuart(const float x)
{
	return x * x * x * x;
}

float UEasingFunctions::easeOutQuart(const float x)
{
	return 1 - pow(1 - x, 4);
}

float UEasingFunctions::easeInOutQuart(const float x)
{
	return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}

float UEasingFunctions::easeInQuint(const float x)
{
	return x * x * x * x * x;
}

float UEasingFunctions::easeOutQuint(const float x)
{
	return 1 - pow(1 - x, 5);
}

float UEasingFunctions::easeInOutQuint(const float x)
{
	return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}

float UEasingFunctions::easeInExpo(const float x)
{
	return x == 0 ? 0 : pow(2, 10 * x - 10);
}

float UEasingFunctions::easeOutExpo(const float x)
{
	return x == 1 ? 1 : 1 - pow(2, -10 * x);
}

float UEasingFunctions::easeInOutExpo(const float x)
{
	return x == 0
		       ? 0
		       : x == 1
		       ? 1
		       : x < 0.5
		       ? pow(2, 20 * x - 10) / 2
		       : (2 - pow(2, -20 * x + 10)) / 2;
}

float UEasingFunctions::easeInCirc(const float x)
{
	return 1 - sqrt(1 - pow(x, 2));
}

float UEasingFunctions::easeOutCirc(const float x)
{
	return sqrt(1 - pow(x - 1, 2));
}

float UEasingFunctions::easeInOutCirc(const float x)
{
	return x < 0.5
		       ? (1 - sqrt(1 - pow(2 * x, 2))) / 2
		       : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}

float UEasingFunctions::easeInBack(const float x)
{
	const double c1 = 1.70158;
	const double c3 = c1 + 1;
	
	return c3 * x * x * x - c1 * x * x;
}

float UEasingFunctions::easeOutBack(const float x)
{
	const double c1 = 1.70158;
	const double c3 = c1 + 1;

	return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}

float UEasingFunctions::easeInOutBack(const float x)
{
	const double c1 = 1.70158;
	const double c2 = c1 * 1.525;

	return x < 0.5
		       ? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		       : (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}

float UEasingFunctions::easeInElastic(const float x)
{
	const double c4 = (2 * PI) / 3;

	return x == 0
		       ? 0
		       : x == 1
		       ? 1
		       : -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * c4);
}

float UEasingFunctions::easeOutElastic(const float x)
{
	const double c4 = (2 * PI) / 3;

	return x == 0
		       ? 0
		       : x == 1
		       ? 1
		       : pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
}

float UEasingFunctions::easeInOutElastic(const float x)
{
	const double c5 = (2 * PI) / 4.5;

	return x == 0
		       ? 0
		       : x == 1
		       ? 1
		       : x < 0.5
		       ? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
		       : (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
}

float UEasingFunctions::easeInBounce(const float x)
{
	return 1 - easeOutBounce(1 - x);
}

float UEasingFunctions::easeOutBounce(const float in)
{
	const double n1 = 7.5625;
    const double d1 = 2.75;
	double x = in;

    if (x < 1 / d1) {
        return n1 * x * x;
    } else if (x < 2 / d1) {
        x -= 1.5 / d1;
        return n1 * x * x + 0.75;
    } else if (x < 2.5 / d1) {
        x -= 2.25 / d1;
        return n1 * x * x + 0.9375;
    } else {
        x -= 2.625 / d1;
        return n1 * x * x + 0.984375;
    }
}

float UEasingFunctions::easeInOutBounce(const float x)
{
	return x < 0.5
		       ? (1 - easeOutBounce(1 - 2 * x)) / 2
		       : (1 + easeOutBounce(2 * x - 1)) / 2;
}


