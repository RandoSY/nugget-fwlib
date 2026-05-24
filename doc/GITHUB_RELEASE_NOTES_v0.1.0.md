# nugget-fwlib v0.1.0 Release Notes

## Included

- GitHub-ready repository structure.
- SVG logo and logo mark.
- REDBOARD/PIC16F18424 board profile.
- Core chip setup helpers.
- GPIO, LED, switch, debounce, latch helpers.
- Timing and cooperative tick helpers.
- ADC and pseudo-DAC/PWM teaching helpers.
- UART text helpers.
- GSA Tiny Text Protocol helpers.
- Diagnostic fault/blink helpers.
- Device skeletons for HX711, HC-SR04, DS18B20, and R&G Show.
- 20 examples from blink to integrated GSA node.
- Minimal Web Serial dashboard and Python serial logger.

## Known limitations

- This is not yet a verified compiled release across all Great Cow BASIC versions.
- Serial receive helper names may require local adaptation.
- HC-SR04, DS18B20, and HX711 modules include teaching skeletons rather than final timed drivers.
- ADC channel names may need adjustment to match exact board wiring and GCB chip definitions.
