# Project Title
This project contains the implementation of the QWIC AWS assignment.

# Getting Started
The project consists of a root and two subfolders. 

The root folder contains the actual implementation.
The `QWIC.ino` file has to be opened in Arduino IDE.
The `secrets.h` file contains the credentials required to connect to AWS IoT.

The `Assignment` folder contans the original brief.

The `KeysAndStuff` folder contains the scratchpad that was used to decode the certificates and private keys. 
It contains the files:

* `AmazonRootCA1.pem` and `AmazonRootCA1.pem.txt`: The Amazon Root CA 1 in binary and text format.
* `0dc78da7b7-private.pem.key.txt` and `0dc78da7b7-certificate.pem.crt.txt`, which respectively contains the device's private key and certificate, as supplied by QWIC, in text format.
* `9aee880e27-*`, the device's certificate, public and private keys (both in binary and text format) as required when connecting to my personal AWS account.

The project was tested on an ESP32 Dev Kit.


# Prerequisites
The project requires Arduino IDE v1.8.12. 

The Arduino IDE has to be configured for the ESP32 Dev Kit. 

The latest version of the `MQTT` and `ArduinoJson` libraries have to be installed.

A USB driver for the serial port that is used for communication with the ESP32 Dev Kit has to be installed. I used the driver supplied with Silicon Labs on my Windows 7 Pro development PC.

At the time of this writing, this Arduino IDE v1.8.12 crashes on the macOS Catalina. Rolling back to version v1.8.10 seemingly causes the MQTT library to become out of sync, so I reverted to my Windows PC.

# Running the tests

Once `QWIC.ico` has been loaded into the Arduino IDE, simply upload the sketch `Sketch | Upload`.

Should you fail to upload the binary to the ESP32 Dev Board, refer to [https://randomnerdtutorials.com/solved-failed-to-connect-to-esp32-timed-out-waiting-for-packet-header/](https://randomnerdtutorials.com/solved-failed-to-connect-to-esp32-timed-out-waiting-for-packet-header/): I simply followed their instructions to hold down the BOOT button while uploading and clicking the EN button on completion of the upload.

Using the supplied credentials, I have failed to subscribe to the `qwic/assignment` topic as required by the assignment. But to prove that I can both subscibe and publist to AWS topics, I have instrumented the code to do exactly that to my own Thing and topics.

The `QWIC` #define controls which one of the two variants are built and uploaded. 

* Defining the `QWIC` symbol (at the top the QWIC tab) causes the QWIC assignment to be built. 
* Undefining the `QWIC` symbol causes the alternative application to be built. 

# Authors
Martin Booyens - Initial work 
See also the list of contributors who participated in this project.

# License
This project is licensed under the MIT License - see the LICENSE.md file for details

# Acknowledgments
Google in general (and [https://aws.amazon.com/blogs/compute/building-an-aws-iot-core-device-using-aws-serverless-and-an-esp32/](https://aws.amazon.com/blogs/compute/building-an-aws-iot-core-device-using-aws-serverless-and-an-esp32/) in particular). 