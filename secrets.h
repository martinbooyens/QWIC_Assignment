#include <pgmspace.h>

#define SECRET

const char WIFI_SSID[] = "VFNL-48DB6A";
const char WIFI_PASSWORD[] = "IUGEOLXP";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

#ifdef QWIC
#define THINGNAME "Martin"

const char AWS_IOT_ENDPOINT[] = "abbdzu9q7kew3-ats.iot.eu-west-1.amazonaws.com";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUG+Z2WACCUPe6FLeBIPFjDhnLdFcwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIwMDUyMDE1MTcw
MVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALjDWGB230R+kqwVFuin
EuB/g4250IxX/Y/QXyZW9VdJV5+SNENcukdMIURAadmqtmQz7iCs6q58YdgDf4v8
7veVoUplBdkOVUAkRzT9VMn5sMGZat744ZvJ4upO4vNECmzs9RfLagk1cGAoI2Ps
6LFgEhr9jVK9+/E3B5JX46Ba6qepZyaMESRprdkcldTknzosikFhvUITuA/2xPzW
hgLA0EDIIi+4m4CrD3m0P50NkbOximNwjOriE3c0jkBHBn46L+hb6MaAWEcMmYBp
LfOJyceymWhsHBsikgu4avpnd26Q7hpRxclsch17zQ4JkQkr+TQYKvuVcGq7kWiU
9pMCAwEAAaNgMF4wHwYDVR0jBBgwFoAUCOwHEbsnVp+N4cpoXe5VCpKZgWYwHQYD
VR0OBBYEFP4YGZ1GFR90XLfRt7Srfuz/SjcnMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQB/ZpaMNVpyXLh0E/tWniFioDMP
Ng7J8BFk9XxWpy565OCbE94G09aoUfNXVpzXTPm5kgBIZT8Cgg3JXMpjOd9tvXRw
PhNbTrPl/MrV993Pvc2CdHpMujNMavkbAzsfsDtufDzyIzqAGMyMcXQ2qtyZi44t
Php0SJoN5q251jFWF7ZEBQvqzqCGMCgoaxjQQ1Z7BkbxxkaC1RACOW/S6KRWoGrF
v9b5DGLYmTA9eZ5ZijOS/00XG3s8g16oyrQuCLK1tnxyKGaz2a00vnka86AJb73Q
JMPgjvxIbBPevGLAqc750aas9hNHEpMAmRRt6TQQ8AWzo0wGlDBBmfY/bxFr
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN PRIVATE KEY-----
MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQC4w1hgdt9EfpKs
FRbopxLgf4ONudCMV/2P0F8mVvVXSVefkjRDXLpHTCFEQGnZqrZkM+4grOqufGHY
A3+L/O73laFKZQXZDlVAJEc0/VTJ+bDBmWre+OGbyeLqTuLzRAps7PUXy2oJNXBg
KCNj7OixYBIa/Y1SvfvxNweSV+OgWuqnqWcmjBEkaa3ZHJXU5J86LIpBYb1CE7gP
9sT81oYCwNBAyCIvuJuAqw95tD+dDZGzsYpjcIzq4hN3NI5ARwZ+Oi/oW+jGgFhH
DJmAaS3zicnHsplobBwbIpILuGr6Z3dukO4aUcXJbHIde80OCZEJK/k0GCr7lXBq
u5FolPaTAgMBAAECggEBAI625UbtyxufITAmwiFHHD+ofzcz9jDRrpwtebGlrbCU
iEhLqG736zMzTObpUlm9kVDpA+DdcBEDJpiyawz4fKVlQMa0LcYxWgxHeXEm1R2F
7tA77t74I1wwn0QZVxhM0Di+97o/d1JRotHDb0K6Nir8aD/M5iKpeTgjJ4gUt1Ce
WHB1P+TxgYGMV7vNpmtE3BBHqWIROc6arhb1069grwP1HujiGrgDo25Bk1YTXP8d
4Iy9nlpGLaV+syso7z0xTtsNAZdJOCurFNma3WtcdrwiBVdCw7MR3fnVlxrva3Hu
lOfe+ll4LkljxPqmgYET5/7q7AKHOq4O8zAMrPy79qECgYEA6wXAestscdjoPv0m
BohCMychrcoRtanD2MzW3l0jMqH8knlRJiUMBNi7mYrluzrTJPFQDhza2qK0wpE3
4+QTg7AoBy6IhI8g26rSSK6wnAwPQe+PH6bnBYutOtmBLrzufq9fm29UnzG2hNQy
mXT5cCZV0gE0qrqUdea4JOBwQOsCgYEAyUErV1+EH+QzO9zgY2tdb8z+NcaQcpA6
cl/wuZ6oKFvxAJaeR7cjrPfpyecLrBG+ynGeRCHodg28S/vNgEOpVK63uZb9CMeV
sjZCEW65Vo+xoA+vY+uWQbgW1s3ZoGyihDgWihn6rIwHSyn5nL88pUlhKvbLSBLA
6LhDkBYM9vkCgYBMw54w/Yy4St7g5BKtg4gL6TYo652JNqAPiiiMjONYQGyc8x88
VFFuq9PqvOF4nCgnIuLBGU+qpgZgnsogl3iARONuJRbWJWHYHh19PAHXlmDNao/X
CM7gktTMKgr11yQXIPUbceuz66rwC9dTJE/s/7h8VYR8V2DyeZ+f++bubQKBgQCO
tjjOv3vIxaCTHaC8v2DFq/7EEWdS5fWcL25boicqX3A585SP1E1nFXHia4V6YicC
FameNNFMDZdt5kQmZVSJKVA9OdV6yVTcx973z6V7vW++ygCcgW3OcoU3k0d0nDRu
P/uzuJJqku2FHmHUBkQyDSPrPJCQLkQ/gpLedNSCuQKBgD7rLUsHFJsO9YxrcXQs
z+CqxavMXURAMSCcFRlTSjha7VY0lQKM77vY+hdmp1kNoDZ4pWE1A095dIilq8GH
rpV40Gyl01PLVZlzZCahZD1dTXzVPQJiAGe1k4jaJA8jwhpxBfdqzSXSLlZVz1p/
AqcisYfLFq75OPXzwbYj2i9g
-----END PRIVATE KEY-----
)KEY";

