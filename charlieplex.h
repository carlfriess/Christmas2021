/*
 * charlieplex.h
 *
 *  Created on: 29 Nov 2021
 *      Author: Carl Friess
 */

#ifndef CHARLIEPLEX_H_
#define CHARLIEPLEX_H_

#include <effect.h>
#include <stdint.h>

void play_effect(const struct effect *effect);
void charlieplex(const uint8_t *bitmap);

#endif /* CHARLIEPLEX_H_ */
