#include "platform/driver/led.h"
#include "led.h"

VlcbPlatformLedEffect vlcb_platform_led_fx_Blink(uint16_t hz) {
}
VlcbPlatformLedEffect vlcb_platform_led_fx_Pulse(uint32_t duration_ms);

VlcbPlatformLedDriver vlcb_platform_led_New(VlcbPlatformLedStatusResolver resolver, VlcbPlatformLedStatusChangeHandler changeHandler);