/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
    tau_p = Kpi;
    tau_i = Kii;
    tau_d = Kdi;
    output_lim_min = output_lim_mini;
    output_lim_max = output_lim_maxi;
    current_cte = 0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   prev_cte = current_cte;
   current_cte = cte;
   int_cte += cte * delta_time;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double diff_cte = current_cte - prev_cte;
    double control = -tau_p * current_cte - tau_d * diff_cte / delta_time - tau_i * int_cte;
    if (control < output_lim_min) {
      control = output_lim_min;
    } else if (control > output_lim_max) {
      control = output_lim_max;
    }
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
	delta_time = new_delta_time;
}