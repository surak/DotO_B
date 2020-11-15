# boot.py

# secrets expects two variables set: ssid and wpa2_pass

from secrets import *

import machine  # For deep sleep
import uPyLora.LoRaSender as LoRaSender
import uPyLora.LoRaReceiver as LoRaReceiver
import uPyLora.LoRaPingPong as LoRaPingPong

import uPyLora.config_lora as config_lora
from uPyLora.sx127x import SX127x
from uPyLora.controller_esp32 import ESP32Controller


def do_connect():
    import network
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('connecting to network...')
        sta_if.active(True)
        sta_if.connect(ssid, wpa2_pass)
        while not sta_if.isconnected():
            pass
    print('network config:', sta_if.ifconfig())


do_connect()

controller = ESP32Controller()
lora = controller.add_transceiver(SX127x(name='LoRa'),
                                  pin_id_ss=ESP32Controller.PIN_ID_FOR_LORA_SS,
                                  pin_id_RxDone=ESP32Controller.PIN_ID_FOR_LORA_DIO0)

#LoRaPingPong.ping_pong(lora)
