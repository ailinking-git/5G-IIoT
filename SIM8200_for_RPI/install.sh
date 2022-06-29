# get dir
linuxheaders="linux-headers-"
uname_r=$(uname -r)
headerdir="/usr/src/"$linuxheaders$(uname -r)
echo $linuxheaders$(uname -r)

# get raspberrypi kernel headers
if [ ! -d $headerdir ]; then
  sudo apt-get install raspberrypi-kernel-headers
else
  echo "raspberrypi kernel headers dir in"$headerdir
fi
  
cd option
make
mv /lib/modules/$(uname -r)/kernel/drivers/usb/serial/option.ko /lib/modules/$(uname -r)/kernel/drivers/usb/serial/option_bk.ko
cp option.ko /lib/modules/$(uname -r)/kernel/drivers/usb/serial/
cd ..

cd qmi_wwan_simcom/
make
cp qmi_wwan_simcom.ko /lib/modules/$(uname -r)/kernel/drivers/net/usb
cd ..

depmod
modprobe option
modprobe qmi_wwan_simcom
dmesg | grep "ttyUSB"
dmesg | grep "qmi_wwan_simcom"

# DNS file
mkdir -p /usr/share/udhcpc
sudo chmod 777 default.script
sudo cp default.script /usr/share/udhcpc

