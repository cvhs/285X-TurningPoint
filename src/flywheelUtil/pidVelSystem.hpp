#pragma once

#include "C:\Users\clove\Desktop\X4\include\main.h"

#include "emaFilter.hpp"

#include "miscUtils.hpp"





namespace flywheelLib

{

	class velPID

	{

	private:



		double m_Kp = 0;

		double m_Kd = 0;

		double m_Kf = 0;



		double m_Error = 0;

		double m_lastError = 0;

		double m_derivative = 0;



		emaFilter m_dFilter;



	public:



		velPID(double, double, double, double);

		double calculate(double, double);

		void setGains(double, double, double, double);

		double getError();



	};

}
