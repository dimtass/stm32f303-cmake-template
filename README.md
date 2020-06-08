STM32F303 cmake template
----

[![dimtass](https://circleci.com/gh/dimtass/stm32f303-cmake-template.svg?style=svg)](https://circleci.com/gh/dimtass/stm32f303-cmake-template)

This is a template cmake project for the stm32f303. So what's
so special about it? Well, it supports the following things:

* STM32 Standard Peripheral Library
* FreeRTOS

To select the which libraries you want to use you need to provide
cmake with the proper options. By default all the options are set
to `OFF`. The supported options are:

* `USE_STDPERIPH_DRIVER`: If set to `ON` enables the stdperiph library
* `USE_FREERTOS`: If set to `ON` enables FreeRTOS

You also need to provide cmake with the source folder by pointing
the folder to the `SRC` parameter. In this case those two parameters
are supported:
```sh
SRC=src_stdperiph
SCR=src_freertos
```

Finally, you also need to provide the path of the toolchain to
use in the `CMAKE_TOOLCHAIN`.
To enable the UART debug print (`TRACE()`) then you need to enable
the `USE_DBGUART` build flag. This will enable a UART port with the
following pinout with 115200 bps baudrate:

UART TX | UART RX
-|-
PA9 | PA10

For the debug uart, by default there's full support for printf, but
if you want a light-weight printf then you can enable the
`USE_TINY_PRINTF` build flag. This printf won't support uint32_t and
float.

## Cloning the code
Because this repo has dependencies on other submodules, in order to
fetch the repo use the following command:

```sh
git clone --recursive -j8 https://dimtass@bitbucket.org/dimtass/stm32f303-cmake-template.git
```

## Examples
To use the `stdperiph` library example run this command:
```sh
CLEANBUILD=true USE_DBGUART=ON USE_STDPERIPH_DRIVER=ON SRC=src_stdperiph ./build.sh
```

To use the `freertos` example run this command:
```sh
CLEANBUILD=true USE_DBGUART=ON USE_STDPERIPH_DRIVER=ON USE_FREERTOS=ON SRC=src_freertos ./build.sh
```

## Using docker
Instead of setting up a build environment, then if you have docker you can
use my CDE image to build the code without much hassle. Just clone the code
like this:

```sh
docker run --rm -it -v $(pwd):/tmp -w=/tmp dimtass/stm32-cde-image:0.1 -c "CLEANBUILD=true USE_DBGUART=ON USE_STDPERIPH_DRIVER=ON SRC=src_stdperiph ./build.sh"
```

or

```sh
docker run --rm -it -v $(pwd):/tmp -w=/tmp dimtass/stm32-cde-image:latest -c "CLEANBUILD=true USE_DBGUART=ON USE_STDPERIPH_DRIVER=ON USE_FREERTOS=ON SRC=src_freertos ./build.sh"
```

## Flashing the firmware
To flash the firmware in Linux you need the texane/stlink tool.
Then you can use the flash script like this:

```sh
./flash.sh
```

Otherwise you can build the firmware and then use any programmer you like.
The elf, hex and bin firmwares are located in the `build-stm32` folder

```sh
./build-stm32/*/stm32f303-cmake-template.bin
./build-stm32/*/stm32f303-cmake-template.hex
./build-stm32/*/stm32f303-cmake-template.elf
```


To flash the HEX file in windows use st-link utility like this:
```
"C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe" -c SWD -p build-stm32\src\stm32f303-cmake-template.hex -Rst
```

To flash the bin in Linux:
```sh
st-flash --reset write build-stm32/src_stdperiph/stm32f303-cmake-template.bin 0x8000000
```

## FW details
* `CMSIS version`: 4.2.0
* `StdPeriph Library version`: 1.2.3
* `STM3 USB Driver version`: 4.1.0

