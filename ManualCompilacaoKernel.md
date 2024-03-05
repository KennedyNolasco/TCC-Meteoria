# Compilação do kernel

Vá para a pasta do kernel:

```
cd ~/Kernel-Aosp13
```

Copie para a lá o módulo:

```
cp ~/aosp/device/devtitans/teia/weatherstation-module/ ./weatherstation-module

```

Defina as configurações do kernel (se já tiver feito, ignore):

```

BUILD_CONFIG=common-modules/virtual-device/build.config.virtual_device.x86_64 FRAGMENT_CONFIG=common/arch/x86/configs/gki_defconfig build/config.sh

```

Compile o kernel:

```

time BUILD_CONFIG=common-modules/virtual-device/build.config.virtual_device.x86_64 build/build.sh -j$(nproc)

```

## Copie os arquivos para o AOSP

Remova a pasta do kernel recompilado do AOSP e crie novamente:

```

rm -rf ~/aosp/kernel_recompilado && mkdir -p ~/aosp/kernel_recompilado

```

Copie os arquivo para a pasta do kernel recompilado:

```

cp out/android13-5.15/dist/bzImage ~/aosp/kernel_recompilado

```

```

cp out/android13-5.15/dist/\*.ko ~/aosp/kernel_recompilado

```

Vá para a pasta do AOSP e recompile:

```

source build/envsetup.sh
lunch devtitans_teia-eng
m

```

Ligue o emulador novamente:

```

emulator -qemu -device qemu-xhci,id=xhci -device usb-host,bus=xhci.0,vendorid=0x10c4,productid=0xea60 &
adb shell

```
