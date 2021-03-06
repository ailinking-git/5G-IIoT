# Raspberry-Pi-as-5G-Smart-Terminal
 The Raspberry Pi integrated with the 5G IoT Modules acts as the 5G Smart Terminal capable of dealing with the variety of IoT scenarios such as video processing, data acquisition and even software defined PLC that need the enhanced radio link capabilities from 5G. Further, it is to be built as the service node in the system supporting the automating deployment, scaling, and management of containerized applications such as Kubernetes.

 The IoT devices with the 5G modules is able to connect to the cutting edge of 5G cellular networks setup by the telecom operator or even the enterprise itself which is known as local 5G or private 5G. The ultra-high data rates and ultra-low latency offered by 5G enables the applications as diverse as remote surgery, autonomous driving, virtual reality gaming, AI-driven smart manufacturing and robotics.

----------
## Description
 The project is divided into several phases:

- **Phase I**: To build the Raspberry Pi device integrated with the 5G IoT Modules enabling the radio communication with the 5G network.

- **Phase II**: To setup the service components in the Phase-I device enabling some use cases such as the remote data acquisition by the RS485 serial port and the remote access of PLC through the 5G network etc.

- **Phase III**: To integrate the Phase-I device into the Kubernetes system wherein the components developed in Phase-II can be managed in the way as if they are running in the work nodes of traditional Kubernetes.  


## Getting Started
### Dependencies

- Hardware: (1) CM4 8G + 32G eMMC, (2) SIM8200EA-M2
- Software: (1) raspios_arm64-2021-10-30, (2) SIM8200_for_RPI

### Installing
- To download the OS for the Raspberry Pi in the following link:
https://downloads.raspberrypi.org/raspios_arm64/images/raspios_arm64-2021-11-08/2021-10-30-raspios-bullseye-arm64.zip

- To unzip and install the following programs in the PC or laptop to be connected to the Raspberry Pi.
1. Rpiboot_setup.zip
2. Panasonic_SDFormatter.zip
3. Win32DiskImager.zip

- To tune the Raspberry Pi into the "image burning" mode.
1. Set the BOOT button to ON.

![BURN0](SIM8200_RPI_4.png "BURN0")

2. Connect the laptop or PC to the Raspberry Pi with the cable for the Type-C to USB converter. The device named as BCM2711 Boot is then displayed as following.

![BCM0](SIM8200_RPI_5.png "BCM0")

- To run Rpiboot in the laptop or PC. The USB driver for the Raspberry Pi is automatically installed. Then the laptop or PC identifies the emcc as the U disk which is followed with the notification of U disk formating. Please ignore the notification.

![Rpiboot0](SIM8200_RPI_6.png "Rpiboot0")

- To launch the SD Card Formater for the emmc formating.

![emmc0](SIM8200_RPI_7.png "emmc0")

- To launch Win32DiskImager.exe to burn the OS image. Select the img file inside 2021-10-30-raspios-bullseye-arm64.zip and click the "Write"  button. After the completion of image burning, please remove the converter cable connecting the Raspberry Pi. The tune the BOOT button to OFF and restart the Raspberry Pi.

![image0](SIM8200_RPI_8.png "image0")

- To config the Raspberry Pi following the instructions about the setting of language, time zone, user account and network etc.

- To launch the automatic start of ssh service for the remote management.

```
systemctl enable ssh
update-rc.d ssh enable
```

- To install the driver of 5G module (SIM8200EA-M2) in the Raspberry Pi.

```
sudo chmod 777 -R SIM8200_for_RPI
cd SIM8200_for_RPI
sudo ./install.sh
```

- To check whether the 5G module works. If so, the information about WWAN0 is displayed.

```
ifconfig -a
```

![WWAN0](SIM8200_RPI_2.png "WWAN0")


- To test the AT command.

```
sudo apt-get install minicom
sudo minicom -D /dev/ttyUSB2
```

![AT](SIM8200_RPI_1.png "AT")

- To check whether the 5G network connection work. If so, the information about DNS query is displayed.

```
cd Goonline
make
sudo ./simcom-cm &
```

![DNS](SIM8200_RPI_3.png "DNS")

- To renew the 5G connection given it fails in accessing the network.

```
sudo dhclient -v wwan0
sudo route add -net 0.0.0.0 wwan0
```

- To enable the automatic execution of the 5G connection procedure after the CM4 restarts. Firstly, the rc.local script should be edited.

```
sudo nano /etc/rc.local
```

Then the following codes are added to the second line from the bottom of the rc.local script.

```
sudo /home/pi/SIM8200_for_RPI/Goonline/simcom-cm &
```

## Authors
1. Yifan Yu, yuyifan@ailinking.com
2. Jiangping Feng, fengjiangping@ailinking.com
3. Zhuo Xu, xuzhuo@ailinking.com

## Acknowledgments
- https://www.waveshare.net/
