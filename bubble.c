/*** AUTO-GENERATED EFFECT FILE ***

{"name":"bubble","frames":[{"_leds":[false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false],"duration":100},{"_leds":[false,false,false,false,true,false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false,true,false,false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,false],"duration":100},{"_leds":[false,false,false,true,true,false,false,false,false,true,true,false,false,false,false,false,false,false,false,false,false,false,true,true,false,false,true,true,false,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false,true,true,false,false,false,false,false,false,false],"duration":100},{"_leds":[false,false,true,true,true,false,false,false,false,true,true,true,false,false,false,false,false,false,false,false,false,false,true,true,true,false,true,true,false,true,false,false,false,false,false,false,true,true,true,false,false,false,false,false,false,true,true,true,false,false,false,false,false,false],"duration":100},{"_leds":[false,true,true,true,true,true,false,true,false,true,true,true,true,false,true,false,true,false,true,true,false,false,true,true,true,true,true,true,false,true,true,false,true,false,true,false,true,true,true,true,false,true,false,true,false,true,true,true,true,false,true,false,true,false],"duration":100},{"_leds":[true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true],"duration":100},{"_leds":[true,true,true,true,false,true,true,true,true,false,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,true,false,true,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true,false,true,true,true,true,true,true,true,true],"duration":100},{"_leds":[true,true,true,false,false,true,true,true,true,false,false,true,true,true,true,true,true,true,true,true,true,true,false,false,true,true,false,false,true,true,true,true,true,true,true,true,false,false,true,true,true,true,true,true,true,false,false,true,true,true,true,true,true,true],"duration":100},{"_leds":[true,true,false,false,false,true,true,true,true,false,false,false,true,true,true,true,true,true,true,true,true,true,false,false,false,true,false,false,true,false,true,true,true,true,true,true,false,false,false,true,true,true,true,true,true,false,false,false,true,true,true,true,true,true],"duration":100},{"_leds":[true,false,false,false,false,false,true,false,true,false,false,false,false,true,false,true,false,true,false,false,true,true,false,false,false,false,false,false,true,false,false,true,false,true,false,true,false,false,false,false,true,false,true,false,true,false,false,false,false,true,false,true,false,true],"duration":100}]}

*/

#include <effect.h>

static const uint16_t iterations[] = { 51, 51, 51, 51, 51, 51, 51, 51, 51, 51 };
static const uint8_t bitmap[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x40, 0x04, 0x10, 0x20, 0x00, 0x18, 0x06, 0xc0, 0x0c, 0x30, 0x60, 0x00, 0x1c, 0x0e, 0xc0, 0x2d, 0x70, 0xe0, 0x00, 0xbe, 0x5e, 0xcd, 0x6f, 0xf5, 0xea, 0x15, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xef, 0xfd, 0xbf, 0xfb, 0xef, 0xdf, 0x3f, 0xe7, 0xf9, 0x3f, 0xf3, 0xcf, 0x9f, 0x3f, 0xe3, 0xf1, 0x3f, 0xd2, 0x8f, 0x1f, 0x3f, 0x41, 0xa1, 0x32, 0x90, 0x0a, 0x15, 0x2a };

const struct effect bubble = {
    .bitmaps = bitmap,
    .iterations = iterations,
    .num_frames = 10,
};
