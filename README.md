# ofxOrbbecAstra

openFrameworks addon for using the [Orbbec Astra SDK](https://orbbec3d.com/develop/). 

Currently using the 2.0.14 SDK

## Setup

The Astra SDK is bundled in the `libs` folder and does not require a separate download or installation.

### Linux
Copy the udev rules in the install folder as follows:
```
sudo cp install/orbbec-usb.rules /etc/udev/rules.d/558-orbbec-usb.rules
```
Use the Project manager to create a project that uses this addon.
Add this line to your qtCreator .qbs file: `cpp.rpaths: ["./libs"]`
Create the `bin\libs` folder if it does not exist.
Copy all files from the `libs/astra/lib/linux64/` folder into the `bin\libs` folder. 

### Windows
Use the Project manager to create a project that uses this addon.

### Mac OS
Use the Project manager to create a project that uses this addon.
Edit the XCode project settings according to the two screenshots in the `docs` folder of this repository

## Support

This has been tested with the following setup:

- openFrameworks 0.9.8 and openFrameworks 0.10.1
- OSX (Does not support SDK greater than 0.5.0, therefore no native body tracking)
- Windows 10 using Visual Studio 2015
- Ubuntu 16.04 and Ubuntu 18.04
- Orbec Astra camera

## More Sample Applications
https://github.com/pierrep/OrbecAstraBodyTracker

