/****************************************************************************
 *
 *   Copyright (c) 2015 PX4 Development Team. All rights reserved.
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
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
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
 ****************************************************************************/

/**
 * @file runway_takeoff_params.c
 *
 * Parameters for runway takeoff
 *
 * @author Andreas Antener <andreas@uaventure.com>
 */

/**
 * Runway takeoff with landing gear
 *
 * @boolean
 * @group Runway Takeoff
 */
PARAM_DEFINE_INT32(RWTO_TKOFF, 0);

/**
 * Specifies which heading should be held during the runway takeoff ground roll.
 *
 * 0: airframe heading when takeoff is initiated
 * 1: position control along runway direction (bearing defined from vehicle position on takeoff initiation to MAV_CMD_TAKEOFF
 *    position defined by operator)
 *
 * @value 0 Airframe
 * @value 1 Runway
 * @min 0
 * @max 1
 * @group Runway Takeoff
 */
PARAM_DEFINE_INT32(RWTO_HDG, 0);

/**
 * Max throttle during runway takeoff.
 *
 * Can be used to test taxi on runway
 *
 * @unit norm
 * @min 0.0
 * @max 1.0
 * @decimal 2
 * @increment 0.01
 * @group Runway Takeoff
 */
PARAM_DEFINE_FLOAT(RWTO_MAX_THR, 1.0);

/**
 * Pitch setpoint during taxi / before takeoff airspeed is reached.
 *
 * A taildragger with steerable wheel might need to pitch up
 * a little to keep its wheel on the ground before airspeed
 * to takeoff is reached.
 *
 * @unit deg
 * @min -10.0
 * @max 20.0
 * @decimal 1
 * @increment 0.5
 * @group Runway Takeoff
 */
PARAM_DEFINE_FLOAT(RWTO_PSP, 0.0);

/**
 * Max pitch during takeoff.
 *
 * Fixed-wing settings are used if set to 0. Note that there is also a minimum
 * pitch of 10 degrees during takeoff, so this must be larger if set.
 *
 * @unit deg
 * @min 0.0
 * @max 60.0
 * @decimal 1
 * @increment 0.5
 * @group Runway Takeoff
 */
PARAM_DEFINE_FLOAT(RWTO_MAX_PITCH, 20.0);

/**
 * Min airspeed scaling factor for takeoff.
 *
 * Pitch up will be commanded when the following airspeed is reached:
 * FW_AIRSPD_MIN * RWTO_AIRSPD_SCL
 *
 * @unit norm
 * @min 0.0
 * @max 2.0
 * @decimal 2
 * @increment 0.01
 * @group Runway Takeoff
 */
PARAM_DEFINE_FLOAT(RWTO_AIRSPD_SCL, 1.3);

/**
 * Throttle ramp up time for runway takeoff
 *
 * @unit s
 * @min 1.0
 * @max 15.0
 * @decimal 2
 * @increment 0.1
 * @group Runway Takeoff
 */
PARAM_DEFINE_FLOAT(RWTO_RAMP_TIME, 2.0f);

/**
 * L1 period while steering on runway
 *
 * @unit s
 * @min 1.0
 * @max 100.0
 * @decimal 1
 * @increment 0.1
 * @group Runway Takeoff
 */
PARAM_DEFINE_FLOAT(RWTO_L1_PERIOD, 5.0f);

/**
 * Enable use of yaw stick for nudging the wheel during runway ground roll
 *
 * This is useful when map, GNSS, or yaw errors on ground are misaligned with what the operator intends for takeoff course.
 * Particularly useful for skinny runways or if the wheel servo is a bit off trim.
 *
 * @boolean
 * @group Runway Takeoff
 */
PARAM_DEFINE_INT32(RWTO_NUDGE, 0);
