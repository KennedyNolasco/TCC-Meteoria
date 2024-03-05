# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devtitans_teia
PRODUCT_DEVICE := teia
PRODUCT_BRAND := TeiaBrand
PRODUCT_MODEL := TeiaModel

PRODUCT_PACKAGES += \
    weatherstation_client

BOARD_SEPOLICY_DIRS += device/devtitans/teia/sepolicy

PRODUCT_PACKAGES += devtitans.weatherstation

PRODUCT_PACKAGES += devtitans.weatherstation-service

DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devtitans/teia/device_framework_matrix.xml

PRODUCT_PACKAGES += android.hardware.sensors@2.X-devsensors-config2

