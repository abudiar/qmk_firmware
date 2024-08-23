BOOTMAGIC_ENABLE = no       	# Virtual DIP switch configuration(+1000)
CONSOLE_ENABLE = no         	# Console for debug(+400)
BACKLIGHT_ENABLE = no      		# Enable keyboard backlight functionality
MIDI_ENABLE = no            	# MIDI controls
AUDIO_ENABLE = no          		# Audio output on port C6
UNICODE_ENABLE = no         	# Unicode
BLUETOOTH_ENABLE = no       	# Enable Bluetooth with the Adafruit EZ-Key HID

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    		# Breathing sleep LED during USB suspend



MOUSEKEY_ENABLE = yes       	# Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       	# Audio control and System control(+450)
COMMAND_ENABLE = yes        	# Commands for debug and configuration
NKRO_ENABLE = yes            	# Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = yes        	# Enable WS2812 RGB underlight.
WS2812_DRIVER = vendor			# RP2040 Specific Driver
ENCODER_ENABLE = yes			# Enable Rotary Encoder
ENCODER_MAP_ENABLE = yes		# Enable Rotary Encoder Keymaps
