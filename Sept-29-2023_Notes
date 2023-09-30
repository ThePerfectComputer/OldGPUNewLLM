I spent over 40 hours figuring out how to configure the DellR720 server to work with the Mi25. Will need to document this process some more later, but here are some notes on getting the Mi25's to run in Ubuntu for now.

Download Ubuntu 23.04.5
https://docs.amd.com/en/docs-5.3.0/deploy/linux/quick_start.html

# Make the directory if it doesn't exist yet.
# This location is recommended by the distribution maintainers.
sudo mkdir --parents --mode=0755 /etc/apt/keyrings
# Download the key, convert the signing-key to a full
# keyring required by apt and store in the keyring directory
wget https://repo.radeon.com/rocm/rocm.gpg.key -O - | \
    gpg --dearmor | sudo tee /etc/apt/keyrings/rocm.gpg > /dev/null

# ROCm repository for jammy
sudo tee /etc/apt/sources.list.d/rocm.list <<'EOF'
deb [arch=amd64 signed-by=/etc/apt/keyrings/rocm.gpg] https://repo.radeon.com/rocm/apt/debian jammy main
EOF


echo -e 'Package: *\nPin: release o=repo.radeon.com\nPin-Priority: 600' | sudo tee /etc/apt/preferences.d/rocm-pin-600

sudo apt update
sudo apt install amdgpu-dkms
sudo usermod -a -G render,video $LOGNAME
sudo reboot

sudo apt install rocm-hip-libraries
sudo apt install rocm-hip-sdk
sudo apt install rocm-hip-sdk5.3.0 rocm-hip-sdk5.2.1
export PATH=$PATH:/opt/rocm-5.3.2/bin:/opt/rocm-5.2.1/opencl/bin

