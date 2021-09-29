/*
 * frame.h
 *
 *  Created on: 29 Sep 2021
 *      Author: Carl Friess
 */

#ifndef EFFECT_H_
#define EFFECT_H_

#include <stdint.h>
#include <stddef.h>

struct effect {
    const uint8_t *bitmaps;
    const uint16_t *iterations;
    size_t num_frames;
};

#endif /* EFFECT_H_ */
