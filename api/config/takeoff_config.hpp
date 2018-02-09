/****************************************************************************
 * Copyright (c) 2018 John A. Dougherty. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name ATLFlight nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * In addition Supplemental Terms apply.  See the SUPPLEMENTAL file.
 ****************************************************************************/

#ifndef SNAV_FCI_TAKEOFF_CONFIG_HPP_
#define SNAV_FCI_TAKEOFF_CONFIG_HPP_

#include <cmath>

namespace snav_fci
{

/**
 * @brief Structure containing options for takeoff
 */
struct TakeoffConfig
{
  /**
   * @brief Default constructor
   */
  TakeoffConfig()
  {
    height = 1.5;
    min_takeoff_speed = 0.05;
    max_takeoff_speed = 1;
    max_linear_acceleration_norm = 0.25;
  }

  /**
   * @overload
   */
  TakeoffConfig(float height)
  {
    this->height = fabs(height);
    min_takeoff_speed = 0.05;
    max_takeoff_speed = 1;
    max_linear_acceleration_norm = 0.25;
  }

  /**
   * @overload
   */
  TakeoffConfig(float height, float min_takeoff_speed, float max_takeoff_speed,
      float max_linear_acceleration_norm)
  {
    this->height = fabs(height);
    this->min_takeoff_speed = fabs(min_takeoff_speed);
    this->max_takeoff_speed = fabs(max_takeoff_speed);
    this->max_linear_acceleration_norm = fabs(max_linear_acceleration_norm);
  }

  float height; /**< Takeoff height above ground in meters */
  float min_takeoff_speed; /**< Minimum vertical takeoff speed in meters per second */
  float max_takeoff_speed; /**< Maximum vertical takeoff speed in meters per second */
  float max_linear_acceleration_norm; /**< Maximum vertical takeoff acceleration
                                           magnitude in meters per second squared */
};

} // namespace snav_fci

#endif // SNAV_FCI_TAKEOFF_CONFIG_HPP_

