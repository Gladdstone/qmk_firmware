# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DNO_USB_STARTUP_CHECK -DENABLE_FACTORY_TEST

SRC += matrix.c

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_CUSTOM_USER = yes
RGB_MATRIX_INDICATORS = yes
CONSOLE_ENABLE = yes

include keyboards/keychron/bluetooth/bluetooth.mk


