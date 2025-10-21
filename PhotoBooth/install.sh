echo "--PHOTO BOOTH--"
echo " "
echo "Installing dependencies..."
sudo apt-get update && sudo apt-get install -y 
sudo apt install build-essential cmake git pkg-config \
    libopencv-dev libgtk-3-dev libgphoto2-dev gphoto2 \
    libgpiod-dev libcurl4-openssl-dev libjpeg-dev libpng-dev

echo "Done installing dependencies."
echo " "
