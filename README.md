# TCC-Meteoria
Repositório pro TCC 

How to install Multi-HAL components on Android 13:
hals.conf goes to ./out/target/product/emulator_x86_64/vendor/etc/sensors/hals.conf and ./device/devtitans/teia/hals.conf

tests folder goes to /home/devtitans-2/aosp/hardware/interfaces/sensors/common/default/2.X/multihal/

after compiling, a file named android.hardware.sensors@2.X-devsensors-config2.so will be generated at /home/devtitans-2/aosp/out/target/product/teia/vendor/lib64/
copy that file to /home/devtitans-2/aosp/out/target/product/emulator_x86_64/vendor/lib64/ so that the multihal can be loaded in the emulator