#else // QWIC
#define THINGNAME "MyThing"

const char AWS_IOT_ENDPOINT[] = "a2vq3qdtb7z70k-ats.iot.us-east-2.amazonaws.com";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAJ7jZPhkdlkMy85BShIAHWSWzr10MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMDA1MjMxMDEw
NTZaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC+JpkJEujSWCXO+uT5
ghDhZnXMgfbxb9ci8baSyu0FFmomcd1ob1lMnU5wRnx2Y2AeIyjR7Uw5tLRi/Q6D
R8D/3gaNEP7o/d+hPAhd2KdlnBVmn2d/pxIhHQRBmwp5+2GQopObPI5eUUiQp02n
EWSIVlkQvnwP44L4pyao73A3gsSweP81kY10dL8+OgOIFhXq0Zc5f0STk+78HcR9
J+R2aYi12XDFLkQbWnKoade64WT8wPZTvNVgYg667/YrjP0cP6ZwhQ/31/efdQzP
lOdIeZ0jxcml93mUGyie+GX3fTdD+VeGPKdVtCiOLopP4z7RIEFH4LoCBDGirSnA
Zi3nAgMBAAGjYDBeMB8GA1UdIwQYMBaAFFNdBn4hRuF+9FgOEWLhipOh0E6gMB0G
A1UdDgQWBBSMkwPPfIMt37WXftWDYsuHCLb/HjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAiom4fzcbxswKc+KCqvweP8AC
gBWJ14bS/4X6F8C+Tw9esZx3rLkkv3lNbiJBafCGy2qsm2iwfDkVN41JcQhlZbuk
WvLfVTMEGnhgHJuTDGVfBzz2bhzpBX2iMUXKN3m+sKml43yrY0/i3QUwzvrZMkOO
0sUN9vhGMriIacaMaBWriZnwV/lujRfJp+QMXOA4rG0Ep2wjXjPwMRvJHiyEh+Ua
A5ykKSIEmscgpf/PrXHnKRM0p8JHDC6BlPatlXOZW8fCe+iU6G+IDBL7jP1lg3Ty
1MTzIdjvl4Nca2i2yU4RI9WlQTKycdXxetETHtnqudg4pi8+Q2kasiISiXd5lA==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEAviaZCRLo0lglzvrk+YIQ4WZ1zIH28W/XIvG2ksrtBRZqJnHd
aG9ZTJ1OcEZ8dmNgHiMo0e1MObS0Yv0Og0fA/94GjRD+6P3foTwIXdinZZwVZp9n
f6cSIR0EQZsKefthkKKTmzyOXlFIkKdNpxFkiFZZEL58D+OC+KcmqO9wN4LEsHj/
NZGNdHS/PjoDiBYV6tGXOX9Ek5Pu/B3EfSfkdmmItdlwxS5EG1pyqGnXuuFk/MD2
U7zVYGIOuu/2K4z9HD+mcIUP99f3n3UMz5TnSHmdI8XJpfd5lBsonvhl9303Q/lX
hjynVbQoji6KT+M+0SBBR+C6AgQxoq0pwGYt5wIDAQABAoIBAQCeQh+ilrNhxe2J
y/Vg2GjWQGGQmSZ/IZdLxSMwH2aPkm08nA4rimknQ9FxzqhuHB12V8r0lWyYppZv
wLAggUrXaeHH7LpMDmfemMlZ2iTQg8yoAcmxS8rh9nWBaNmaVqeIKldxnz/argoY
IraVcvtaIYu1TOSSkMeDzhJ2Dfo2p9dOy+8NK24qDKvc+kGIA4/mNxLhGC4l7Caw
6IJ/+28VKeemWnhWSBSnPCO9Ee9681bC5r4g0RElUQoyFwvIQPU44u0MPVXKmt6i
JX8HfBPBBSSgQNxwOquvV7hHU73gN8nf8crqe7Ht6kT5e59xpijxqo6W1VV91JSB
+CpjOe55AoGBAOIkcS1r1vCoHSFo8Riyo330qsyXNacDKCVD941sfdBpNURqyeuu
Kk4D8067rBf//zWF6DrhCFj3csRPTQrz1MIkmEUyXybXtAOy3jaOMcVvbOIO3Nsw
5hnf/KgppzFiP56ucd2kbyP+ZPLSUbg5WbEf9YMNPl0n5Df1JmKBpqrTAoGBANdB
phqrwAgiJbK/mwe5k/RaAzXsc7MnNoeGEyJ2rNVBkqfzeOufWyGw/WJ7U8/vz8GB
vNDe5U5+Kqs5sDrVqYh9ElZhq6Eev4N3WSCtphUBnqY+9dD0TzM12fiPuz3neYoS
zTOVWrFEfPFQpPXiE6ABpFGqMPzyaHexOygxu1wdAoGAN+HvgdzrQY8Zm772DTdf
xWlnp6UaIgpaqlLQYsdTk+PbwOtuuGnSlHLPdj5UOZ4OL+jGSX6AdJO5bZ93F2TH
x64JXtgiwVN+bYeO+AZNcE+npXksxJGh2vUJ13hrk32G4SyUgMP4nvlncsXcYdzy
OB4AqoDkT1rjP5y5/o+xYvcCgYEA0am1+qBziPiJs5OBk4KkpArQucM35rY5HMPw
+06QhZ87E6/IhehPwX89LqFlP1IcECUoHmIdA9lMAj9MceIPIUyBgfXcUDE85PZo
r7Wz4R4Uw2Tr1b1BL2YyizKkdGV0MpKhoK7HCYbmE74zDvRHnUA8JvcYhCgwrPTJ
5BqcndkCgYEAoc83EvBIElnKnyS8wIPlf4YSKXjpToEXbeoECdc6MiyGmOOqJLBs
vuN+KRYAb56dxaCPp2Kd2/y+mzfYZ57evilvUn0E4bL5PayaTvxFpM/jsfiGkTBw
5EsGuPzqI/DX8kjUilsU8V2n2RSoqG+3r8eb+PE5JZe5byBcYFFWeKM=
-----END RSA PRIVATE KEY-----
)KEY";

#endif // QWIC
