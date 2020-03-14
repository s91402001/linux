#!/bin/bash
#Pi 1
#KERNEL=kernel
#make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcmrpi_defconfig

#Pi 2, Pi 3, Pi 3+, or Compute Module 3
cd linux
KERNEL=kernel7
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- randy_bcm2709_defconfig -j$(nproc)

#Pi 4
#KERNEL=kernel7l
#make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcm2711_defconfig

make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- zImage modules dtbs
