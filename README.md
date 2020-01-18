STM32F303 cmake template
----

This is a template cmake project for the stm32f103. So what's
so special about it? Well, it supports the following things:

* STM32 Standard Peripheral Library
* FreeRTOS (not working example yet)

To select the which libraries you want to use you need to provide
cmake with the proper options. By default all the options are set
to `OFF`. The supported options are:

* `USE_STDPERIPH_DRIVER`: If set to `ON` enables the stdperiph library
* `USE_FREERTOS`: If set to `ON` enables FreeRTOS

You also need to provide cmake with the source folder by pointing
the folder to the `SRC` parameter.

Finally, you also need to provide the path of the toolchain to
use in the `CMAKE_TOOLCHAIN`.

## Cloning the code
Because this repo has dependencies on other submodules, in order to
fetch the repo use the following command:

```sh
git clone --recursive -j8 https://dimtass@bitbucket.org/dimtass/stm32f103-cmake-template.git
```

## Examples
To use the `stdperiph` library example run this command:
```sh
CLEANBUILD=true USE_STDPERIPH_DRIVER=ON SRC=src_stdperiph ./build.sh
```

To use the `freertos`/`opencm3` example run this command:
```sh
CLEANBUILD=true USE_STDPERIPH_DRIVER=ON USE_FREERTOS=ON SRC=src_freertos ./build.sh
```

To flash the HEX file in windows use st-link utility like this:
```"C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe" -c SWD -p build-stm32\src\stm32f103_wifi_usb_psu.hex -Rst```

To flash the bin in Linux:
```st-flash --reset write build-stm32/src_stdperiph/stm32-cmake-template.bin 0x8000000```

## FW details
* `CMSIS version`: 4.2.0
* `StdPeriph Library version`: 1.2.3
* `STM3 USB Driver version`: 4.1.0

