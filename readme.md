# WaggleNet_PnP

This repository hosts the protocol implementation of WaggleNet Smart Sensors. It allows sensor modules to brief the data collection device of its data format and mechanism, so data can be collected without having to write a dedicated driver for the data collector. The only add-on compared to a "dumb" sensor is a $1.2 ATmega CPU and a one-time effort to code the driver. There are also executable codes in this repository to serve as examples:

- Linux / Unix test harness for sensor protocol in `pc_test`.
- Example master program on `main_master.cpp`.
- Example slave (sensor) program on `main_slave.cpp`.

## Quick start

To run this, you need compatible hardware and OS:

- The test harness should work on any POSIX-based system, i.e. Unix, Linux, WSL, Cygwin, MINGW64 (untested), etc.
- The example master program runs on anything ATmega328P / ATmega328PB.
- The example slave program runs on anything ATmega328P / ATmega328PB.

All hardware models run ESP8266 at its core. Double check `platformio.ini` for your programming configuration, and use one of the following environments:

- `master` for testing the master. If you have a slave connected, the master program makes a data structure dump of the sensor, and periodically collects data from it.
- `slave` for the testing the slave, which creates a simple sensor that outputs the analog value of A0, a constant number 42, and the current `millis()`, i.e. milliseconds since bootup.
- For PC test harness, just execute `make` and the executable is `./test`.

In both cases, please check the [how-to document](https://wagglenet.atlassian.net/wiki/spaces/SPORT/pages/54493246/How-to) on preflight check items and how to operate the tools.

## Using this library

We're not yet releasing this as a standard package (soon!). To use this library in your own code:

- If your project uses PlatformIO, just copy `src/sensor` under your project's `lib/` directory. Then include the right files.
- If your project uses Arduino, copy all the files under `src/sensor` to the same directory that hosts your project.
- If you wish to stay updated, you can clone this repo as a submodule and set up a relative symlink (warning: Possibly not Windows-friendly).

Note the `UNO` flag in the build config. This is reserved for ATmega328PB implementations where we can use either the primary serial port (`#ifdef UNO`) or the second serial port. In future WaggleNet Sensors we might enable the second serial port so firmware need to compile against the absence of this flag.

## Code explanation

WaggleNet_PnP is a protocol suite that contains some distinct parts:

- `sensor.h` - Abstraction of Sensor. It describes any sensor as a memory space with all the data mapped onto this space. Note that not all addresses represent one byte - "data" entries represent variable bytes and you must check the length in the next register. This is documented [here](https://wagglenet.atlassian.net/wiki/spaces/SPORT/pages/7995403/Version+1+Specification).
- `pnpsensor.h` - Operation wrapper of the sensor. It wraps the sensor into an "sensor" (device!) that takes care of the data collection, bookkeeping and communication with the master node. Communication is over I2C, and if at any point we have a better protocol we can create a separate wrapper for that.
- `manager.h` - Master node sensor manager. It takes care of the master-side operations such as scanning for sensor devices, surveying the data structures and actually collecting the data. WaggleNet's master devices such as WaggleNode and the Datalogger use this library directly.


