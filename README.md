# AhmsVille Dial 2 sensor adapter interfaces
This package contains the sensor adapter interfaces necessary for AhmsVille Dial 2 to work.

The intention of this library is to provide abstract sensor adapter interfaces to decouple sensor-related operations
from the application firmware in order to be able to test the firmware properly.

This library **is <u>not</u> allowed** to include **any** `Arduino` dependencies.